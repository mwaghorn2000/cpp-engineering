//
// Created by Mitch on 29/11/2025.
//

#include "../include/oscillator.h"
#include <cmath>

using namespace dsp;

void oscillator::set_frequency(float freq) {
    phase_inc_ = freq / sample_rate_;
}

void oscillator::set_waveform(Waveform wf) {
    waveform_ = wf;
}

q8_8 oscillator::next_sample() {
    phase_ += phase_inc_;
    if (phase_ >= 1.0f) phase_ -= 1.0f;

    float y = 0.0f;

    switch (waveform_.kind) {
        case Waveform::Kind::Sine:
            y = sinf(phase_ * TWO_PI);
            break;
        case Waveform::Kind::Square:
            y = phase_ < waveform_.pwm ? 1.0f : -1.0f;
            break;
        case Waveform::Kind::Triangle:
            y = 2.0f * fabsf(2.0f * phase_ - 1.0f) - 1.0f;
            break;
        case Waveform::Kind::Saw:
            y = (2.0 * phase_) - 1.0f;
            break;
    }

    return q8_8::q8_8_fromFloat(y);
}


