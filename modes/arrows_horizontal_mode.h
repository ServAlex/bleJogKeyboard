#ifndef arrows_horizontal_mode_h
#define arrows_horizontal_mode_h

#include "mode_definition.h"
#include "BleCombo.h"

void encoderScrollHandler_arrows_horizontal(BleComboKeyboard Keyboard, BleComboMouse Mouse, int32_t d)
{
    if(Keyboard.isConnected())
    {
        const uint8_t key = d>0?KEY_RIGHT_ARROW:KEY_LEFT_ARROW;
        for(int i = 0; i<abs(d); i++)
        {
            Keyboard.write(key);
        }
    }
}

void encoderClickHandler_arrows_horizontal(BleComboKeyboard Keyboard, BleComboMouse Mouse)
{
    if(Keyboard.isConnected())
    {
    }
}

void primaryHandler_arrows_horizontal(BleComboKeyboard Keyboard, BleComboMouse Mouse)
{
    if(Keyboard.isConnected())
    {
    }
}

void secondaryHandler_arrows_horizontal(BleComboKeyboard Keyboard, BleComboMouse Mouse)
{
    if(Keyboard.isConnected())
    {
    }
}

void fastLoopHandler_arrows_horizontal(BleComboKeyboard Keyboard, BleComboMouse Mouse)
{
}

String modeShortName_arrows_horizontal()
{
    return "arrows x";
}

ModeDefinition arrows_horizontal_mode_definition()
{
    ModeDefinition resultDefinition;
    resultDefinition.modeShortName = modeShortName_arrows_horizontal;
    resultDefinition.encoderScrollHandler = encoderScrollHandler_arrows_horizontal;
    resultDefinition.encoderClickHandler = encoderClickHandler_arrows_horizontal;
    resultDefinition.primaryHandler = primaryHandler_arrows_horizontal;
    resultDefinition.secondaryHandler = secondaryHandler_arrows_horizontal;
    resultDefinition.fastLoopHandler = fastLoopHandler_arrows_horizontal;

    return resultDefinition;
}

#endif