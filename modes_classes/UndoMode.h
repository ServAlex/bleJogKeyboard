#ifndef UndoMode_h
#define UndoMode_h

#include "IMode.h"

class UndoMode: public IMode
{
    protected:
        ~UndoMode(){};
        bool unixStyle;
    public:
        UndoMode(Logger* aLogger)
        {
            logger = aLogger;
            name = "undo";
            unixStyle = false;
            encoderAction = UndoEncoder;
            secondaryEncoderAction = UndoEncoder;
        };

        Action ActionNameForButton(int buttonPin)
        {
            Action baseAction = IMode::ActionNameForButton(buttonPin);
            Action overrideAction = None;

            switch(buttonPin)
            {
                case Button34:
                    overrideAction = SwitchUndoStyleAction;
                    break;
                default:
                    overrideAction = None;
                    break;
            }

            if(overrideAction != None)
                return overrideAction;

            return baseAction;
        };

        void SwitchStyle()
        {
            unixStyle = !unixStyle;
            name = unixStyle?"undo u":"undo";
            encoderAction = unixStyle?UndoUnixEncoder:UndoEncoder;
        }
};

#endif
