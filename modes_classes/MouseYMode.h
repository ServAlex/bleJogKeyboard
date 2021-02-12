#ifndef MouseYMode_h
#define MouseYMode_h

#include "IMode.h"

class MouseYMode: public IMode
{
    protected:
        ~MouseYMode(){};
    public:
        MouseYMode(Logger* aLogger)
        {
            logger = aLogger;
            name = "mouse Y";
            encoderAction = MouseYEncoderAction;
            secondaryEncoderAction = MouseXEncoderAction;
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
