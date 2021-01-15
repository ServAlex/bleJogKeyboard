#ifndef mouse_drag_y_mode_h
#define mouse_drag_y_mode_h

#include "mode_definition.h"
#include "BleCombo.h"

uint32_t drag_y_lastMovementTime = 0;
uint32_t drag_y_releaseThreshold = 1*1000;
bool drag_y_pressed = false;

void encoderScrollHandler_drag_y(BleComboKeyboard Keyboard, BleComboMouse Mouse, int32_t d)
{
    if(Keyboard.isConnected())
    {
        Mouse.press(MOUSE_LEFT);
        drag_y_pressed = true;
        Mouse.move(0, d, 0);

        drag_y_lastMovementTime = millis();
    }
}

void encoderClickHandler_drag_y(BleComboKeyboard Keyboard, BleComboMouse Mouse)
{
    if(Keyboard.isConnected())
    {
    }
}

void primaryHandler_drag_y(BleComboKeyboard Keyboard, BleComboMouse Mouse)
{
    if(Keyboard.isConnected())
    {
        Mouse.click(MOUSE_LEFT);
    }
}

void secondaryHandler_drag_y(BleComboKeyboard Keyboard, BleComboMouse Mouse)
{
    if(Keyboard.isConnected())
    {
        Mouse.click(MOUSE_RIGHT);
    }
}

void fastLoopHandler_drag_y(BleComboKeyboard Keyboard, BleComboMouse Mouse)
{
    if(millis() - drag_y_lastMovementTime > drag_y_releaseThreshold && drag_y_pressed)
    {
        Mouse.release(MOUSE_LEFT);
        Mouse.click(MOUSE_LEFT);
        drag_y_pressed = false;
        
        Serial.println("releasing");
    }
}

String modeShortName_drag_y()
{
    return "drag  y";
}

ModeDefinition mouse_drag_y_mode_definition()
{
    ModeDefinition resultDefinition;
    resultDefinition.modeShortName = modeShortName_drag_y;
    resultDefinition.encoderScrollHandler = encoderScrollHandler_drag_y;
    resultDefinition.encoderClickHandler = encoderClickHandler_drag_y;
    resultDefinition.primaryHandler = primaryHandler_drag_y;
    resultDefinition.secondaryHandler = secondaryHandler_drag_y;
    resultDefinition.fastLoopHandler = fastLoopHandler_drag_y;

    return resultDefinition;
}

#endif