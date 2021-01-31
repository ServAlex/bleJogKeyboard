#ifndef MouseYMode_h
#define MouseYMode_h

#include "IMode.h"

class MouseYMode: public IMode
{
    protected:
        ~MouseYMode(){};
    public:
        MouseYMode()
        {
            name = "mouse Y";
            encoderAction = MouseYEncoderAction;
            secondaryEncoderAction = MouseXEncoderAction;
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
