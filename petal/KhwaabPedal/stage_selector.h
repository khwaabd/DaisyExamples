#include "daisy_petal.h"

namespace daisy {
    class StageSelector {
        public:
            // Stage Select Variables
            enum Stage {
                GENERAL,
                COMPRESSOR,
                GAIN,
                CHORUS,
                DELAY,
                REVERB,
                STAGE_MAX
            };

            DaisyPetal *hw;
            Stage currentStage;

            void init(DaisyPetal* hw, Stage initial);
            void processEncoder();
            void updateLeds();
    };
}

