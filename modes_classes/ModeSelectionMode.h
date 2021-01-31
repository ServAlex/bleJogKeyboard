#ifndef ModeSelectionMode_h
#define ModeSelectionMode_h

#include "IMode.h"

class ModeSelectionMode: public IMode
{
    public:
        ModeSelectionMode();
        String name = "mode sel";

        virtual Action ActionNameForButton(int buttonPin);
        virtual Action ActionNameForEncoder();
        virtual Action SecondaryActionNameForEncoder();
        String GetName();

    protected:
        ~ModeSelectionMode(){};
};

ModeSelectionMode::ModeSelectionMode() { }

String ModeSelectionMode::GetName()
{
    return "mode selection";
}

Action ModeSelectionMode::ActionNameForButton(int buttonPin)
{
    switch (buttonPin)
    {
    case 35:
        return ConfirmModeSelection;
        break;
    
    default:
        return None;
        break;
    }
}

Action ModeSelectionMode::ActionNameForEncoder()
{
    return ModeSelectionEncoderAction;
}

Action ModeSelectionMode::SecondaryActionNameForEncoder()
{
    return ModeSelectionEncoderAction;
}

#endif
