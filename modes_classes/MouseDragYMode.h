#ifndef MouseDragYMode_h
#define MouseDragYMode_h

#include "IMode.h"

class MouseDragYMode: public IMode
{
    protected:
        ~MouseDragYMode(){};
    public:
        MouseDragYMode(Logger* aLogger)
        {
            logger = aLogger;
            name = "mouse drag Y";
            encoderAction = MouseDragYEncoder;
            secondaryEncoderAction = MouseDragXEncoder;
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
