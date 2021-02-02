#ifndef MouseDragYMode_h
#define MouseDragYMode_h

#include "IMode.h"

class MouseDragYMode: public IMode
{
    protected:
        ~MouseDragYMode(){};
    public:
        MouseDragYMode()
        {
            name = "mouse drag Y";
            encoderAction = MouseDragYEncoder;
            secondaryEncoderAction = MouseDragXEncoder;
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
