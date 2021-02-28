#ifndef ZoomMode_h
#define ZoomMode_h

#include "IMode.h"

class ZoomMode: public IMode
{
    protected:
        ~ZoomMode(){};
    public:
        ZoomMode(Logger* aLogger)
        {
            logger = aLogger;
            name = "zoom";
            encoderAction = ZooomEncoder;
            secondaryEncoderAction = ZooomEncoder;
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
