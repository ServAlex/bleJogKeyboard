#ifndef alt_tab_mode_h
#define alt_tab_mode_h

#include "mode_definition.h"
#include "BleCombo.h"

uint32_t alt_tab_lastActionTime = 0;
uint32_t alt_tab_releaseThreshold = 1*1000;

void encoderScrollHandler_alt_tab(BleComboKeyboard Keyboard, BleComboMouse Mouse, int32_t d)
{
    if(Keyboard.isConnected())
    {
        Keyboard.press(KEY_LEFT_ALT);

        if(d<0)
        {
            Keyboard.press(KEY_LEFT_SHIFT);
        }
        
        for(int i = 0; i<abs(d); i++)
        {
            Keyboard.press(KEY_TAB);
            Keyboard.release(KEY_TAB);
        }

        if(d<0)
        {
            Keyboard.release(KEY_LEFT_SHIFT);
        }
        alt_tab_lastActionTime = millis();
        //Keyboard.releaseAll();
    }
}

void encoderClickHandler_alt_tab(BleComboKeyboard Keyboard, BleComboMouse Mouse)
{
    if(Keyboard.isConnected())
    {
    }
}

void primaryHandler_alt_tab(BleComboKeyboard Keyboard, BleComboMouse Mouse)
{
    if(Keyboard.isConnected())
    {
    }
}

void secondaryHandler_alt_tab(BleComboKeyboard Keyboard, BleComboMouse Mouse)
{
    if(Keyboard.isConnected())
    {
    }
}

void fastLoopHandler_alt_tab(BleComboKeyboard Keyboard, BleComboMouse Mouse)
{
    if(millis() - alt_tab_lastActionTime > alt_tab_releaseThreshold)
    {
        Keyboard.releaseAll();
    }
}

String modeShortName_alt_tab()
{
    return String("alt tab");
}

ModeDefinition alt_tab_mode_definition()
{
    ModeDefinition resultDefinition;
    resultDefinition.modeShortName = modeShortName_alt_tab;
    resultDefinition.encoderScrollHandler = encoderScrollHandler_alt_tab;
    resultDefinition.encoderClickHandler = encoderClickHandler_alt_tab;
    resultDefinition.primaryHandler = primaryHandler_alt_tab;
    resultDefinition.secondaryHandler = secondaryHandler_alt_tab;
    resultDefinition.fastLoopHandler = fastLoopHandler_alt_tab;

    return resultDefinition;
}

#endif