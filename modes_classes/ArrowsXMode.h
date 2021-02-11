#ifndef ArrowsXMode_h
#define ArrowsXMode_h

#include "IMode.h"

class ArrowsXMode: public IMode
{
    protected:
        ~ArrowsXMode(){};
    public:
        ArrowsXMode()
        {
            name = "arrows X";
            encoderAction = ArrowsXEncoderAction;
            secondaryEncoderAction = ArrowsYEncoderAction;
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
