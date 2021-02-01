#ifndef ExecutionController_h
#define ExecutionController_h

#include "BleCombo.h"
#include "Logger.h"
#include "modes_classes/Action.h"

class ExecutionController
{
    private:
        Logger* logger;
        bool awaitingActionCompletion;
        int32_t actionCompletionWaitingStartedTime;
        int32_t completionThreshold;
        void Awaited2KeyComboWithModifier(bool positive, uint8_t baseKey, uint8_t secondaryKey, uint8_t modifierKey, int32_t times, int32_t delay);

    public:
        ExecutionController(Logger* aLogger);
        void ExecuteAction(Action action, int32_t parameter);
        void TryActionCompletion(Action action);
};

#endif