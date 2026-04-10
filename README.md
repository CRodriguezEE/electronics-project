# Single-Phase DC-AC Inverter with LCL Filter

The project focuses on the design and implementation of a single-phase DC-AC inverter with an LCL output filter using a MOSFET H-bridge and unipolar sinusoidal pulse width modulation (SPWM). It was completed as part of Electronics Technical Project for the course ECE3155 at the University of Houston. The main objective of the design was to convert a DC input into a clean 60 Hz AC output while filtering high-frequency harmonics at the inverter output.

The inverter was designed for a switching frequency of 20 kHz and uses 300 ns dead time inserted between complementary MOSFET gate signals to protect against shoot-through. An LCL filter was added to the output stage to reduce switching harmonics while preserving the 60 Hz fundamental component. The performance target was a cleaner (low-harmonic) sinusoidal output, with total harmonic distortion (THD) goal of less than 5% at rated power.

As project lead for a four-person team, I contributed to the inverter filter design process, coordinated integration of the power stage and filter stage, and participated in verification of PWM timing, dead time behavior, and filtered output performance.

## System Overview

The system converts a DC input into a high-frequency PWM waveform through a MOSFET H-bridge. That waveform is then passed through an LCL filter made up of an inverter-side inductor, capacitor branch, and grid-side inductor. The filter reduces high-frequency switching content while allowing the 60 Hz output component to remain.

## Repository Contents


### Main Blocks
- DC bus input
- MOSFET H-bridge inverter
- Unipolar SPWM control
- Gate driver with dead time
- LCL output filter
- Resistive test load / output stage

## Key Specifications

| Parameter | Value |
|---|---|
| Output Frequency | 60 Hz |
| Switching Frequency | 20 kHz |
| Modulation | Unipolar SPWM |
| Dead Time | 300 ns |
| Inverter-Side Inductor (L1) | 1.8 mH |
| Filter Capacitor (C) | 2.2 µF film, 250 VAC rated |
| Grid-Side Inductor (L2) | 0.6 mH |
| LCL Resonant Frequency | ~5.06 kHz |
| Damping Resistor | 3–5 Ω in series with capacitor branch |
| Gate Drive Voltage | 12–15 V |
| Gate Resistor | 10–22 Ω per MOSFET |
| MOSFET Vds Rating | at least 2× DC bus voltage |
| MOSFET Rds(on) | < 50 mΩ |
| MOSFET Turn-Off Delay | < 150 ns |
| Test Load Resistance | 50–100 Ω |
| DC Bus Capacitance | 1000–2200 µF |
| Target THD | < 5% at rated power |

## Design Decisions

### Why 20 kHz Switching Frequency?
A switching frequency of 20 kHz was selected because it provides strong frequency separation between 60 Hz fundamental and the high frequency switching harmonics, improving harmonic attenuation. It also places the switching action near the upper edge of the audible range, which helps reduce audible noise from magnetic components. In addition, standard silicon MOSFETs can typically operate at this frequency with manageable switching losses.

### Why 300 ns Dead Time?
A dead time of 300 ns was selected to prevent shoot-through, where both MOSFETs in the same inverter leg conduct at the same time and create a short across the DC bus. Since the MOSFET turn-off delay is specified as less than 150 ns, 300 ns provides a reasonable safety margin to allow one device to turn off before the complementary device turns on. Too little dead time increases the risk of shoot-through, while too much dead time can distort the output waveform.

### Why an LCL Filter Was Used?
An LCL filter was used since it provides stronger attenuation of switching harmonics than a simple LC filter while keeping the inductors at practical values. The intent was to place the resonant frequency above the 60 Hz output frequency and below the 20 kHz switching frequency so that the filter would reduce high-frequency ripple while preserving the fundamental output component.

### LCL Filter Design
The selected filter values were:

- L1 = 1.8 mH
- C = 2.2 µF 
- L2 = 0.6 mH

The capacitor value was set to 2.2 µF, and total inductance was divided between the inverter-side and grid-side inductors. 

The resonant frequency was calculated using:

f_res = (1 / (2π)) * sqrt((L1 + L2) / (L1 * L2 * C))

Substituting the selected values:

f_res = (1 / (2π)) * sqrt((1.8e-3 + 0.6e-3) / ((1.8e-3) * (0.6e-3) * (2.2e-6)))
      ≈ 5.06 kHz

A 3–5 Ω damping resistor was connected in series with the capacitor branch to damp resonance peaking and improve filter behavior.

## Verification Goals

The project was developed around the following verification steps:

1. Verify PWM switching waveforms and proper complementary gate operation.
2. Confirm 300 ns dead time is inserted correctly and that shoot-through is avoided.
3. Integrate the LCL filter and observe harmonic attenuation at the output.
4. Confirm the filtered output approximates a 60 Hz sinusoidal waveform.
5. Compare measured waveform quality against the target THD specification.

## Repository Contents
- `schematics/` – inverter and LCL filter schematics
- `calculations/` – LCL design math and resonant frequency calculations
- `measurements/` – scope captures and waveform verification
- `images/` – block diagram and hardware photos
- `docs/` – report and supporting notes
- `results/` – concise verification summary

## My Contributions
As project lead, I was responsible for:
- guiding inverter and LCL filter design decisions
- selecting switching and passive component values
- verification of PWM timing and dead time behavior
- coordinating system integration across a four-person team
- documenting specifications, design choices, and test milestones

## Notes

- This project was built for single-phase inverter design and harmonic filtering study.
- Any claim of full grid synchronization should only be included if synchronization was explicitly implemented and verified.
- THD should be reported as a target unless final measured data is available.
