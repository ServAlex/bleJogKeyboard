#ifndef arrows_vertical_mode_h
#define arrows_vertical_mode_h

#include "mode_definition.h"
#include "BleCombo.h"

void encoderScrollHandler_arrows_vertical(BleComboKeyboard Keyboard, BleComboMouse Mouse, int32_t d)
{
    if(Keyboard.isConnected())
    {
        const uint8_t key = d>0?KEY_UP_ARROW:KEY_DOWN_ARROW;
        for(int i = 0; i<abs(d); i++)
        {
            Keyboard.write(key);
        }
    }
}

void encoderClickHandler_arrows_vertical(BleComboKeyboard Keyboard, BleComboMouse Mouse)
{
    if(Keyboard.isConnected())
    {
    }
}

void primaryHandler_arrows_vertical(BleComboKeyboard Keyboard, BleComboMouse Mouse)
{
    if(Keyboard.isConnected())
    {
    }
}

void secondaryHandler_arrows_vertical(BleComboKeyboard Keyboard, BleComboMouse Mouse)
{
    if(Keyboard.isConnected())
    {
    }
}

void fastLoopHandler_arrows_vertical(BleComboKeyboard Keyboard, BleComboMouse Mouse)
{
}

String modeShortName_arrows_vertical()
{
    return "arrows  y";
}

ModeDefinition arrows_vertical_mode_definition()
{
    ModeDefinition resultDefinition;
    resultDefinition.modeShortName = modeShortName_arrows_vertical;
    resultDefinition.encoderScrollHandler = encoderScrollHandler_arrows_vertical;
    resultDefinition.encoderClickHandler = encoderClickHandler_arrows_vertical;
    resultDefinition.primaryHandler = primaryHandler_arrows_vertical;
    resultDefinition.secondaryHandler = secondaryHandler_arrows_vertical;
    resultDefinition.fastLoopHandler = fastLoopHandler_arrows_vertical;

    return resultDefinition;
}

#endif