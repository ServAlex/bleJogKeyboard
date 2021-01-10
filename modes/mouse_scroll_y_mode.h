#ifndef mouse_scroll_y_mode_h
#define mouse_scroll_y_mode_h

#include "mode_definition.h"
#include "BleCombo.h"

void encoderScrollHandler_mouse_scroll_y(BleComboKeyboard Keyboard, BleComboMouse Mouse, int32_t d)
{
    if(Keyboard.isConnected())
    {
        Mouse.move(0, 0, char(d), 0);
    }
}

void encoderClickHandler_mouse_scroll_y(BleComboKeyboard Keyboard, BleComboMouse Mouse)
{
    if(Keyboard.isConnected())
    {
    }
}

void primaryHandler_mouse_scroll_y(BleComboKeyboard Keyboard, BleComboMouse Mouse)
{
    if(Keyboard.isConnected())
    {
        Mouse.click(MOUSE_LEFT);
    }
}

void secondaryHandler_mouse_scroll_y(BleComboKeyboard Keyboard, BleComboMouse Mouse)
{
    if(Keyboard.isConnected())
    {
        Mouse.click(MOUSE_RIGHT);
    }
}

void fastLoopHandler_mouse_scroll_y(BleComboKeyboard Keyboard, BleComboMouse Mouse)
{
}

String modeShortName_mouse_scroll_y()
{
    return "scroll  y";
}

ModeDefinition mouse_scroll_y_mode_definition()
{
    ModeDefinition resultDefinition;
    resultDefinition.modeShortName = modeShortName_mouse_scroll_y;
    resultDefinition.encoderScrollHandler = encoderScrollHandler_mouse_scroll_y;
    resultDefinition.encoderClickHandler = encoderClickHandler_mouse_scroll_y;
    resultDefinition.primaryHandler = primaryHandler_mouse_scroll_y;
    resultDefinition.secondaryHandler = secondaryHandler_mouse_scroll_y;
    resultDefinition.fastLoopHandler = fastLoopHandler_mouse_scroll_y;

    return resultDefinition;
}

#endif