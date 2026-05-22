# LCL Filter Design Calculations

This file documents the LCL output filter calculation for the single-phase MOSFET H-bridge inverter project.

## Nominal Filter Values

The LCL output filter was referenced using the following nominal component values:

- L1 = 2.2 mH
- C = 0.1 µF
- L2 = 2.2 mH

## Resonant Frequency Calculation

The LCL resonant frequency was calculated using:

```text
f_res = (1 / 2π) × sqrt((L1 + L2) / (L1 × L2 × C))
```

Substituting the nominal values:

```text
L1 = 2.2e-3 H
L2 = 2.2e-3 H
C  = 0.1e-6 F
```

```text
f_res = (1 / 2π) × sqrt((2.2e-3 + 2.2e-3) / ((2.2e-3)(2.2e-3)(0.1e-6)))
```

```text
f_res ≈ 15.17 kHz
```

## Relationship to Switching Frequency

The measured inverter switching frequency was:

```text
f_sw = 16.97 kHz
```

The calculated LCL resonant frequency falls below the measured switching frequency. This value is reported as a calculated design estimate based on nominal component values, not a measured filter response. Filtered-output performance is documented based on observed waveform behavior under resistive load testing.

```text
f_res ≈ 15.17 kHz
f_sw  = 16.97 kHz
```

## Notes

- Resonant frequency was calculated from nominal component values, not experimentally measured.
- Component tolerances, parasitic resistance, wiring effects, load behavior, and capacitor ESR may shift the actual filter response.
- The LCL filter was observed to smooth the switched output under resistive load testing.
- Future validation should include additional waveform measurements, RMS voltage characterization, and FFT-based harmonic analysis.
