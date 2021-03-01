#ifndef ModeSelector_h
#define ModeSelector_h

#include <stddef.h>
#include "Logger.h"
#include "modes_classes/IMode.h"
#include "modes_classes/AltTabMode.h"
#include "modes_classes/FusionOrbitXMode.h"
#include "modes_classes/FusionOrbitYMode.h"
#include "modes_classes/TabSwitchMode.h"
#include "modes_classes/UndoMode.h"
#include "modes_classes/VolumeMode.h"
#include "modes_classes/ZoomMode.h"

#include "modes_classes/MouseMode.h"
#include "modes_classes/ArrowsMode.h"

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
        IMode* getCurrentMode();    // mode from the array or mode selection mode
        IMode* getSelectedMode();   // mode from the array
        IMode* getNextMode();
        IMode* getPreviousMode();

        AltTabMode* altTabMode;
        FusionOrbitXMode* fusionOrbitXMode;
        FusionOrbitYMode* fusionOrbitYMode;
        TabSwithcMode* tabSwitchMode;
        UndoMode* undoMode;
        VolumeMode* volumeMode;
        ZoomMode* zoomMode;
        MouseMode* mouseMode;
        ArrowsMode* arrowsMode;

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
