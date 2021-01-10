
// downloaded https://github.com/ServAlex/ESP32-BLE-Combo and manually extracted to a library folder next to fastled
//#include "BleKeyboard.h"
#include "BleCombo.h"

// my libs
#include "display_part.h"
#include "buttons_part.h"
//#include "wifi_part.h"
//#include "led_part.h"
#include "encoder_part.h"

#include "modes/mode_definition.h"

#include "modes/volume_mode.h"                // 1
#include "modes/zoom_mode.h"                  // 2
#include "modes/mouse_x_mode.h"               // 3
#include "modes/mouse_y_mode.h"               // 4
#include "modes/mouse_scroll_x_mode.h"        // 5
#include "modes/mouse_scroll_y_mode.h"        // 6
#include "modes/arrows_vertical_mode.h"       // 7
#include "modes/arrows_horizontal_mode.h"     // 8
#include "modes/undo_mode.h"                  // 9
#include "modes/tab_switch_mode.h"            // 10
#include "modes/mouse_drag_x_mode.h"          // 11
#include "modes/mouse_drag_y_mode.h"          // 12

const int32_t ModesCount = 100;
ModeDefinition modes[ModesCount];
int32_t activeMode;
int32_t filledModesCount = 0;

int currentMenu = 0;
int menuCount = 3;

uint32_t lastUpdated = 0;

void reportSetup()
{
    tft.setTextColor(TFT_GREEN, TFT_BLACK);
    tft.setTextDatum(TL_DATUM);

    int d = 25;

    drawLeftAlignedStringWithOffset("connect",      20, 5 + 0*d);
    drawLeftAlignedStringWithOffset("mode",         20, 5 + 1*d);
    drawLeftAlignedStringWithOffset("encoder",      20, 5 + 2*d);
}

void report()
{
    int d = 25;
    int secondColumnStart = 140;
    //clearScreen();
    clearRect(0, 0, 10, tft.height());
    clearRect(secondColumnStart, 0, tft.width() - secondColumnStart, tft.height());
    
    drawLeftAlignedStringWithOffset(String(Keyboard.isConnected()),        secondColumnStart, 5 + 0*d);
    drawLeftAlignedStringWithOffset(modes[activeMode].modeShortName(),     secondColumnStart, 5 + 1*d);
    drawLeftAlignedStringWithOffset(String(encoderValue),                  secondColumnStart, 5 + 2*d);

    //tft.fillCircle(5, tft.height()/2-d*2 + currentMenu*d, 3, TFT_GREEN);
    tft.fillCircle(5, 15 + currentMenu*d, 3, TFT_GREEN);
}

void setup()
{
    delay(1000);

    filledModesCount = 0;
    modes[filledModesCount++] = volume_mode_definition();
    modes[filledModesCount++] = zoom_mode_definition();
    modes[filledModesCount++] = mouse_x_mode_definition();
    modes[filledModesCount++] = mouse_y_mode_definition();
    modes[filledModesCount++] = mouse_drag_x_mode_definition();
    modes[filledModesCount++] = mouse_drag_y_mode_definition();
    modes[filledModesCount++] = mouse_scroll_x_mode_definition();
    modes[filledModesCount++] = mouse_scroll_y_mode_definition();
    modes[filledModesCount++] = arrows_horizontal_mode_definition();
    modes[filledModesCount++] = arrows_vertical_mode_definition();
    modes[filledModesCount++] = tab_switch_mode_definition();
    modes[filledModesCount++] = undo_mode_definition();

    activeMode = 0;

    Serial.begin(115200);
    Serial.println("Start");

    lastUpdated = millis();

    displaySetup();
    buttonsSetup();
    encoderSetup();
    reportSetup();

    //bleKeyboard.begin();
    Keyboard.begin();
    Mouse.begin();

    report();
    delay(200);
}

void secondTask()
{
    encoderLoop();
    modes[activeMode].fastLoopHandler(Keyboard, Mouse);
    //vTaskDelay(10);
}

void loop()
{
    //encoderLoop();
    uint32_t time = millis();
    if (time - lastUpdated > 50)
    {
        report();
        lastUpdated = time;
    }
    else
    {
        vTaskDelay(10);
    }
}


void encoderChanged(int32_t dir)
{
    //Serial.println("d " + String(dir) + " enc " + String(encoderValue) + " amp " + String(encoderValueAmplified) + " ampD " + String(encoderDeltaAmplified));
    Serial.println("enc " + String(dir) + " amp " + String(encoderDeltaAmplified) + " connected " + String(Keyboard.isConnected()) + " mode " + String(activeMode));

    modes[activeMode].encoderScrollHandler(Keyboard, Mouse, encoderDeltaAmplified);
    return;
    //report();
}

// buttons

void buttonEncoderPresHandler()
{
    modes[activeMode].encoderClickHandler(Keyboard, Mouse);
}

void button1PresHandler()
{
    /*
    Serial.println("button 1");
    currentMenu = ++currentMenu % menuCount;
    report();
    */

    Serial.println("button 1 - prev menu");
    // switch mode back
    activeMode = (activeMode + filledModesCount - 1)%filledModesCount;
    resetEncoder();
}

void button2PresHandler()
{
    /*
    Serial.println("button 2");
    currentMenu = ++currentMenu % menuCount;
    report();
    */

    Serial.println("button 2 - next menu");
    // switch mode
    activeMode = (activeMode + 1)%filledModesCount;
    resetEncoder();
}

void buttonUpPresHandler()
{
    Serial.println("up");
    modes[activeMode].primaryHandler(Keyboard, Mouse);
}
void buttonDownPresHandler()
{
    Serial.println("down");
    // switch mode back
    activeMode = (activeMode + filledModesCount - 1)%filledModesCount;
    resetEncoder();
}
void buttonLeftPresHandler()
{
    Serial.println("left");
    modes[activeMode].secondaryHandler(Keyboard, Mouse);
}
void buttonRightPresHandler()
{
    Serial.println("right");
    // switch mode
    activeMode = (activeMode + 1)%filledModesCount;
    resetEncoder();
}
