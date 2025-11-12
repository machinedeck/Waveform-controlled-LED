# Waveform-controlled LED
_Last Updated: November 12, 2025_

This is just an Arduino/C++ practice to generate waveforms, which are later on applied to modulate LED intensity.

_To be updated..._

## Contents
### `waveforms.ino`
This contains the code for generating the waveform (square, sawtooth, sine) by entering the period in ms. The resulting waveform and period are visualized and entered, respectively, on the Serial monitor.

**TAKE NOTE:** For the sine wave, I tried to generate sine function using Taylor series representation. Hence, my method is **inaccurate** in modelling the sine wave.

### `led_waveform.ino`
This is where I have incorporated the LED circuit to modulate its intensity based on the selected waveform: The serial entry receives something like "A 50", where
- A : Square wave
- B : Sawtooth wave
- C : Sine wave
- and the following number is the period of the wave in ms.
