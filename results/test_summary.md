# Test Summary

## Purpose

This file summarizes validation work completed for the single-phase MOSFET H-bridge inverter prototype. The goal is to separate measured or observed results from design targets and future characterization work.

## Verified / Observed Results

| Test Item | Status | Evidence / Notes |
|---|---|---|
| Arduino SPWM generation | Verified | Switching frequency measured at 16.97 kHz |
| Dead time | Implemented | 300 ns software dead time inserted in Arduino firmware; physical gate timing pending confirmation through gate-source waveform capture |
| IR2110 low-side switching | Verified | Confirmed through staged LED-load testing |
| IR2110 high-side switching | Verified after troubleshooting | Bootstrap charging and grounding issues were resolved during testing |
| Full H-bridge switching | Verified | H-bridge switching behavior validated through staged LED-load and bench testing before final filtered-output testing |
| DC bus operation | Verified | Prototype tested from a 12 V DC bus |
| LCL filtered output | Observed | Smoother sinusoidal-like waveform observed under resistive load testing |

## Issues Encountered

- Bootstrap capacitor charging issues affected high-side gate-drive operation.
- Grounding and COM/VSS reference issues affected switching behavior during debugging.
- PWM pin assignment errors and IR2110 shutdown/enable pin behavior required correction before stable gate-drive switching was achieved.
- Final LCL component values and resonant-frequency calculation require re-verification against the hardware setup.

## Not Formally Measured

| Item | Status |
|---|---|
| THD | Not formally measured |
| Final output frequency accuracy | Not fully characterized |
| Output power rating | Not fully characterized |
| Grid synchronization | Not implemented |
| Grid protection | Not implemented |
| Closed-loop voltage regulation | Not implemented |

## Next Validation Steps

1. Capture representative gate-source voltage waveforms for high-side and low-side MOSFET switching.
2. Measure switching-node waveform before the LCL filter.
3. Characterize filtered output frequency and RMS voltage under resistive load.
4. Measure THD using oscilloscope FFT or exported waveform data.
5. Reconfirm final LCL component values and update the resonant-frequency calculation.
