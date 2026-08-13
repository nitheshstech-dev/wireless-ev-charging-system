# System Architecture

```text
12 V DC Supply
      ↓
Oscillator / PWM Driver
      ↓
MOSFET Switching Stage
      ↓
TX Resonant Coil + Capacitor
      ))))))  Magnetic Coupling  ((((((
RX Resonant Coil + Capacitor
      ↓
Fast Bridge Rectifier
      ↓
Filter Capacitor
      ↓
CC/CV Regulator
      ↓
Battery / DC Load

Optional:
MCU → voltage/current/temperature monitoring
```

## Core electronics

The transmitter converts DC to a high-frequency alternating excitation for the TX resonant network. The receiver coil captures the coupled magnetic energy. The receiver AC is rectified and filtered before being passed to a regulated charging/load stage.

## Key design variables

- Coil inductance and number of turns
- Operating frequency
- Resonant capacitance
- Coupling coefficient
- TX/RX separation
- Coil alignment
- Load resistance/current
- Switching losses and temperature

## Interview-ready explanation

The important idea is that resonance is used to improve energy transfer between loosely coupled coils. The quality of the coupling and the tuning of the transmitter/receiver networks strongly affect received power and efficiency.
