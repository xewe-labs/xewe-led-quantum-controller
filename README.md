# Quantum LED Controller — Arduino Nano firmware for four PC lighting channels

Personal project · Dec 2020 – Apr 2021 · Solo · Status: Completed

![Finished PC with case and fan LEDs lit](static/media/resources/IMG_7276.webp)

## Overview

QuantumController MC is the Arduino Nano firmware behind a custom-lit desktop PC. The Nano drives four addressable LED
strips — one around the case (77 LEDs) and one in each of three front fans (16 LEDs each) — and takes commands over the
PC's serial (UART) link from a companion Windows app,
[xewe-led-quantum-controller-app](https://github.com/xewe-labs/xewe-led-quantum-controller-app), where the user picks a
mode, colours and speed and applies them to the case, a single fan, all fans or everything. Each channel runs its own
effect (single colour, pulse, fade, Perlin-noise "smart fade", rainbow), cross-fades through black when the mode changes,
and remembers its last mode and parameters in EEPROM across power cycles.

## Highlights

- 4 independent channels, 125 LEDs in total: case strip 77 LEDs on pin 12; fan rings 16 LEDs each on pins 10, 9, 11 (`QuantumController.h`)
- 5 effects exposed by the app — Single colour, Pulse, Fade, Smart fade (Perlin noise via FastLED `inoise8`), Rainbow (`Mode_*.h`, `SerialController.h`)
- Compact ASCII protocol at 4800 baud: `$<mode><channel>:<hex>:<hex>…;`, frames ≤ 40 chars, 100 ms read timeout; channel 8 = all fans, 9 = everything (`SerialController.h`)
- 600 ms mode transition: brightness ramps 255 → 20, the mode swaps at the 300 ms midpoint, then ramps back to 255 (`Mode_GradualChange.h`)
- Per-channel state persisted in EEPROM (17 bytes per strip: mode byte + four 32-bit parameters) and restored at boot (`DataController.h`)

## How it works

```
Windows app (C#) ──serial 4800 baud──▶ SerialController ──▶ StripController ×4 ──▶ mode function ──▶ Adafruit_NeoPixel.show()
                                         │ parse $…; frame        │ params + mode          (S / F / P / R)
                                         └─ 'm' free RAM, 'r' reset └─ EEPROM write / read at boot
```

Every 5 ms the main loop (`QuantumController-MC.ino`) calls `QuantumController::tick()`: the serial controller checks for
a `$`, reads the frame up to `;`, decodes the mode letter, channel digit and up to four hex arguments, converts them where
needed (pulse and fade speed 1–10 → 10,000–1,000 ms cycle; rainbow step × 100; Perlin hue range folded to the shorter arc
of the 16-bit hue wheel) and hands them to the target strip(s). Each strip then renders one frame of its current mode.

- **`SETUP.h`** — includes, constants (`STRIP_NUM 4`, `SYSTEM_MAX_BRIGHT 255`, `GC_TIME 600`), Arduino `setup()`
- **`QuantumController.h`** — creates the serial controller and the four strips; per-tick dispatch by mode letter
- **`SerialController.h`** — frame reader, argument parser, mode-specific parameter conversion, service commands `m` (free SRAM) and `r` (soft reset)
- **`StripController.h`** — one NeoPixel strip (`NEO_GRB + NEO_KHZ800`), its parameters, mode flags and small per-mode state pools
- **`DataController.h`, `AXILLARY.h`** — EEPROM layout and 32-bit read/write, hex parsing, colour-channel extraction
- **`Mode_SingleColor.h`, `Mode_Fade.h`, `Mode_FadeSmart.h` (Perlin), `Mode_Rainbow.h`, `Mode_GradualChange.h`** — the effects and the mode-change cross-fade
- **`Modes.h`, `ModeFunctions.h`** — earlier class-based versions of the modes, kept commented out

| Mode letter | App name | Arguments sent | Behaviour |
|---|---|---|---|
| `S` | Single colour (Один цвет) | colour | whole strip one colour |
| `U` | Pulse (Пульсирование) | colour, speed 1–10 | fade between colour and black, 10,000–1,000 ms cycle |
| `F` | Fade (Переливание) | colour 1, colour 2, cycle | back-and-forth linear RGB fade |
| `P` | Smart fade (Умное переливание) | hue 1, hue 2, step, min saturation | Perlin-noise flame within a hue range |
| `R` | Rainbow (Радуга) | speed 1–10 | moving gamma-corrected rainbow, step = speed × 100 |

Known mismatch: the uploaded app sends the Fade cycle as `speed × 1000`, while this firmware maps a 1–10 speed to a
10,000–1,000 ms cycle, so the two uploaded versions disagree for Fade (see the TODO at the end of the `.ino`).

## Results

| Metric | Value | Source |
|---|---|---|
| LED channels | 4 (case + 3 fans) | `SETUP.h`, `QuantumController.h` |
| LEDs driven | 125 (77 + 3 × 16) | `QuantumController.h` |
| Serial link | 4800 baud, frames ≤ 40 chars, 100 ms timeout | `SerialController.h` |
| Mode transition | 600 ms (300 ms out, 300 ms in) | `SETUP.h`, `Mode_GradualChange.h` |
| Persistent state | 17 bytes EEPROM per channel | `DataController.h` |

These are design figures from the code rather than benchmarks; photos and videos of the finished build are in `static/media/`.

## Getting started

```text
1. Arduino IDE → install libraries: Adafruit NeoPixel, FastLED, MemoryFree (EEPROM comes with the Arduino core)
2. Open QuantumController-MC.ino, board "Arduino Nano", select the port, Upload
3. Wire strips: case → D12, fan 1 → D10, fan 2 → D9, fan 3 → D11 (change counts/pins in QuantumController.h)
4. Control it from the Windows app, or from any serial terminal at 4800 baud, e.g.  $S9:0xff0000;  (all channels red)
```

Requirements: Arduino Nano; addressable strips compatible with Adafruit NeoPixel in GRB, 800 kHz mode. The Windows app
expects the Nano on `COM3`. On each connection the app sends `$r;`, which soft-resets the board.

![QuantumController](https://github.com/xeweva/QuantumController-MC/assets/54597813/7ca7dd3c-97ec-4f6b-b74e-d84fd2c26b09)

## Documents

- Windows app: [xewe-led-quantum-controller-app](https://github.com/xewe-labs/xewe-led-quantum-controller-app)
- Project page: [maxdokukin.com/projects/xewe-led-quantum-controller](https://maxdokukin.com/projects/xewe-led-quantum-controller)
- Photos and videos: [`static/media/`](static/media/)
- Related: the later ESP32 lighting platform, XeWe LED OS — [project page](https://maxdokukin.com/projects/xewe-led-os) · [GitHub](https://github.com/xewe-labs/xewe-led-os)
