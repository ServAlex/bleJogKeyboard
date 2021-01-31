#ifndef ArrowsYMode_h
#define ArrowsYMode_h

#include "IMode.h"

class ArrowsYMode: public IMode
{
    public:
        ArrowsYMode();
        String name = "arrows y";

        Action ActionNameForButton(int buttonPin);
        Action ActionNameForEncoder();
        Action SecondaryActionNameForEncoder();
        String GetName();
        
    protected:
        ~ArrowsYMode(){};
};

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

#endif
