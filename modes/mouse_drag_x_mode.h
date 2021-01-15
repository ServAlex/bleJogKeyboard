#ifndef mouse_drag_x_mode_h
#define mouse_drag_x_mode_h

#include "mode_definition.h"
#include "BleCombo.h"

uint32_t drag_x_lastMovementTime = 0;
uint32_t drag_x_releaseThreshold = 1*1000;
bool drag_x_pressed = false;

void encoderScrollHandler_drag_x(BleComboKeyboard Keyboard, BleComboMouse Mouse, int32_t d)
{
    if(Keyboard.isConnected())
    {
        Mouse.press(MOUSE_LEFT);
        drag_x_pressed = true;
        Mouse.move(d, 0, 0);

        drag_x_lastMovementTime = millis();
    }
}

void encoderClickHandler_drag_x(BleComboKeyboard Keyboard, BleComboMouse Mouse)
{
    if(Keyboard.isConnected())
    {
    }
}

void primaryHandler_drag_x(BleComboKeyboard Keyboard, BleComboMouse Mouse)
{
    if(Keyboard.isConnected())
    {
        Mouse.click(MOUSE_LEFT);
    }
}

void secondaryHandler_drag_x(BleComboKeyboard Keyboard, BleComboMouse Mouse)
{
    if(Keyboard.isConnected())
    {
        Mouse.click(MOUSE_RIGHT);
    }
}

void fastLoopHandler_drag_x(BleComboKeyboard Keyboard, BleComboMouse Mouse)
{
    if(millis() - drag_x_lastMovementTime > drag_x_releaseThreshold && drag_x_pressed)
    {
        Mouse.release(MOUSE_LEFT);
        Mouse.click(MOUSE_LEFT);
        drag_x_pressed = false;
        
        Serial.println("releasing");
    }
}

String modeShortName_drag_x()
{
    return "drag x";
}

ModeDefinition mouse_drag_x_mode_definition()
{
    ModeDefinition resultDefinition;
    resultDefinition.modeShortName = modeShortName_drag_x;
    resultDefinition.encoderScrollHandler = encoderScrollHandler_drag_x;
    resultDefinition.encoderClickHandler = encoderClickHandler_drag_x;
    resultDefinition.primaryHandler = primaryHandler_drag_x;
    resultDefinition.secondaryHandler = secondaryHandler_drag_x;
    resultDefinition.fastLoopHandler = fastLoopHandler_drag_x;

    return resultDefinition;
}

#endif