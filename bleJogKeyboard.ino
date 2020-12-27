
// downloaded https://github.com/T-vK/ESP32-BLE-Keyboard and manually extracted to a library folder next to fastled
//#include "BleKeyboard.h"
#include "BleCombo.h"

// my libs
#include "display_part.h"
#include "buttons_part.h"
//#include "wifi_part.h"
//#include "led_part.h"
#include "encoder_part.h"

/*
BleComboKeyboard keyboard;
BleComboMouse mouse(&keyboard);
*/
//BleKeyboard bleKeyboard;

enum Mode
{
    volume_control,
    mouse_x,
    mouse_y,
    mouse_scroll_x,
    mouse_scroll_y,
    arrows_x,
    arrows_y
};

int32_t ModesCount = 7;

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
    drawLeftAlignedStringWithOffset(modeToName(currentMode),               secondColumnStart, 5 + 1*d);
    drawLeftAlignedStringWithOffset(String(encoderValue),                  secondColumnStart, 5 + 2*d);

    //tft.fillCircle(5, tft.height()/2-d*2 + currentMenu*d, 3, TFT_GREEN);
    tft.fillCircle(5, 15 + currentMenu*d, 3, TFT_GREEN);
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
    Keyboard.begin();
    Mouse.begin();

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


String modeToName(Mode mode)
{
    switch (currentMode)
    {
        case volume_control:
            return "volume";
            break;

        case mouse_x:
            return "mouse x";
            break;

        case mouse_y:
            return "mouse y";
            break;

        case mouse_scroll_x:
            return "scroll x";
            break;

        case mouse_scroll_y:
            return "scroll y";
            break;

        case arrows_x:
            return "arrows x";
            break;

        case arrows_y:
            return "arrows y";
            break;

        default:
            return "Error";
            break;
    }
    return "Error";
}

void encoderChanged(int dir)
{
    //Serial.println("d " + String(dir) + " enc " + String(encoderValue) + " amp " + String(encoderValueAmplified) + " ampD " + String(encoderDeltaAmplified));
    Serial.println("enc " + String(dir) + " amp " + String(encoderDeltaAmplified) + " connected " + String(Keyboard.isConnected()) + " mode " + String(currentMode));

    if(dir != 0 && Keyboard.isConnected())
    {
        switch (currentMode)
        {
            case volume_control:
                Serial.println("volume " + (dir>0)?"up":"down");
                for(int i = 0; i<abs(encoderDeltaAmplified); i++)
                {
                    Keyboard.write(dir > 0?KEY_MEDIA_VOLUME_UP:KEY_MEDIA_VOLUME_DOWN);
                }
                break;

            case mouse_x:
                Serial.println("move x");
                Mouse.move(char(encoderDeltaAmplified), 0, 0, 0);
                break;

            case mouse_y:
                Serial.println("move y");
                Mouse.move(0, char(encoderDeltaAmplified), 0, 0);
                break;

            case mouse_scroll_x:
                Serial.println("scroll horizontaly");
                Mouse.move(0, 0, char(encoderDeltaAmplified), 0);
                break;

            case mouse_scroll_y:
                Serial.println("scroll verticaly");
                Mouse.move(0, 0, 0, char(encoderDeltaAmplified));
                break;

            case arrows_x:
                Serial.println("horizontal arrows");
                for(int i = 0; i<abs(encoderDeltaAmplified); i++)
                {
                    Keyboard.write(dir > 0?KEY_RIGHT_ARROW:KEY_LEFT_ARROW);
                }
                break;

            case arrows_y:
                Serial.println("vertical arrows");
                for(int i = 0; i<abs(encoderDeltaAmplified); i++)
                {
                    Keyboard.write(dir > 0?KEY_UP_ARROW:KEY_DOWN_ARROW);
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

    if(Keyboard.isConnected())
    {
        Serial.println(", mute sent");
        Keyboard.write(KEY_MEDIA_MUTE);
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
    // left mouse click
    Mouse.click(MOUSE_LEFT);
}
void buttonDownPresHandler()
{
    Serial.println("down");
    // switch mode back
    currentMode = (Mode)((currentMode+ModesCount-1)%ModesCount);
    resetEncoder();
}
void buttonLeftPresHandler()
{
    Serial.println("left");
    // right mouse click
    Mouse.click(MOUSE_RIGHT);
}
void buttonRightPresHandler()
{
    Serial.println("right");
    // switch mode
    currentMode = (Mode)((currentMode+1)%ModesCount);
    resetEncoder();
}
