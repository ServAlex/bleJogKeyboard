#ifndef FusionOrbitXYInvertedMode_h
#define FusionOrbitXYInvertedMode_h

#include "IMode.h"

class FusionOrbitXYInvertedMode: public IMode
{
    protected:
        ~FusionOrbitXYInvertedMode(){};
    public:
        FusionOrbitXYInvertedMode()
        {
            name = "Fusion orb XYi";
            encoderAction = FusionOrbitXYInvertedEncoder;
            secondaryEncoderAction = FusionOrbitXYEncoder;
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
