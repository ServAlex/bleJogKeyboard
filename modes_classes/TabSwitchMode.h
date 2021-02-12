#ifndef TabSwitchMode_h
#define TabSwitchMode_h

#include "IMode.h"

class TabSwithcMode: public IMode
{
    protected:
        ~TabSwithcMode(){};
    public:
        TabSwithcMode(Logger* aLogger)
        {
            logger = aLogger;
            name = "tab swithc";
            encoderAction = TabSwitchEncoder;
            secondaryEncoderAction = TabSwitchEncoder;
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
