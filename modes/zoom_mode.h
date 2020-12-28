#ifndef zoom_mode_h
#define zoom_mode_h

#include "mode_definition.h"
#include "BleCombo.h"

void encoderScrollHandler_zoom(BleComboKeyboard Keyboard, BleComboMouse Mouse, int32_t d)
{
    if(Keyboard.isConnected())
    {
        Keyboard.press(KEY_LEFT_CTRL);
        Mouse.move(0, 0, char(d), 0);
        Keyboard.release(KEY_LEFT_CTRL);
    }
}

void encoderClickHandler_zoom(BleComboKeyboard Keyboard, BleComboMouse Mouse)
{

}

void primaryHandler_zoom(BleComboKeyboard Keyboard, BleComboMouse Mouse)
{
    //Keyboard.write(KEY_MEDIA_MUTE);
}

void secondaryHandler_zoom(BleComboKeyboard Keyboard, BleComboMouse Mouse)
{

}

String modeShortName_zoom()
{
    return "zoom";
}

ModeDefinition zoom_mode_definition()
{
    ModeDefinition resultDefinition;
    resultDefinition.modeShortName = modeShortName_zoom;
    resultDefinition.encoderScrollHandler = encoderScrollHandler_zoom;
    resultDefinition.encoderClickHandler = encoderClickHandler_zoom;
    resultDefinition.primaryHandler = primaryHandler_zoom;
    resultDefinition.secondaryHandler = secondaryHandler_zoom;

    return resultDefinition;
}

#endif