#ifndef ModeSelector_h
#define ModeSelector_h

#include <stddef.h>
#include "Logger.h"
#include "modes_classes/IMode.h"

class ModeSelector
{
    private:
        Logger* logger;
        IMode** modes;
        int32_t modesCount;
        IMode* modeSelectionMode;
        int32_t currentModeIndex;
        bool isInModeSelectionMode;

    public:
        ModeSelector(Logger* aLogger, IMode** modes, int32_t modesCount, IMode* modeSelectionMode);
        IMode* getCurrentMode();
        IMode* getNextMode();
        IMode* getPreviousMode();

        // next mode in the array of normal modes, not mode selection mode
        void switchToNextMode();
        // previous mode in the array of normal modes, not mode selection mode
        void switchToPreviousMode();
        // mode selection mode
        void switchToSelectionMode();
        void completeSelectionMode();
        bool isInSelectionMode();
        // some mode in the array of normal modes, not mode selection mode
        void switchToMode(IMode* mode);

        int32_t getCurrentModeIndex();
        int32_t getModesCount();
};

#endif
