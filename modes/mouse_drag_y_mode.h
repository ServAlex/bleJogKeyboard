#ifndef mouse_drag_y_mode_h
#define mouse_drag_y_mode_h

#include "mode_definition.h"
#include "BleCombo.h"

void encoderScrollHandler_drag_y(BleComboKeyboard Keyboard, BleComboMouse Mouse, int32_t d)
{
    if(Keyboard.isConnected())
    {
        /*
        if(!leftButtonDown)
        {
            Mouse.press(MOUSE_LEFT);
            leftButtonDown = true;
        }
        Mouse.move(0, char(d), 0, 0);
        lastMovementTime = millis();
        */

        Mouse.press(MOUSE_LEFT);
        Mouse.move(0, d, 0);
        vTaskDelay(100);
        Mouse.release();
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
    /*
    if(millis() - lastMovementTime > releaseThreshold)
    {
        leftButtonDown = false;
        Mouse.release();
    }
    */
    if(millis() - lastMovementTime > releaseThreshold && Mouse.isPressed(MOUSE_LEFT))
    {
        //leftButtonDown = false;
        Mouse.release();
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