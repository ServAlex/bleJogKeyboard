#ifndef MouseXMode_h
#define MouseXMode_h

#include "IMode.h"

class MouseXMode: public IMode
{
    protected:
        ~MouseXMode(){};
    public:
        MouseXMode(Logger* aLogger)
        {
            logger = aLogger;
            name = "mouse X";
            encoderAction = MouseXEncoderAction;
            secondaryEncoderAction = MouseYEncoderAction;
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
