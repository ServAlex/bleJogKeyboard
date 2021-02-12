#ifndef FusionOrbitYMode_h
#define FusionOrbitYMode_h

#include "IMode.h"

class FusionOrbitYMode: public IMode
{
    protected:
        ~FusionOrbitYMode(){};
    public:
        FusionOrbitYMode(Logger* aLogger)
        {
            logger = aLogger;
            name = "Fusion orb Y";
            encoderAction = FusionOrbitYEncoder;
            secondaryEncoderAction = FusionOrbitXEncoder;
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
