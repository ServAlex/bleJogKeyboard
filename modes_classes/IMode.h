
#ifndef IMODE_H
#define IMODE_H

#include "Action.h"
#include "WString.h"

class IMode
{
    public:
        String name;
        virtual Action ActionNameForButton(int buttonPin){};
        virtual Action ActionNameForEncoder(){};
        virtual Action SecondaryActionNameForEncoder(){};
        virtual String GetName(){};
        
        //IMode(){};
        //virtual ~IMode() {}
        //virtual void PerformNamedAction(String actionName);
};

#endif

