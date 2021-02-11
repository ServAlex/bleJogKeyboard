#ifndef MouseScrollYMode_h
#define MouseScrollYMode_h

#include "IMode.h"

class MouseScrollYMode: public IMode
{
    protected:
        ~MouseScrollYMode(){};
    public:
        MouseScrollYMode()
        {
            name = "mouse scrl y";
            encoderAction = MouseScrollYEncoderAction;
            secondaryEncoderAction = MouseScrollXEncoderAction;
        };

        Action ActionNameForButton(int buttonPin)
        {
            switch (buttonPin)
            {
            case 13:
                return StartModeSelection;
                break;
            
            default:
                return None;
                break;
            }
        };
};

#endif
