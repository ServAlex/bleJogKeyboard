#ifndef MouseScrollXMode_h
#define MouseScrollXMode_h

#include "IMode.h"

class MouseScrollXMode: public IMode
{
    protected:
        ~MouseScrollXMode(){};
    public:
        MouseScrollXMode()
        {
            name = "mouse scrl X";
            encoderAction = MouseScrollXEncoderAction;
            secondaryEncoderAction = MouseScrollYEncoderAction;
        };

        Action ActionNameForButton(int buttonPin)
        {
            switch (buttonPin)
            {
            case 35:
                return StartModeSelection;
                break;
            
            default:
                return None;
                break;
            }
        };
};

#endif
