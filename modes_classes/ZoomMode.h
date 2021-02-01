#ifndef ZoomMode_h
#define ZoomMode_h

#include "IMode.h"

class ZoomMode: public IMode
{
    protected:
        ~ZoomMode(){};
    public:
        ZoomMode()
        {
            name = "zoom";
            encoderAction = ZooomEncoder;
            secondaryEncoderAction = ZooomEncoder;
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
