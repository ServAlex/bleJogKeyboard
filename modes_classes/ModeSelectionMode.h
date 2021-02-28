#ifndef ModeSelectionMode_h
#define ModeSelectionMode_h

#include "IMode.h"

class ModeSelectionMode: public IMode
{
    public:
        ModeSelectionMode(Logger* aLogger);
        String name = "mode sel";

        virtual Action ActionNameForButton(int buttonPin);
        virtual Action ActionNameForEncoder();
        virtual Action SecondaryActionNameForEncoder();
        String GetName();

    protected:
        ~ModeSelectionMode(){};
};

ModeSelectionMode::ModeSelectionMode(Logger* aLogger)
{
    logger = aLogger;
}

String ModeSelectionMode::GetName()
{
    return "mode selection";
}

Action ModeSelectionMode::ActionNameForButton(int buttonPin)
{
    Action baseAction = IMode::ActionNameForButton(buttonPin);
    Action overrideAction = None;

    switch(buttonPin)
    {
        case ButtonModeSelect:
            overrideAction = ConfirmModeSelection;
            break;
        default:
            overrideAction = None;
            break;
    }

    if(overrideAction != None)
        return overrideAction;

    return baseAction;
};

Action ModeSelectionMode::ActionNameForEncoder()
{
    return ModeSelectionEncoderAction;
}

Action ModeSelectionMode::SecondaryActionNameForEncoder()
{
    return ModeSelectionEncoderAction;
}

#endif
