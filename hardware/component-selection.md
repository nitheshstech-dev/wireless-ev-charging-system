# Component Selection Guide

The following choices are suitable for a **low-voltage educational prototype**. They are reference selections, not a record of the exact parts used in the original college build.

| Block | Example component/type | Why it is used |
|---|---|---|
| DC source | 12 V current-limited bench supply | Safe prototype input |
| Switch | Logic-level N-channel MOSFET | High-frequency switching |
| Gate driver | IR2110-class driver | Drives MOSFET gates with better timing/drive strength |
| TX coil | Enamelled copper spiral | Creates alternating magnetic field |
| RX coil | Enamelled copper spiral | Receives magnetic energy |
| Resonant capacitor | Polypropylene film | Low-loss resonant element |
| Rectifier | Fast/Schottky bridge | Converts receiver AC to DC |
| Filter | Electrolytic + film bypass | Smooths rectified DC |
| Regulator | CC/CV buck module | Limits current and regulates charging voltage |
| Protection | Fuse + current limit | Fault protection |
| MCU | Arduino/ESP32 (optional) | Telemetry/monitoring |
| Temperature sensor | NTC/DS18B20 (optional) | Thermal monitoring |

## Selection rules

1. Measure the actual TX/RX coil inductance before choosing resonance capacitors.
2. Select MOSFET voltage/current ratings with adequate margin over measured operating conditions.
3. Use a switching frequency compatible with the chosen driver, MOSFETs and coil/capacitor losses.
4. Select the rectifier for both voltage and current, accounting for switching transients.
5. Use a proper CC/CV charging stage for any rechargeable battery.
6. Never connect an unprotected prototype directly to a lithium battery pack.
