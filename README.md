Embedded Systems Assignment – ThinkClock

This repository contains my solutions for the ThinkClock Embedded Systems assignment.
It covers programming on Raspberry Pi Pico, waveform level shifting, and battery pack topologies.
__________________________________________________________________________________________________
Q1 – Raspberry Pi Pico LED Blink

Goal: Blink the on-board LED on the Raspberry Pi Pico with a pattern:

10 blinks in the first minute

20 blinks in the second minute

30 blinks in the third minute

A pushbutton toggles the sequence order (reverse: 30 → 20 → 10).

Implementation:

Developed in Wokwi Raspberry Pi Pico C simulator.

GPIO 25 used for the LED, GPIO 14 used for the button (with internal pull-up).

Written in C using Pico SDK.

Result:
The LED blinks according to the programmed sequence, and pressing the button reverses the blink order.
Link: https://wokwi.com/projects/442446928074129409
________________________________________________________________________________________________________
Q2 – PWM Waveform Level Shifting

Part 1: Shift 0–3.3 V PWM to –1.65 V … +1.65 V

Designed circuit in LTSpice.

Implemented level shift using difference amplifier / behavioral subtractor.

Verified that the PWM waveform is centered around 0 V.

Part 2: Shift –1.65 V … +1.65 V back to 0–3.3 V

Implemented non-inverting summing amplifier.

Added 1.65 V DC offset to recenter the waveform.

Verified output returns to 0–3.3 V swing.
_________________________________________________________________________________________________
Q3 – Battery Pack Topologies

Topology 1: Series Connection

Increases voltage.

Capacity remains the same as one cell.

Suitable for high-voltage applications.

Requires balancing circuits to prevent cell mismatch.

Topology 2: Parallel Connection

Increases capacity.

Voltage remains the same as a single cell.

Provides higher run time and fault tolerance.

Needs fuse protection for safety.
