#ifndef mouse_x_mode_h
#define mouse_x_mode_h

#include "mode_definition.h"
#include "BleCombo.h"

void encoderScrollHandler_mouse_x(BleComboKeyboard Keyboard, BleComboMouse Mouse, int32_t d)
{
    if(Keyboard.isConnected())
    {
        Mouse.move(char(d), 0, 0, 0);
    }
}

void encoderClickHandler_mouse_x(BleComboKeyboard Keyboard, BleComboMouse Mouse)
{
    if(Keyboard.isConnected())
    {
    }
}

void primaryHandler_mouse_x(BleComboKeyboard Keyboard, BleComboMouse Mouse)
{
    if(Keyboard.isConnected())
    {
        Mouse.click(MOUSE_LEFT);
    }
}

void secondaryHandler_mouse_x(BleComboKeyboard Keyboard, BleComboMouse Mouse)
{
    if(Keyboard.isConnected())
    {
        Mouse.click(MOUSE_RIGHT);
    }
}

String modeShortName_mouse_x()
{
    return "mouse x";
}

ModeDefinition mouse_x_mode_definition()
{
    ModeDefinition resultDefinition;
    resultDefinition.modeShortName = modeShortName_mouse_x;
    resultDefinition.encoderScrollHandler = encoderScrollHandler_mouse_x;
    resultDefinition.encoderClickHandler = encoderClickHandler_mouse_x;
    resultDefinition.primaryHandler = primaryHandler_mouse_x;
    resultDefinition.secondaryHandler = secondaryHandler_mouse_x;

    return resultDefinition;
}

#endif