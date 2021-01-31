#ifndef ExecutionController_h
#define ExecutionController_h

#include "BleCombo.h"
#include "Logger.h"
#include "modes_classes/Action.h"

class ExecutionController
{
    private:
        Logger* logger;
    public:
        ExecutionController(Logger* aLogger);
        void ExecuteAction(Action action, int32_t parameter);
};

#endif