#ifndef TabSwitchMode_h
#define TabSwitchMode_h

#include "IMode.h"

class TabSwithcMode: public IMode
{
    protected:
        ~TabSwithcMode(){};
    public:
        TabSwithcMode()
        {
            name = "tab swithc";
            encoderAction = TabSwitchEncoder;
            secondaryEncoderAction = TabSwitchEncoder;
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
