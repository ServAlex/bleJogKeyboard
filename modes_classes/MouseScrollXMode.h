#ifndef MouseScrollXMode_h
#define MouseScrollXMode_h

#include "IMode.h"

class MouseScrollXMode: public IMode
{
    protected:
        ~MouseScrollXMode(){};
    public:
        MouseScrollXMode(Logger* aLogger)
        {
            logger = aLogger;
            name = "mouse scrl X";
            encoderAction = MouseScrollXEncoderAction;
            secondaryEncoderAction = MouseScrollYEncoderAction;
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
