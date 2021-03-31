
#ifndef IMODE_H
#define IMODE_H

#include "Action.h"
#include "WString.h"
#include "../ButtonPins.h"
#include "../Logger.h"

class IMode
{
    public:
        String name;
        Action encoderAction;
        Action secondaryEncoderAction;
        Logger* logger;
        
        virtual Action ActionNameForButton(int buttonPin)
        {
            switch (buttonPin)
            {
                /*
                case ButtonModeSelect:
                    return StartModeSelection;
                    break;
*/

                case Button31:
                    return SwitchToPreviousModeAction;
                    break;

                case Button21:
                    return SwitchToNextModeAction;
                    break;
                
                default:
                    return None;
                    break;
            }
        };
        virtual Action ActionNameForEncoder()
        {
            return encoderAction;
        };
        virtual Action SecondaryActionNameForEncoder()
        {
            return secondaryEncoderAction;
        };
        virtual String GetName()
        {
            return name;
        };
        
        //IMode(){};
        //virtual ~IMode() {}
        //virtual void PerformNamedAction(String actionName);
};

#endif

