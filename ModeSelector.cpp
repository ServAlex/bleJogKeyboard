#include "ModeSelector.h"

ModeSelector::ModeSelector(Logger* aLogger, IMode** modes, int32_t modesCount, IMode* modeSelectionMode)
{
    this->logger = aLogger;
    this->modes = modes;
    this->modesCount = modesCount;
    this->modeSelectionMode = modeSelectionMode;
    currentModeIndex = 0;
}

IMode* ModeSelector::getCurrentMode()
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

}

void ModeSelector::switchToMode(IMode mode)
{

}

