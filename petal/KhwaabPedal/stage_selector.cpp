#include "stage_selector.h"

using namespace daisy;

void StageSelector::init(DaisyPetal *hw, Stage initial) {
    hw = hw;
    currentStage = initial;
}

void StageSelector::processEncoder() {
    int32_t encoder = hw->encoder.Increment();
    if(encoder < 0) {
        if(currentStage != GENERAL) {
            currentStage = static_cast<Stage>(static_cast<int>(currentStage - 1));
        }
    }
    else if(encoder > 0) {
        currentStage = static_cast<Stage>(static_cast<int>(currentStage + 1));
        if(currentStage == STAGE_MAX) {
            currentStage = static_cast<Stage>(static_cast<int>(currentStage - 1));
        }
    }
}

void StageSelector::updateLeds() {
    hw->SetRingLed(static_cast<DaisyPetal::RingLed>(1), 1,0,0);
}


