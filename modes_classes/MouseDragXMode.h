#ifndef MouseDragXMode_h
#define MouseDragXMode_h

#include "IMode.h"

class MouseDragXMode: public IMode
{
    protected:
        ~MouseDragXMode(){};
    public:
        MouseDragXMode(Logger* aLogger)
        {
            logger = aLogger;
            name = "mouse drag X";
            encoderAction = MouseDragXEncoder;
            secondaryEncoderAction = MouseDragYEncoder;
        };

        Action ActionNameForButton(int buttonPin)
        {
            Action baseAction = IMode::ActionNameForButton(buttonPin);
            Action overrideAction = None;

            switch(buttonPin)
            {
                case Button34:
                    overrideAction = SwitchModeToMouseDragYAction;
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
