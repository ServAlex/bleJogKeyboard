#include "ModeSelector.h"

ModeSelector::ModeSelector(Logger* aLogger, IMode** modes, int32_t modesCount, IMode* modeSelectionMode)
{
    this->logger = aLogger;
    this->modes = modes;
    this->modesCount = modesCount;
    this->modeSelectionMode = modeSelectionMode;
    currentModeIndex = 0;
    isInModeSelectionMode = false;

}

IMode* ModeSelector::getCurrentMode()
{
    if(isInModeSelectionMode)
    {
        return modeSelectionMode;
    }
    
    return modes[currentModeIndex];
}

IMode* ModeSelector::getSelectedMode()
{
    return modes[currentModeIndex];
}

IMode* ModeSelector::getNextMode()
{
    return modes[(currentModeIndex + 1) % modesCount];
}

IMode* ModeSelector::getPreviousMode()
{
    return modes[(currentModeIndex - 1 + modesCount) % modesCount];
}

int32_t ModeSelector::getCurrentModeIndex()
{
    return currentModeIndex;
}

int32_t ModeSelector::getModesCount()
{
    return modesCount;
}

void ModeSelector::switchToNextMode()
{
    currentModeIndex = (currentModeIndex + 1) % modesCount;
}

void ModeSelector::switchToPreviousMode()
{
    currentModeIndex = (currentModeIndex - 1 + modesCount) % modesCount;
}

void ModeSelector::switchToSelectionMode()
{
    isInModeSelectionMode = true;
}

void ModeSelector::completeSelectionMode()
{
    isInModeSelectionMode = false;
}

bool ModeSelector::isInSelectionMode()
{
    return isInModeSelectionMode;
}

void ModeSelector::switchToMode(IMode* mode)
{
    if(mode == modeSelectionMode)
    {
        isInModeSelectionMode = true;
        return;
    }

    currentModeIndex = 0;
    for(int i = 0; i<modesCount; i++)
    {
        if(modes[i] == mode)
            currentModeIndex = i;
    }
}

