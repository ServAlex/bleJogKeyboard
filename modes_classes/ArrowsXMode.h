#ifndef ArrowsXMode_h
#define ArrowsXMode_h

#include "IMode.h"

class ArrowsXMode: public IMode
{
    protected:
        ~ArrowsXMode(){};
    public:
        ArrowsXMode(Logger* aLogger)
        {
            logger = aLogger;
            name = "arrows X";
            encoderAction = ArrowsXEncoderAction;
            secondaryEncoderAction = ArrowsYEncoderAction;
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
