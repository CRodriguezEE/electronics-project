# \# Single Phase Inverter with LCL Filter 



As the project lead for a four-person team, I led the design and build of a grid-tied single-phase DC-AC inverter with and LCL output filter as part of ECE 3155 at the University of Houston. The inverter converts a DC bus voltage to a clean 60 Hz sinusoidal output synchronize with the utility grid using a MOSFET H-bridge driven by unipolar sinusoidal pulse width modulation at a 20 kHz switching frequency. Dead time of 300 ns is inserted between complementary gate signals to prevent shoot-through across the DC bus. The LCL filter - consisting of a 1.8 mH invert-side inductor, 2.2 µF film capacitor, and 0.6 mH grid-side inductor — attenuates switching harmonics before the output, with a resonant frequency of approximately 3.1 kHz sitting cleanly between the 60 Hz fundamental and the 20 kHz switching frequency. The design targets a total harmonic distortion below 5% at rated power.



\## Specifications 



| Parameter | Value |

|---|---|

| Output Frequency | 60 Hz |

| Switching Frequency | 20 kHz |

| Modulation | Unipolar SPWM |

| Dead Time | 300 ns |

| Inverter-Side Inductor (L1) | 1.8 mH |

| Filter Capacitor (C) | 2.2 uF film, 250VAC rated |

| Grid-Side Inductor (L2) | 0.6 mH |

| LCL Resonant Frequency | \~3.1 kHz |

| Damping Resistor | 3-5 ohms series with C |

| Gate Drive Voltage | 12-15 V |

| Gate Resistor | 10-22 ohms per MOSFET |

| MOSFET Vds Rating | 2x DC bus voltage minimum |

| MOSFET Ron | < 50 mohms |

| Grid Load Resistance | 50-100 ohms |

| Target THD | < 5% at rated power |

| DC Bus Capacitance | 1000-2200 uF |

