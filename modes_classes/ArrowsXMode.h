#ifndef ArrowsXMode_h
#define ArrowsXMode_h

#include "IMode.h"

class ArrowsXMode: public IMode
{
    public:
        ArrowsXMode();
        String name = "arrows x";

        Action ActionNameForButton(int buttonPin);
        Action ActionNameForEncoder();
        Action SecondaryActionNameForEncoder();
        String GetName();
        
    protected:
        ~ArrowsXMode(){};
};

ArrowsXMode::ArrowsXMode() 
{
    name = "arrows X";
}
String ArrowsXMode::GetName()
{
    return "arrows -";
}

Action ArrowsXMode::ActionNameForButton(int buttonPin)
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

Action ArrowsXMode::ActionNameForEncoder()
{
    return ArrowsXEncoderAction;
}

Action ArrowsXMode::SecondaryActionNameForEncoder()
{
    return ArrowsYEncoderAction;
}

#endif
