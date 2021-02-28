#ifndef ArrowsYMode_h
#define ArrowsYMode_h

#include "IMode.h"

class ArrowsYMode: public IMode
{
    protected:
        ~ArrowsYMode(){};
    public:
        ArrowsYMode(Logger* aLogger)
        {
            logger = aLogger;
            name = "arrows Y";
            encoderAction = ArrowsYEncoderAction;
            secondaryEncoderAction = ArrowsXEncoderAction;
        };

        Action ActionNameForButton(int buttonPin)
        {
            Action baseAction = IMode::ActionNameForButton(buttonPin);
            Action overrideAction = None;

            switch(buttonPin)
            {
                case Button34:
                    overrideAction = SwitchModeToArrowsXAction;
                    break;
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
