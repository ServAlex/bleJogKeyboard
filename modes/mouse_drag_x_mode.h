#ifndef mouse_drag_x_mode_h
#define mouse_drag_x_mode_h

#include "mode_definition.h"
#include "BleCombo.h"

uint32_t lastMovementTime = 0;
uint32_t releaseThreshold = 3*1000;
//bool leftButtonDown = false;

void encoderScrollHandler_drag_x(BleComboKeyboard Keyboard, BleComboMouse Mouse, int32_t d)
{
    if(Keyboard.isConnected())
    {
       /* 
        if(!leftButtonDown)
        {
            Mouse.press(MOUSE_LEFT);
            leftButtonDown = true;
        }
        */

        //Mouse.move(char(d), 0, 0, 0);
/*
        Mouse.move(10, 10, 0);
        Mouse.press(MOUSE_LEFT);

        Mouse.move(50, 50, 0);
        vTaskDelay(300);
*/

    //Mouse.move(10, 10, 0);
    Mouse.press(MOUSE_LEFT);
    Mouse.move(d, 0, 0);
    vTaskDelay(100);
    Mouse.release();
        //Mouse.release();

        lastMovementTime = millis();
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
    if(millis() - lastMovementTime > releaseThreshold && Mouse.isPressed(MOUSE_LEFT))
    {
        //leftButtonDown = false;
        Mouse.release();
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