#ifndef ArrowsXMode_h
#define ArrowsXMode_h

#include "IMode.h"

class ArrowsXMode: public IMode
{
    protected:
        ~ArrowsXMode(){};
    public:
        String name;
        Action encoderAction;
        Action secondaryEncoderAction;

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
