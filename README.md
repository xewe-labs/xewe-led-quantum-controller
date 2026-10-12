> Archived. Part of the XeWe LED family; see https://github.com/xewe-labs/xewe-led-os.

# Quantum LED Controller — firmware and Windows app for four PC lighting channels

Personal project · Dec 2020 – Apr 2021 · Solo · Status: Completed (archived)

LED lighting for a PC build: an Arduino Nano drives four lighting channels, and a small Windows
app sets their modes and colours over USB serial.

| Folder | What it is | Previously |
|---|---|---|
| [`firmware/`](firmware/) | Arduino Nano firmware (QuantumController-MC) | `xewe-labs/xewe-led-quantum-controller` |
| [`app/`](app/) | Windows app (C#, .NET Framework 4.7.2) | `xewe-labs/xewe-led-quantum-controller-app` (archived; now a pointer here) |

Both histories are kept: the firmware commits are this repository's own history (moved into
`firmware/`), and the app commits came in with `git subtree add`.

Build steps, protocol and media: [firmware/README.md](firmware/README.md) and
[app/README.md](app/README.md).
