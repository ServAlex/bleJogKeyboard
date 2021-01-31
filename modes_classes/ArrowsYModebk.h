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
        };

        String name;

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

        Action ActionNameForEncoder()
        {
            return ArrowsYEncoderAction;
        };

        Action SecondaryActionNameForEncoder()
        {
            return ArrowsXEncoderAction;
        };

        String GetName()
        {
            return name;
        };
};
/*
ArrowsYMode::ArrowsYMode() 
{
    name = "arrows Y";
}
String ArrowsYMode::GetName()
{
    return name;
}

Action ArrowsYMode::ActionNameForButton(int buttonPin)
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
}

Action ArrowsYMode::ActionNameForEncoder()
{
    return ArrowsYEncoderAction;
}

Action ArrowsYMode::SecondaryActionNameForEncoder()
{
    return ArrowsXEncoderAction;
}
*/

#endif
