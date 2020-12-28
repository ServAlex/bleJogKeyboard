#ifndef volume_mode_h
#define volume_mode_h

#include "mode_definition.h"
#include "BleCombo.h"

void encoderScrollHandler_volume(BleComboKeyboard Keyboard, BleComboMouse Mouse, int32_t d)
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

void encoderClickHandler_volume(BleComboKeyboard Keyboard, BleComboMouse Mouse)
{

}

void primaryHandler_volume(BleComboKeyboard Keyboard, BleComboMouse Mouse)
{
    if(Keyboard.isConnected())
    {
        Keyboard.write(KEY_MEDIA_MUTE);
    }
}

void secondaryHandler_volume(BleComboKeyboard Keyboard, BleComboMouse Mouse)
{

}

String modeShortName_volume()
{
    return "volume";
}

ModeDefinition volume_mode_definition()
{
    ModeDefinition resultDefinition;
    resultDefinition.modeShortName = modeShortName_volume;
    resultDefinition.encoderScrollHandler = encoderScrollHandler_volume;
    resultDefinition.encoderClickHandler = encoderClickHandler_volume;
    resultDefinition.primaryHandler = primaryHandler_volume;
    resultDefinition.secondaryHandler = secondaryHandler_volume;

    return resultDefinition;
}

#endif