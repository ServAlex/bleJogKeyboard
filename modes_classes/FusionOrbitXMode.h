#ifndef FusionOrbitXMode_h
#define FusionOrbitXMode_h

#include "IMode.h"

class FusionOrbitXMode: public IMode
{
    protected:
        ~FusionOrbitXMode(){};
    public:
        FusionOrbitXMode(Logger* aLogger)
        {
            logger = aLogger;
            name = "Fusion orbit X";
            encoderAction = FusionOrbitXEncoder;
            secondaryEncoderAction = FusionOrbitYEncoder;
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
