#ifndef UndoMode_h
#define UndoMode_h

#include "IMode.h"

class UndoMode: public IMode
{
    protected:
        ~UndoMode(){};
    public:
        UndoMode(Logger* aLogger)
        {
            logger = aLogger;
            name = "undo";
            encoderAction = UndoEncoder;
            secondaryEncoderAction = UndoEncoder;
        };

        Action ActionNameForButton(int buttonPin)
        {
            Action baseAction = IMode::ActionNameForButton(buttonPin);
            Action overrideAction = None;

            switch(buttonPin)
            {
                default:
                    overrideAction = None;
                    break;
            }

            if(overrideAction != None)
                return overrideAction;

            return baseAction;
        };
};

#endif
