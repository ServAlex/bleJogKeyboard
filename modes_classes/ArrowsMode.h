#ifndef ArrowsMode_h
#define ArrowsMode_h

#include "IMode.h"
#include "Axis.h"

class ArrowsMode: public IMode
{
    protected:
        ~ArrowsMode(){};
        Axis axis;
    public:
        ArrowsMode(Logger* aLogger)
        {
            logger = aLogger;
            name = "arrows X";
            axis = X;

            encoderAction = ArrowsXEncoderAction;
            secondaryEncoderAction = ArrowsYEncoderAction;
        };

        Action ActionNameForButton(int buttonPin)
        {
            Action baseAction = IMode::ActionNameForButton(buttonPin);
            Action overrideAction = None;

            switch(buttonPin)
            {
                case Button34:
                    overrideAction = SwitchArrowsAxisAction;
                    break;
                default:
                    overrideAction = None;
                    break;
            }

            if(overrideAction != None)
                return overrideAction;

            return baseAction;
        };

        void SwithcAxis()
        {
            axis = axis==X?Y:X;
            encoderAction = (axis==X)?ArrowsXEncoderAction:ArrowsYEncoderAction;
            name = (axis==X)?"arrows X":"arrows Y";
        };
};

#endif
