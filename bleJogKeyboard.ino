
// downloaded https://github.com/T-vK/ESP32-BLE-Keyboard and manually extracted to a library folder next to fastled
//#include "BleKeyboard.h"
#include "BleCombo.h"

// my libs
#include "display_part.h"
#include "buttons_part.h"
//#include "wifi_part.h"
//#include "led_part.h"
#include "encoder_part.h"


BleComboKeyboard keyboard;
BleComboMouse mouse(&keyboard);

//BleKeyboard bleKeyboard;

enum Mode
{
    volume_control,
    mouse_x,
    mouse_y,
    mouse_scroll,
    arrows_x,
    arrows_y
};

int32_t ModesCount = 6;

//Mode currentMode = arrows_y;
//Mode currentMode = mouse_y;
Mode currentMode = volume_control;
//Mode currentMode = mouse_scroll;

int currentMenu = 0;
int menuCount = 3;

uint8_t continuousUpdate = 0;


void setMode(Mode modeToSet)
{
    Serial.println("set mode to " + modeToSet);
    currentMode = modeToSet;
    report();
}

uint32_t lastUpdated = 0;
/*
void report()
{
    Serial.println("encoder " + String(encoder.getCount()) + " " + String(encoder.getCountRaw()));
}
*/

void reportSetup()
{
    tft.setTextColor(TFT_GREEN, TFT_BLACK);
    tft.setTextDatum(TL_DATUM);

    int d = 25;

    drawLeftAlignedStringWithOffset("connected",   20, 5 + 0*d);
    drawLeftAlignedStringWithOffset("mode",        20, 5 + 1*d);
    drawLeftAlignedStringWithOffset("encoder",     20, 5 + 2*d);
}

void report()
{
    int d = 25;
    //clearScreen();
    clearRect(0, 0, 10, tft.height());
    clearRect(180, 0, tft.width() - 180, tft.height());
    
    drawLeftAlignedStringWithOffset(String(keyboard.isConnected()),        180, 5 + 0*d);
    drawLeftAlignedStringWithOffset(String(currentMode),                   180, 5 + 1*d);
    drawLeftAlignedStringWithOffset(String(encoderValue),                  180, 5 + 2*d);

    //tft.fillCircle(5, tft.height()/2-d*2 + currentMenu*d, 3, TFT_GREEN);
    tft.fillCircle(5, 5 + currentMenu*d, 3, TFT_GREEN);
}

void setup()
{
    delay(1000);

    Serial.begin(115200);
    Serial.println("Start");

    lastUpdated = millis();

    displaySetup();
    buttonsSetup();
    encoderSetup();
    reportSetup();

    //bleKeyboard.begin();
//    keyboard.begin();
//    mouse.begin();


    report();
    delay(200);
}

void secondTask()
{
    encoderLoop();
    uint32_t time = millis();
    if (time - lastUpdated > 1000)
    {
        report();
        lastUpdated = time;
    }
    //vTaskDelay(10);
}

void loop()
{
    //encoderLoop();
    //    Serial.print(" " + String(encoder.getCount()) );
    //delay(20);
    vTaskDelay(10);
}






void encoderChanged(int dir)
{
    //Serial.println("d " + String(dir) + " enc " + String(encoderValue) + " amp " + String(encoderValueAmplified) + " ampD " + String(encoderDeltaAmplified));
    Serial.println("enc " + String(dir) + " amp " + String(encoderDeltaAmplified) + " connected " + String(keyboard.isConnected()) + " mode " + String(currentMode));

    if(dir != 0 && keyboard.isConnected())
    {
        switch (currentMode)
        {
        case volume_control:
            Serial.println("volume " + (dir>0)?"up":"down");
            for(int i = 0; i<abs(encoderDeltaAmplified); i++)
            {
                keyboard.write(dir > 0?KEY_MEDIA_VOLUME_UP:KEY_MEDIA_VOLUME_DOWN);
            }
            break;

        case mouse_x:
            Serial.println("move x");
            mouse.move(char(encoderDeltaAmplified), 0, 0, 0);
            break;

        case mouse_y:
            Serial.println("move y");
            mouse.move(0, char(encoderDeltaAmplified), 0, 0);
            break;

        case mouse_scroll:
            Serial.println("scroll");
            mouse.move(0, 0, char(encoderDeltaAmplified), 0);
            break;
        case arrows_y:
            Serial.println("vertical arrows");
            for(int i = 0; i<abs(encoderDeltaAmplified); i++)
            {
                keyboard.write(dir > 0?KEY_UP_ARROW:KEY_DOWN_ARROW);
            }
            break;

        default:
            Serial.println("undefined mode");
            break;
        }
    }

    //report();
}

// buttons

void buttonEncoderPresHandler()
{
    //currentMenu = ++currentMenu % menuCount;
    //report();
    Serial.println("mute pressed");

    if(keyboard.isConnected())
    {
        Serial.println(", mute sent");
        keyboard.write(KEY_MEDIA_MUTE);
    }
}

void button1PresHandler()
{
    //cycleOption(1);
    Serial.println("button 1");
    currentMenu = ++currentMenu % menuCount;
    report();
}

void button2PresHandler()
{
    Serial.println("button 2");
    currentMenu = ++currentMenu % menuCount;
    report();
}
/*
void buttonMode1PresHandler()
{
    Serial.println("butt 1");
    //setMode(Mode::volume_control);
}
void buttonMode2PresHandler()
{
    Serial.println("butt 2");
    //setMode(Mode::mouse_x);
}
void buttonMode3PresHandler()
{
    Serial.println("butt 3");
    //setMode(Mode::mouse_y);
}
void buttonMode4PresHandler()
{
    Serial.println("butt 4");
    //setMode(Mode::mouse_scroll);
}
*/

void buttonUpPresHandler()
{
    Serial.println("up");
}
void buttonDownPresHandler()
{
    Serial.println("down");
}
void buttonLeftPresHandler()
{
    Serial.println("left");
}
void buttonRightPresHandler()
{
    Serial.println("right");
    // switch mode
    currentMode = (Mode)((currentMode+1)%ModesCount);
}

