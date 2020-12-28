#ifndef _mode_h
#define _mode_h

#include "mode_definition.h"
#include "BleCombo.h"

void encoderScrollHandler_(BleComboKeyboard Keyboard, BleComboMouse Mouse, int32_t d)
{
    if(Keyboard.isConnected())
    {
        const uint8_t* key = d>0?KEY_MEDIA_VOLUME_UP:KEY_MEDIA_VOLUME_DOWN;
        for(int i = 0; i<abs(d); i++)
        {
            Keyboard.write(key);
        }
    }
}

void encoderClickHandler_(BleComboKeyboard Keyboard, BleComboMouse Mouse)
{
    if(Keyboard.isConnected())
    {
    }
}

void primaryHandler_(BleComboKeyboard Keyboard, BleComboMouse Mouse)
{
    if(Keyboard.isConnected())
    {
    }
}

void secondaryHandler_(BleComboKeyboard Keyboard, BleComboMouse Mouse)
{
    if(Keyboard.isConnected())
    {
    }
}

String modeShortName_()
{
    return "";
}

ModeDefinition _mode_definition()
{
    ModeDefinition resultDefinition;
    resultDefinition.modeShortName = modeShortName_;
    resultDefinition.encoderScrollHandler = encoderScrollHandler_;
    resultDefinition.encoderClickHandler = encoderClickHandler_;
    resultDefinition.primaryHandler = primaryHandler_;
    resultDefinition.secondaryHandler = secondaryHandler_;

    return resultDefinition;
}

#endif