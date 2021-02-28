#ifndef AltTabMode_h
#define AltTabMode_h

#include "IMode.h"

class AltTabMode: public IMode
{
    protected:
        ~AltTabMode(){};
    public:
        AltTabMode(Logger* aLogger)
        {
            logger = aLogger;
            name = "alt tab";
            encoderAction = AltTabEncoder;
            secondaryEncoderAction = AltTabEncoder;
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
