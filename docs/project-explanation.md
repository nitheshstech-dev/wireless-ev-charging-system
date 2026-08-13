# How I Explain This Project in an Interview

## Why I selected this project

I selected wireless EV charging as an ECE mini project because it combines electronics fundamentals with a practical emerging application. I wanted to understand how electrical energy could be transferred without a direct charging connector.

## What I worked on

My project work focused on the low-voltage prototype architecture: generating an alternating excitation signal, driving the transmitter coil, coupling energy into the receiver coil, rectifying the received AC, filtering it and regulating the DC output for a safe demonstration load.

I also studied how coil alignment and separation affect power transfer and how voltage/current measurements can be used to evaluate the prototype.

## How it works

A DC source feeds a switching/oscillator stage. The switching stage produces high-frequency excitation for the transmitter coil. The TX coil produces an alternating magnetic field. When the RX coil is positioned within the coupled field, an AC voltage is induced at the receiver.

The receiver output is passed through a fast rectifier and filter. A regulator/CC-CV stage provides controlled DC output for the prototype load.

## Why resonance matters

The TX and RX networks can be tuned around a resonant frequency. For an LC network:

`f0 = 1 / (2π√LC)`

The actual resonant capacitor depends on measured coil inductance and the selected operating frequency. Resonance can improve energy transfer in a loosely coupled system.

## Main engineering challenge

The most important practical issue is coupling. If the receiver coil moves away from the transmitter or becomes misaligned, coupled energy decreases. This affects receiver voltage, current and efficiency.

Other practical issues include switching losses, coil resistance, rectifier losses and temperature rise.

## What I would measure

For each coil position and load, I would record input voltage/current, receiver voltage/current, coil gap, alignment offset and component temperature.

Then calculate:

`Pin = Vin × Iin`

`Pout = Vout × Iout`

`Efficiency = (Pout / Pin) × 100`

## What I learned

This project helped me connect theoretical ECE concepts with a physical energy-transfer system. I gained practical understanding of electromagnetic induction, resonant circuits, MOSFET switching, rectification, filtering, voltage regulation, measurement and troubleshooting.

## What I would improve

For an advanced version, I would add closed-loop resonance control, coil alignment detection, temperature monitoring, foreign-object detection, communication between vehicle and charging pad, improved power-stage design and stronger electrical/EMI safety mechanisms.

## Project boundary

This GitHub repository documents a low-voltage educational prototype architecture. It should not be described as a production EV charger. Performance numbers should come from actual hardware or simulator measurements.
