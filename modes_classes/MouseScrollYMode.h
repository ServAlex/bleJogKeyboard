#ifndef MouseScrollYMode_h
#define MouseScrollYMode_h

#include "IMode.h"

class MouseScrollYMode: public IMode
{
    protected:
        ~MouseScrollYMode(){};
    public:
        MouseScrollYMode(Logger* aLogger)
        {
            logger = aLogger;
            name = "mouse scrl y";
            encoderAction = MouseScrollYEncoderAction;
            secondaryEncoderAction = MouseScrollXEncoderAction;
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
