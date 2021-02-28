#ifndef FusionOrbitXYInvertedMode_h
#define FusionOrbitXYInvertedMode_h

#include "IMode.h"

class FusionOrbitXYInvertedMode: public IMode
{
    protected:
        ~FusionOrbitXYInvertedMode(){};
    public:
        FusionOrbitXYInvertedMode(Logger* aLogger)
        {
            logger = aLogger;
            name = "Fusion orb XYi";
            encoderAction = FusionOrbitXYInvertedEncoder;
            secondaryEncoderAction = FusionOrbitXYEncoder;
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
