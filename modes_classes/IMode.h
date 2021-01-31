
#ifndef IMODE_H
#define IMODE_H

#include "Action.h"
#include "WString.h"

class IMode
{
    public:
        String name;
        Action encoderAction;
        Action secondaryEncoderAction;
        
        virtual Action ActionNameForButton(int buttonPin){};
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

