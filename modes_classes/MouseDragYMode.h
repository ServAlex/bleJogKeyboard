#ifndef MouseDragYMode_h
#define MouseDragYMode_h

#include "IMode.h"

class MouseDragYMode: public IMode
{
    protected:
        ~MouseDragYMode(){};
    public:
        MouseDragYMode(Logger* aLogger)
        {
            logger = aLogger;
            name = "mouse drag Y";
            encoderAction = MouseDragYEncoder;
            secondaryEncoderAction = MouseDragXEncoder;
        };

        Action ActionNameForButton(int buttonPin)
        {
            Action baseAction = IMode::ActionNameForButton(buttonPin);
            Action overrideAction = None;

            switch(buttonPin)
            {
                case Button34:
                    overrideAction = SwitchModeToMouseDragXAction;
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
