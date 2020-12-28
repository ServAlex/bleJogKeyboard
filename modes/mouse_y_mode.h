#ifndef mouse_y_mode_h
#define mouse_y_mode_h

#include "mode_definition.h"
#include "BleCombo.h"

void encoderScrollHandler_mouse_y(BleComboKeyboard Keyboard, BleComboMouse Mouse, int32_t d)
{
    if(Keyboard.isConnected())
    {
        Mouse.move(0, char(d), 0, 0);
    }
}

void encoderClickHandler_mouse_y(BleComboKeyboard Keyboard, BleComboMouse Mouse)
{
    if(Keyboard.isConnected())
    {
    }
}

void primaryHandler_mouse_y(BleComboKeyboard Keyboard, BleComboMouse Mouse)
{
    if(Keyboard.isConnected())
    {
        Mouse.click(MOUSE_LEFT);
    }
}

void secondaryHandler_mouse_y(BleComboKeyboard Keyboard, BleComboMouse Mouse)
{
    if(Keyboard.isConnected())
    {
        Mouse.click(MOUSE_RIGHT);
    }
}

String modeShortName_mouse_y()
{
    return "mouse  y";
}

ModeDefinition mouse_y_mode_definition()
{
    ModeDefinition resultDefinition;
    resultDefinition.modeShortName = modeShortName_mouse_y;
    resultDefinition.encoderScrollHandler = encoderScrollHandler_mouse_y;
    resultDefinition.encoderClickHandler = encoderClickHandler_mouse_y;
    resultDefinition.primaryHandler = primaryHandler_mouse_y;
    resultDefinition.secondaryHandler = secondaryHandler_mouse_y;

    return resultDefinition;
}

#endif