# Oscillite

Oscillite is a lightweight, embedded-friendly C++ library for generating audio waveforms using an efficient phase-accumulator architecture. It provides a clean API for producing sine, square (with PWM), saw, and triangle waves using Q8.8 fixed-point output.

Designed for:

- Microcontrollers (Teensy, Arduino, STM32)
- Low-latency audio engines
- DSP experimentation
- Compact synthesizer applications

---

## Features

- Multi-waveform oscillator
    - Sine
    - Square with adjustable PWM
    - Sawtooth
    - Triangle

- Q8.8 fixed-point math library
    - Fast fixed-point arithmetic
    - Saturation-safe operations
    - Ideal for embedded audio and lookup-free DSP

- Phase-accumulator synthesis
    - Stable oscillator core
    - Frequency control via `phase_inc = f / sample_rate`
    - Continuous, wrap-around phase handling

- Clean, simple API
    - Construct oscillators with waveform configs
    - Change frequency and waveform at runtime
    - Zero heap allocation, deterministic behavior

---

## Getting Started

### Including Oscillite

```cpp
#include "oscillator.h"
#include "q8_8.h"
```

### Example: Generate a 440Hz sine wave at 48kHz
```cpp
#include "oscillator.h"
#include "q8_8.h"

using namespace Waveform;

int main() {
    oscillator osc(48000.0f, 440.0f, Waveform::sine());

    while (true) {
        q8_8 sample = osc.next_sample();
        float y = sample.toFloat();

        // send y to your audio output buffer or DAC...
    }
}
```

### Waveforms
#### Sine
```cpp
auto wf = Waveform::sine();
```

#### Square
```cpp
auto wf = Waveform::Square(0.3f); // 30% High
```

#### Saw
```cpp
auto wf = Waveform::Saw();
```

#### Triangle
```cpp
auto wf = Waveform::Triangle();
```

### Modifying the Oscillator
#### Changing Frequency
```cpp
osc.set_frequency(880.0f);
```

#### Changing Waveform
```cpp
osc.set_waveform(Waveform::sine());
osc.set_waveform(Waveform::square(0.7));
```

### Q8.8 Fixed-Point Usage
```cpp
q8_8 a = q8_8::q8_8_fromFloat(0.5f);
q8_8 b = q8_8_fromFloat(-0.25f);

q8_8 c = a + b;
float f = c.toFloat(); // 0.25

```

## Planned Extensions
1. ADSR Envelope generator
2. LFO Modulation
3. Biquad filters

