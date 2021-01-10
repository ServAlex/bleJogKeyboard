#ifndef tab_switch_mode_h
#define tab_switch_mode_h

#include "mode_definition.h"
#include "BleCombo.h"

void encoderScrollHandler_tab_switch(BleComboKeyboard Keyboard, BleComboMouse Mouse, int32_t d)
{
    if(Keyboard.isConnected())
    {
        Keyboard.press(KEY_LEFT_CTRL);
        if(d<0)
        {
            Keyboard.press(KEY_LEFT_SHIFT);
        }
        
        for(int i = 0; i<abs(d); i++)
        {
            Keyboard.press(KEY_TAB);
        }
        Keyboard.releaseAll();
    }
}

void encoderClickHandler_tab_switch(BleComboKeyboard Keyboard, BleComboMouse Mouse)
{
    if(Keyboard.isConnected())
    {
    }
}

void primaryHandler_tab_switch(BleComboKeyboard Keyboard, BleComboMouse Mouse)
{
    if(Keyboard.isConnected())
    {
    }
}

void secondaryHandler_tab_switch(BleComboKeyboard Keyboard, BleComboMouse Mouse)
{
    if(Keyboard.isConnected())
    {
    }
}

void fastLoopHandler_tab_switch(BleComboKeyboard Keyboard, BleComboMouse Mouse)
{
}

String modeShortName_tab_switch()
{
    return String("tab sw");
}

ModeDefinition tab_switch_mode_definition()
{
    ModeDefinition resultDefinition;
    resultDefinition.modeShortName = modeShortName_tab_switch;
    resultDefinition.encoderScrollHandler = encoderScrollHandler_tab_switch;
    resultDefinition.encoderClickHandler = encoderClickHandler_tab_switch;
    resultDefinition.primaryHandler = primaryHandler_tab_switch;
    resultDefinition.secondaryHandler = secondaryHandler_tab_switch;
    resultDefinition.fastLoopHandler = fastLoopHandler_tab_switch;

    return resultDefinition;
}

#endif