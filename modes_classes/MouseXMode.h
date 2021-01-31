#ifndef MouseXMode_h
#define MouseXMode_h

#include "IMode.h"

class MouseXMode: public IMode
{
    protected:
        ~MouseXMode(){};
    public:
        MouseXMode()
        {
            name = "mouse X";
            encoderAction = MouseXEncoderAction;
            secondaryEncoderAction = MouseYEncoderAction;
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
