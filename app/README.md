# Quantum Controller App — Windows app for the Quantum LED Controller

Personal project · Dec 2020 – Apr 2021 · Solo · Status: Completed

<img width="600" alt="Screenshot 2023-11-18 at 20 39 31" src="https://github.com/xeweva/QuantumController-App/assets/54597813/4c167116-526e-4a87-b93f-8adb0e0b6ca1">

## Overview

Quantum Controller is a small C# Windows Forms app that controls the addressable LEDs of a custom-lit desktop PC. The user
picks a mode, one or two colours and a speed, then applies them to the case strip, one of the three front fans, all fans,
or everything. The app turns that choice into a short ASCII command and writes it over a serial (UART) port to an Arduino Nano
running the [QuantumController MC firmware](https://github.com/xewe-labs/xewe-led-quantum-controller), which drives four
LED channels. The interface is a frameless 400 × 400 window in Russian with a custom background skin.

## Highlights

- 5 lighting modes in one dropdown: Single colour, Pulse, Fade, Smart fade (Perlin noise), Rainbow (`Form1.Designer.cs`, `Form1.cs`)
- 6 apply-to targets: All, Case, Coolers (all fans), Fan 1, 2, 3 → firmware channels 9, 0, 8, 1, 2, 3 (`Form1.cs`)
- Serial link at 4800 baud on `COM3`, a clickable connection indicator (green = open, red = closed) and a `$r;` reset on every connect (`Form1.cs`, `Form1.Designer.cs`)
- Colours sent as `0x`-prefixed 24-bit hex; Smart-fade hues converted from degrees to the 16-bit NeoPixel hue wheel (× 65,535 / 360)
- .NET Framework 4.7.2 WinForms project with a ClickOnce publish profile and signed manifests (`Quantum Controller.csproj`)

## How it works

```
mode + colours + speed + target button → sendCommand(channel) → "$<mode><channel>:<hex>:…;" → SerialPort (COM3, 4800) → Arduino Nano
```

- **`Form1.cs`** — event handlers: colour pickers, the six target buttons, `openPort()` (open, send `$r;`, colour the indicator), `sendCommand()` (build the frame per mode), `generateHex()`, window dragging, close
- **`Form1.Designer.cs`** — the 400 × 400 borderless layout: mode dropdown (Режим), Colour 1 / Colour 2 swatches (Цвет 1/2), speed 1–10 (Скорость), "Apply to" (Применить на) buttons Все / Корпус / Кулеры / 1 / 2 / 3, the `SerialPort` component
- **`Program.cs`** — WinForms entry point
- **`basic.png`, `basicV2.png`, `allPressed.png`, `Coolers pressed.png`** — 400 × 400 background skins for the window, including pressed-state variants

| Mode (UI) | Frame | Arguments |
|---|---|---|
| Один цвет — Single colour | `$S<ch>:c1;` | colour 1 |
| Пульсирование — Pulse | `$U<ch>:c1:speed;` | colour 1, speed 1–10 |
| Переливание — Fade | `$F<ch>:c1:c2:ms;` | colour 1, colour 2, speed × 1000 |
| Умное переливание — Smart fade | `$P<ch>:h1:h2:step:sat;` | hues × 182.04, speed × 10, saturation 0xB4 (180) |
| Радуга — Rainbow | `$R<ch>:speed;` | speed 1–10 |

## Getting started

```text
1. Open "Quantum Controller.sln" in Visual Studio 2019 or later (.NET Framework 4.7.2 targeting pack)
2. Flash the firmware from xewe-led-quantum-controller to an Arduino Nano and connect it; it must appear as COM3
   (or change quantum_port.PortName in Form1.Designer.cs)
3. Build and run (F5). The "o" in the top-right corner turns green when the port is open; click it to reconnect
```

Notes: the project file references an application icon `fedosXuinya1.ico` that is not in the repository (the repository
has `icon.ico`), so fix the `ApplicationIcon` path if the build complains. `bin/` and `obj/` hold the original build
output. The UI text is Russian.

![IMG_8411](https://github.com/xeweva/QuantumController-App/assets/54597813/178cc923-e73e-4d2a-8977-ae199ed30f81)

## Documents

- Firmware: [xewe-led-quantum-controller](https://github.com/xewe-labs/xewe-led-quantum-controller) (photos and videos of the build in its `static/media/`)
- Project page: [maxdokukin.com/projects/xewe-led-quantum-controller](https://maxdokukin.com/projects/xewe-led-quantum-controller)
- Related: the later ESP32 lighting platform, XeWe LED OS — [project page](https://maxdokukin.com/projects/xewe-led-os) · [GitHub](https://github.com/xewe-labs/xewe-led-os)
