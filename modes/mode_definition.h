#ifndef mode_definition_h
#define mode_definition_h

#include <Wire.h>
#include "BleCombo.h"

typedef String (*ModeShortName)();
typedef void (*EncoderScrollHandler)(BleComboKeyboard Keyboard, BleComboMouse Mouse, int32_t delta);
typedef void (*EncoderClickHandler)(BleComboKeyboard Keyboard, BleComboMouse Mouse);
typedef void (*PrimaryHandler)(BleComboKeyboard Keyboard, BleComboMouse Mouse);
typedef void (*SecondaryHandler)(BleComboKeyboard Keyboard, BleComboMouse Mouse);

struct ModeDefinition
{
    ModeShortName modeShortName;
    EncoderScrollHandler encoderScrollHandler;
    EncoderClickHandler encoderClickHandler;
    PrimaryHandler primaryHandler;
    SecondaryHandler secondaryHandler;
} mode_definition;

#endif