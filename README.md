# Single-Phase MOSFET H-Bridge Inverter with LCL Filter

This project documents the design, construction, and validation of a course-approved independent single-phase inverter prototype built for ECE 3155 at the University of Houston. The system used an Arduino UNO to generate unipolar SPWM control signals for a MOSFET H-bridge driven by IR2110 gate drivers, followed by an LCL output filter and resistive AC load.

The inverter was tested from a 12 V DC bus, with switching behavior validated through staged LED-load testing, oscilloscope measurements, and final bench testing. The measured switching frequency was approximately 16.97 kHz, with 300 ns software dead time implemented between complementary gate signals.

This repository includes schematics, calculations, hardware photos, measurement evidence, and troubleshooting notes. THD was not formally measured, while grid synchronization and closed-loop voltage regulation were not implemented in this version and are listed as future work.

## System Overview

The system converts a DC input into a high-frequency PWM waveform through a MOSFET H-bridge. That waveform is then passed through an LCL filter made up of an inverter-side inductor, capacitor branch, and grid-side inductor. The filter was used to reduce high-frequency switching content and produce a smoother sinusoidal-like output waveform under resistive load testing.

## Repository Contents
- `schematics/` – inverter and LCL filter schematics
- `calculations/` – LCL design math and resonant frequency calculations
- `measurements/` – scope captures and waveform verification
- `images/` – block diagram and hardware photos
- `docs/` – report and supporting notes
- `results/` – concise verification summary

### Main Blocks
- DC supply 
- MOSFET H-bridge inverter
- Unipolar SPWM control
- Gate driver with dead time
- LCL output filter
- Resistive test load / output stage

## Key Specifications

| Parameter | Value / Status |
|---|---|
| DC Bus Voltage | 12–15 V design range; validated at 12 V |
| Switching Frequency | ~16.97 kHz measured; 20 kHz design target |
| Modulation | Unipolar SPWM |
| Dead Time | 300 ns software dead time |
| Gate Driver | 2× IR2110 |
| MOSFETs | 4× IRLZ44N |
| Gate Drive Supply | 12 V during validation |
| Logic Controller | Arduino UNO |
| LCL Filter | 2.2 mH / 0.1 µF / 2.2 mH |
| Load Type | Resistive load |
| THD | Design target only; not formally measured |
| Grid Synchronization | Not implemented |
| Closed-Loop Control | Not implemented |

## Design Decisions

### Why a 20 kHz Switching Target?
A 20 kHz switching frequency was used as the initial design target since it provides strong separation from the low-frequency output waveform and helps move switching noise near the upper edge of the audible range. During final validation, the Arduino UNO generated a measured switching frequency of approximately 16.97 kHz, which was used as the verified experimental result.

### Why 300 ns Dead Time?
A dead time of 300 ns was selected to prevent shoot-through, where both MOSFETs in the same inverter leg conduct at the same time and create a short across the DC bus. Since the MOSFET turn-off delay is specified as less than 150 ns, 300 ns provides a reasonable safety margin to allow one device to turn off before the complementary device turns on. Too little dead time increases the risk of shoot-through, while too much dead time can distort the output waveform.

### Why an LCL Filter Was Used?
The intent was to place the filter response above the low-frequency output component and below the high-frequency switching region so that the filter would reduce switching ripple while preserving the desired output waveform shape.

### LCL Filter Design

The output-filter stage was documented using the following final referenced values:

- L1 = 2.2 mH
- C = 0.1 µF
- L2 = 2.2 mH

Earlier design calculations used a different filter set of 1.8 mH / 2.2 µF / 0.6 mH and produced an estimated resonant frequency of approximately 5.06 kHz. Because the documentation contains both the earlier design values and the final referenced hardware values, the final resonant-frequency calculation is marked for follow-up verification.

For this version of the README, the LCL filter is reported as a tested output-filtering stage. Final resonant-frequency documentation will be updated after the hardware setup is rechecked.

## Validation Summary

### Verified
1. Arduino UNO generated unipolar SPWM switching signals at approximately 16.97 kHz.
2. 300 ns software dead time was implemented between complementary MOSFET gate signals.
3. IR2110 low-side and high-side switching behavior was validated through staged LED-load testing.
4. Full H-bridge switching behavior was validated before integration with the LCL filter and resistive load.
5. A smoother sinusoidal-like output waveform was observed after filtering under resistive load testing.

### Not Formally Measured
1. Total harmonic distortion, THD.
2. Final output frequency accuracy.
3. Output power rating.
4. Grid synchronization.
5. Closed-loop voltage regulation.

## My Contributions
- Guided inverter, gate-drive, and LCL filter design decisions
- Contributed to switching frequency, dead time, MOSFET, gate-driver, and passive component selection
- Verified PWM timing and switching behavior using oscilloscope measurements; implemented 300 ns dead time in Arduino firmware
- Supported staged validation from LED-load testing to full H-bridge and filtered-output testing
- Documented troubleshooting of grounding, bootstrap charging, SD pin, and PWM assignment issues

## Current Status and Future Work
- THD was treated as a design target but was not formally measured during final validation.
- Grid synchronization and grid protection were outside the scope of this prototype.
- Closed-loop voltage regulation was not implemented in this version.
- Output power rating and final output frequency accuracy require additional characterization.
- Future work includes gate-source waveform capture, switching-node measurements, PCB layout, and voltage-feedback control.
