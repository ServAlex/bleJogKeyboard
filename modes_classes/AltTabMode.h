#ifndef AltTabMode_h
#define AltTabMode_h

#include "IMode.h"

class AltTabMode: public IMode
{
    protected:
        ~AltTabMode(){};
    public:
        AltTabMode()
        {
            name = "alt tab";
            encoderAction = AltTabEncoder;
            secondaryEncoderAction = AltTabEncoder;
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
