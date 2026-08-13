# Wireless EV Charging System — ECE Mini Project

> A low-voltage wireless EV charging prototype based on resonant inductive power transfer, with rectification, regulation and optional embedded monitoring.

## Overview

This Electronics & Communication Engineering mini project demonstrates contactless power transfer using a transmitter coil and a receiver coil.

### Working principle

```text
DC Supply
   ↓
Oscillator / MOSFET Driver
   ↓
TX Resonant Coil
   ))))  Magnetic Coupling  ((((
RX Resonant Coil
   ↓
Fast Rectifier
   ↓
Filter
   ↓
CC/CV Regulator
   ↓
Battery / DC Load
```

The prototype is intentionally low-voltage and educational. It is **not** a production EV charger and should not be connected to an EV traction battery or mains power.

## Objectives

- Demonstrate wireless energy transfer.
- Study electromagnetic induction and resonant coupling.
- Design transmitter and receiver coils.
- Convert received AC to DC.
- Regulate the output for a small battery or load.
- Study the effect of coil spacing and alignment.
- Monitor voltage/current using an optional microcontroller.

## Components

### Transmitter

- 12 V current-limited DC supply
- PWM/oscillator stage
- Logic-level N-channel MOSFETs
- Gate-driver IC such as IR2110 or equivalent
- Enamelled copper TX coil
- Polypropylene resonant capacitor
- Fuse and protection components
- Heat sink as required

### Receiver

- Enamelled copper RX coil
- Fast/Schottky bridge rectifier
- Filter capacitor
- DC-DC buck or CC/CV charging module
- Small protected rechargeable battery or resistive/electronic load
- Voltage/current measurement

## Resonance

For an LC resonant network:

```text
f₀ = 1 / (2π√LC)
```

The resonant capacitor should be selected after measuring the actual coil inductance and choosing a safe operating frequency.

## Circuit Architecture

```text
                 TRANSMITTER
        ┌───────────────────────────┐
        │ 12 V DC Supply            │
        └─────────────┬─────────────┘
                      ↓
        ┌───────────────────────────┐
        │ PWM / Oscillator Driver   │
        └─────────────┬─────────────┘
                      ↓
        ┌───────────────────────────┐
        │ MOSFET Switching Stage    │
        └─────────────┬─────────────┘
                      ↓
        ┌───────────────────────────┐
        │ TX Coil + Resonant C      │
        └─────────────┬─────────────┘
                      │
               Magnetic Coupling
                      │
                      ↓
        ┌───────────────────────────┐
        │ RX Coil + Resonant C      │
        └─────────────┬─────────────┘
                      ↓ AC
        ┌───────────────────────────┐
        │ Fast Bridge Rectifier     │
        └─────────────┬─────────────┘
                      ↓ DC
        ┌───────────────────────────┐
        │ Filter + CC/CV Regulator  │
        └─────────────┬─────────────┘
                      ↓
                 Battery / Load
```

A redraw is included at `images/wireless-ev-charging-block-diagram.svg`.

## Optional MCU Monitoring

An Arduino/ESP32 can measure receiver voltage and current, monitor temperature and expose status over Serial. The MCU should be used as a measurement/control layer and not connected directly to a high-power switching node.

See `firmware/monitor.ino` for a low-voltage ADC monitoring example.

## Efficiency Calculation

```text
Pin  = Vin × Iin
Pout = Vout × Iout

Efficiency = (Pout / Pin) × 100
```

## Test Plan

### Coil alignment

Move the RX coil laterally while keeping the gap approximately constant. Record Vout, Iout and Pout.

### Coil separation

Increase the TX/RX gap and observe the change in received power.

### Load variation

Test several safe loads and compare input/output power.

### Thermal check

Monitor MOSFET, coil and rectifier temperatures during operation.

## Results Template

Use actual measurements from the physical prototype. Do not substitute fabricated values.

| Coil gap | Alignment | Vout | Iout | Pout | Efficiency |
|---:|---|---:|---:|---:|---:|
| 5 mm | Centered | — | — | — | — |
| 10 mm | Centered | — | — | — | — |
| 15 mm | Centered | — | — | — | — |
| 10 mm | Offset | — | — | — | — |

## Advantages

- Contactless charging concept
- Reduced connector wear
- Convenient energy transfer
- Strong ECE combination of power electronics, electromagnetics and embedded monitoring

## Limitations

- Efficiency depends strongly on coil alignment and distance.
- Coil and switching-stage heating can limit operation.
- Prototype power capability is far below a real EV charger.
- EMI/EMC and safety need much more engineering for a commercial system.

## Real EV System Considerations

A production wireless EV charging system additionally needs high-power converters, precise resonance/control, foreign-object detection, thermal protection, communication, isolation, alignment assistance, EMI/EMC compliance and certified charging/battery protection.

## Interview Explanation

**30-second answer:**

> My ECE mini project was a low-voltage wireless EV charging prototype based on resonant inductive power transfer. A switching circuit drives a transmitter coil to create an alternating magnetic field. A nearby receiver coil captures the coupled energy, which is then rectified and regulated to obtain DC power for a small battery or load. The main engineering variables were resonance, coil alignment, distance, power loss and thermal behaviour.

**What I learned:**

> I learned how electromagnetic coupling, resonant circuits, MOSFET switching, rectification and voltage regulation work together in a practical power-transfer system.

## Project Scope Note

This repository is a portfolio-oriented prototype/reference implementation. Component values and performance numbers must be validated against the actual hardware before being presented as experimental measurements.

## Author

**Nithesh S** — B.E. Electronics & Communication Engineering

GitHub: `nitheshstech-dev`

## License

MIT
