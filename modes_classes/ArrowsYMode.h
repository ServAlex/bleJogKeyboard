#ifndef ArrowsYMode_h
#define ArrowsYMode_h

#include "IMode.h"

class ArrowsYMode: public IMode
{
    protected:
        ~ArrowsYMode(){};
    public:
        ArrowsYMode()
        {
            name = "arrows Y";
            encoderAction = ArrowsYEncoderAction;
            secondaryEncoderAction = ArrowsXEncoderAction;
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
