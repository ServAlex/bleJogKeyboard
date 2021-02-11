#ifndef UndoMode_h
#define UndoMode_h

#include "IMode.h"

class UndoMode: public IMode
{
    protected:
        ~UndoMode(){};
    public:
        UndoMode()
        {
            name = "undo";
            encoderAction = UndoEncoder;
            secondaryEncoderAction = UndoEncoder;
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
