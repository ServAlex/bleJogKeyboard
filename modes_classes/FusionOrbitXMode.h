#ifndef FusionOrbitXMode_h
#define FusionOrbitXMode_h

#include "IMode.h"

class FusionOrbitXMode: public IMode
{
    protected:
        ~FusionOrbitXMode(){};
    public:
        FusionOrbitXMode()
        {
            name = "Fusion orbit X";
            encoderAction = FusionOrbitXEncoder;
            secondaryEncoderAction = FusionOrbitYEncoder;
        };

        Action ActionNameForButton(int buttonPin)
        {
            switch (buttonPin)
            {
            case 35:
                return StartModeSelection;
                break;
            
            default:
                return None;
                break;
            }
        };
};

#endif
