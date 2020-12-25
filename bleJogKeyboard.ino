
// downloaded https://github.com/T-vK/ESP32-BLE-Keyboard and manually extracted to a library folder next to fastled
#include "BleKeyboard.h"

// my libs
#include "display_part.h"
#include "buttons_part.h"
//#include "wifi_part.h"
//#include "led_part.h"
#include "encoder_part.h"

BleKeyboard bleKeyboard;

int currentMenu = 0;
int menuCount = 3;

uint8_t continuousUpdate = 0;

void cycleOption(int dir)
{
    switch (currentMenu)
    {
    case 0:
        /*
            if(dir==-1)
            else
            */
        break;
    case 1:
        break;
    case 2:

        //Serial.println(brightness*brightnessMultiplier + 3);
        break;
    default:
        break;
    }
}

void button1PresHandler()
{
    //cycleOption(1);
    currentMenu = ++currentMenu % menuCount;
    report();
}

void button2PresHandler()
{
    currentMenu = ++currentMenu % menuCount;
    report();
}

void buttonUpPresHandler()
{
    currentMenu = (--currentMenu + menuCount) % menuCount;
    report();
}
void buttonDownPresHandler()
{
    currentMenu = ++currentMenu % menuCount;
    report();
}
void buttonLeftPresHandler()
{
    //Serial.println("button");
    cycleOption(-1);
    report();
}
void buttonRightPresHandler()
{
    //Serial.println("button");
    cycleOption(1);
    report();
}

void buttonEncoderPresHandler()
{
    //currentMenu = ++currentMenu % menuCount;
    //report();

    if(bleKeyboard.isConnected())
    {
        Serial.println("mute");
        bleKeyboard.write(KEY_MEDIA_MUTE);
    }
}

void encoderChanged(int dir)
{
    /*
    cycleOption(dir > 0 ? 1 : -1);
    */

    Serial.println("d " + String(dir) + " enc " + String(encoderValue) + " amp " + String(encoderValueAmplified) + " ampD " + String(encoderDeltaAmplified));

    if(dir != 0 && bleKeyboard.isConnected())
    {
        if(dir > 0)
        {
            Serial.println("volume up");
            bleKeyboard.write(KEY_MEDIA_VOLUME_UP);
        }
        else
        {
            Serial.println("volume down");
            bleKeyboard.write(KEY_MEDIA_VOLUME_DOWN);
        }
    }

    //report();
}

//void bothButtonsPressHandler() {}

uint32_t lastUpdated = 0;
/*
void report()
{
    Serial.println("encoder " + String(encoder.getCount()) + " " + String(encoder.getCountRaw()));
}
*/


void report()
{
    uint32_t color = TFT_RED;
    //if(battery_voltage>3.4)
    //    color = TFT_YELLOW;
    //if(battery_voltage>3.9)
    //    color = TFT_GREEN;
    //if(battery_voltage>4.26)
    //    color = TFT_BLUE;

    tft.setTextColor(TFT_GREEN, TFT_BLACK);
    int d = 25;
    clearScreen();

    drawStringWithOffset("line 1", 0, -2*d);
    drawStringWithOffset("line 2", 0, -d);
    drawStringWithOffset("encoder " + String(encoderValue), 0, 0);
    //drawStringWithOffset(, 0, d);
    
    //drawStringWithOffset("Voltage " + String(battery_voltage), 0, 2*d);
    //tft.drawRoundRect(2, tft.height() - 7, tft.width()-2*2, 7, 4, color);
    //tft.fillRoundRect(5, tft.height() - 5, 4 + (tft.width()-5*2-4)*percentage, 3, 2, color);
    

    tft.fillCircle(5, tft.height()/2-d*2 + currentMenu*d, 3, TFT_GREEN);
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

    bleKeyboard.begin();

    report();
    delay(200);
}

void secondTask()
{
    encoderLoop();
    uint32_t time = millis();
    if (time - lastUpdated > 10000)
    {
        report();
        lastUpdated = time;
    }
}

void loop()
{
    //encoderLoop();
    //    Serial.print(" " + String(encoder.getCount()) );
    //delay(20);
    vTaskDelay(10);
}
