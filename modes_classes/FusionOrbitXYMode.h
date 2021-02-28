#ifndef FusionOrbitXYMode_h
#define FusionOrbitXYMode_h

#include "IMode.h"

class FusionOrbitXYMode: public IMode
{
    protected:
        ~FusionOrbitXYMode(){};
    public:
        FusionOrbitXYMode(Logger* aLogger)
        {
            logger = aLogger;
            name = "Fusion orb XY";
            encoderAction = FusionOrbitXYEncoder;
            secondaryEncoderAction = FusionOrbitXYInvertedEncoder;
        };

        Action ActionNameForButton(int buttonPin)
        {
            Action baseAction = IMode::ActionNameForButton(buttonPin);
            Action overrideAction = None;

            switch(buttonPin)
            {
                default:
                    overrideAction = None;
                    break;
            }

            if(overrideAction != None)
                return overrideAction;

            return baseAction;
        };
};

#endif
