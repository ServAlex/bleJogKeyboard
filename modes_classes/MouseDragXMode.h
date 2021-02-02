#ifndef MouseDragXMode_h
#define MouseDragXMode_h

#include "IMode.h"

class MouseDragXMode: public IMode
{
    protected:
        ~MouseDragXMode(){};
    public:
        MouseDragXMode()
        {
            name = "mouse drag X";
            encoderAction = MouseDragXEncoder;
            secondaryEncoderAction = MouseDragYEncoder;
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
