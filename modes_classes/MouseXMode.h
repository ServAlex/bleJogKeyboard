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
                case Button34:
                    overrideAction = SwitchModeToMouseYAction;
                    break;

                case Button24:
                    overrideAction = SwitchModeToMouseXAction;
                    break;
                case Button23:
                    overrideAction = SwitchModeToMouseScrollXAction;
                    break;
                case Button22:
                    overrideAction = SwitchModeToMouseDragXAction;
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
