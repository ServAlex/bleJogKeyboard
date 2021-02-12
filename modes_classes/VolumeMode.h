#ifndef VolumeMode_h
#define VolumeMode_h

#include "IMode.h"

class VolumeMode: public IMode
{
    protected:
        ~VolumeMode(){};
    public:
        VolumeMode(Logger* aLogger)
        {
            logger = aLogger;
            name = "volume";
            encoderAction = VolumeEncoder;
            secondaryEncoderAction = VolumeEncoder;
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
