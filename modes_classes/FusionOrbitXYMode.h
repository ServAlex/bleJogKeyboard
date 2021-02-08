#ifndef FusionOrbitXYMode_h
#define FusionOrbitXYMode_h

#include "IMode.h"

class FusionOrbitXYMode: public IMode
{
    protected:
        ~FusionOrbitXYMode(){};
    public:
        FusionOrbitXYMode()
        {
            name = "Fusion orb XY";
            encoderAction = FusionOrbitXYEncoder;
            secondaryEncoderAction = FusionOrbitXYInvertedEncoder;
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
