#ifndef undo_mode_h
#define undo_mode_h

#include "mode_definition.h"
#include "BleCombo.h"

bool undo_unix_style = true;

void encoderScrollHandler_undo(BleComboKeyboard Keyboard, BleComboMouse Mouse, int32_t d)
{
    if(Keyboard.isConnected())
    {
        Keyboard.press(KEY_LEFT_CTRL);
        if(d>0 && undo_unix_style)
        {
            Keyboard.press(KEY_LEFT_SHIFT);
        }
        
        for(int i = 0; i<abs(d); i++)
        {
            Keyboard.write((d>0 && !undo_unix_style)?'y':'z');
        }
        Keyboard.releaseAll();
    }
}

void encoderClickHandler_undo(BleComboKeyboard Keyboard, BleComboMouse Mouse)
{
    if(Keyboard.isConnected())
    {
    }
}

void primaryHandler_undo(BleComboKeyboard Keyboard, BleComboMouse Mouse)
{
    if(Keyboard.isConnected())
    {
        undo_unix_style = !undo_unix_style;
    }
}

void secondaryHandler_undo(BleComboKeyboard Keyboard, BleComboMouse Mouse)
{
    if(Keyboard.isConnected())
    {
    }
}

void fastLoopHandler_undo(BleComboKeyboard Keyboard, BleComboMouse Mouse)
{
}

String modeShortName_undo()
{
    return String("undo ") + (undo_unix_style?"u":"ms");
}

ModeDefinition undo_mode_definition()
{
    ModeDefinition resultDefinition;
    resultDefinition.modeShortName = modeShortName_undo;
    resultDefinition.encoderScrollHandler = encoderScrollHandler_undo;
    resultDefinition.encoderClickHandler = encoderClickHandler_undo;
    resultDefinition.primaryHandler = primaryHandler_undo;
    resultDefinition.secondaryHandler = secondaryHandler_undo;
    resultDefinition.fastLoopHandler = fastLoopHandler_undo;

    return resultDefinition;
}

#endif