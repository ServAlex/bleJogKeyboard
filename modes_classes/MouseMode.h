#ifndef MouseMode_h
#define MouseMode_h

#include "IMode.h"
#include "Axis.h"

enum MouseModeStyle
{
    Regular,
    Scroll,
    Drag
};

class MouseMode: public IMode
{
    protected:
        ~MouseMode(){};
        Axis axis;
        MouseModeStyle modeStyle;
    public:
        MouseMode(Logger* aLogger)
        {
            logger = aLogger;
            name = "mouse X";
            axis = X;
            modeStyle = Regular;

            encoderAction = MouseXEncoderAction;
            secondaryEncoderAction = MouseYEncoderAction;
        };

        Action ActionNameForButton(int buttonPin)
        {
            Action baseAction = IMode::ActionNameForButton(buttonPin);
            Action overrideAction = None;

            switch(buttonPin)
            {
                case Button34:
                    overrideAction = SwitchMouseAxisAction;
                    break;

                case Button24:
                    overrideAction = SwitchMouseStyleToRegularAction;
                    break;
                case Button23:
                    overrideAction = SwitchMouseStyleToScrollAction;
                    break;
                case Button22:
                    overrideAction = SwitchMouseStyleToDragAction;
                    break;

                default:
                    overrideAction = None;
                    break;
            }

            if(overrideAction != None)
                return overrideAction;

            return baseAction;
        };

        void SwitchAxis()
        {
            axis = axis==X?Y:X;
            logger->Log("switching axis, new axis " + String(axis));
            switch(modeStyle)
            {
                case Regular:
                    encoderAction = (axis==X)?MouseXEncoderAction:MouseYEncoderAction;
                    break;
                case Scroll:
                    encoderAction = (axis==X)?MouseScrollXEncoderAction:MouseScrollYEncoderAction;
                    break;
                case Drag:
                    encoderAction = (axis==X)?MouseDragXEncoder:MouseDragYEncoder;
                    break;
            }
        };

        void SwitchToRegularStyle()
        {
            modeStyle = Regular;
            encoderAction = (axis==X)?MouseXEncoderAction:MouseYEncoderAction;
        };

        void SwitchToScrollStyle()
        {
            modeStyle = Scroll;
            encoderAction = (axis==X)?MouseScrollXEncoderAction:MouseScrollYEncoderAction;
        };

        void SwitchToDragStyle()
        {
            modeStyle = Drag;
            encoderAction = (axis==X)?MouseDragXEncoder:MouseDragYEncoder;
        };

        String GetName()
        {
            String newName = "new name";
            String axisName = (axis==X)?"X":"Y";
            switch (modeStyle)
            {
                case Regular:
                    newName = "mouse " + axisName;
                    break;
                
                case Scroll:
                    newName = "mouse scrl " + axisName;
                    break;

                case Drag:
                    newName = "mouse drag " + axisName;
                    break;

                default:
                    newName = "mouse";
                    break;
            }

            return newName;
        }
};

#endif
