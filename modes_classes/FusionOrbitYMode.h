#ifndef FusionOrbitYMode_h
#define FusionOrbitYMode_h

#include "IMode.h"

class FusionOrbitYMode: public IMode
{
    protected:
        ~FusionOrbitYMode(){};
    public:
        FusionOrbitYMode()
        {
            name = "Fusion orb Y";
            encoderAction = FusionOrbitYEncoder;
            secondaryEncoderAction = FusionOrbitXEncoder;
        };

        Action ActionNameForButton(int buttonPin)
        {
            switch (buttonPin)
            {
            case 13:
                return StartModeSelection;
                break;
            
            default:
                return None;
                break;
            }
        };
};

#endif
