#ifndef mouse_scroll_x_mode_h
#define mouse_scroll_x_mode_h

#include "mode_definition.h"
#include "BleCombo.h"

void encoderScrollHandler_mouse_scroll_x(BleComboKeyboard Keyboard, BleComboMouse Mouse, int32_t d)
{
    if(Keyboard.isConnected())
    {
        Mouse.move(0, 0, 0, char(d));
    }
}

void encoderClickHandler_mouse_scroll_x(BleComboKeyboard Keyboard, BleComboMouse Mouse)
{
    if(Keyboard.isConnected())
    {
    }
}

void primaryHandler_mouse_scroll_x(BleComboKeyboard Keyboard, BleComboMouse Mouse)
{
    if(Keyboard.isConnected())
    {
        Mouse.click(MOUSE_LEFT);
    }
}

void secondaryHandler_mouse_scroll_x(BleComboKeyboard Keyboard, BleComboMouse Mouse)
{
    if(Keyboard.isConnected())
    {
        Mouse.click(MOUSE_RIGHT);
    }
}

String modeShortName_mouse_scroll_x()
{
    return "scroll x";
}

ModeDefinition mouse_scroll_x_mode_definition()
{
    ModeDefinition resultDefinition;
    resultDefinition.modeShortName = modeShortName_mouse_scroll_x;
    resultDefinition.encoderScrollHandler = encoderScrollHandler_mouse_scroll_x;
    resultDefinition.encoderClickHandler = encoderClickHandler_mouse_scroll_x;
    resultDefinition.primaryHandler = primaryHandler_mouse_scroll_x;
    resultDefinition.secondaryHandler = secondaryHandler_mouse_scroll_x;

    return resultDefinition;
}

#endif