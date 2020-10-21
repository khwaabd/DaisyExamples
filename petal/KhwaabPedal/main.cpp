// Basic Template for DaisyPetal
#include "daisy_petal.h"
#include "stage_selector.h"

using namespace daisy;

DaisyPetal hw;
StageSelector stage;


// Update Leds based on inputs
void updateLeds() {
    hw.ClearLeds();
    stage.updateLeds();
    hw.UpdateLeds();
}


void AudioCallback(float *in, float *out, size_t size) {
    // input debouncing and optimization
    hw.DebounceControls();
    hw.UpdateAnalogControls();

    //submodule processing
    stage.processEncoder();

    for(size_t i = 0; i < size; i += 2) {
        out[i]     = in[i];
        out[i + 1] = in[i + 1];
    }
}

int main(void) {
    // Petal Setup
    hw.Init();
    hw.StartAdc();

    //Module Init
    stage.init(&hw, StageSelector::GENERAL);

    //main loop
    hw.StartAudio(AudioCallback);
    for(;;) {
        dsy_system_delay(10);
        updateLeds();
    }
}
