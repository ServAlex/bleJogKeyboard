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
                case Button34:
                    overrideAction = SwitchModeToMouseXAction;
                    break;

                case Button24:
                    overrideAction = SwitchModeToMouseYAction;
                    break;
                case Button23:
                    overrideAction = SwitchModeToMouseScrollYAction;
                    break;
                case Button22:
                    overrideAction = SwitchModeToMouseDragYAction;
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
