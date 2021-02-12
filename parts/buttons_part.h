#ifndef buttons_part_h
#define buttons_part_h

#include <Wire.h>
#include "../ButtonPins.h"
#define but_count 8
//#define but_count 12

int repeatStart = 1000;
int repeatPeriod = 5;
int resetPeriod = 10;

int32_t pins[but_count] = 
{
    /*
    Button11, 
    Button12, 
    Button13, 
    Button14, 
    */
    Button21, 
    Button22, 
    Button23, 
    Button24, 
    Button31, 
    Button32, 
    Button33, 
    Button34
};

long pressStartedTime[but_count] = {0};
long lastRepeatedTime[but_count] = {0};
long releasedTime[but_count] = {0};
//bool isPressed2[but_count] = {false, false, false, false, false, false};

bool buttonIsInPressedState[but_count] = {false};

// task
TaskHandle_t core0Task;

void readButtons();
void secondTask();

void core0TaskCode( void * pvParameters )
{
    Serial.print("core 0 task is running on core ");
    Serial.println(xPortGetCoreID());

    for(;;)
    {
        //vTaskDelay(10);
        //delay(20);
        readButtons();
        secondTask();
    } 
}

void numberedButtonHandler(int32_t button);

void buttonsSetup()
{
    for(int i = 0; i<but_count; i++)
    {

        pinMode(pins[i], INPUT_PULLUP);
        buttonIsInPressedState[i] = false;
    }

    //for(int i = 0; i<but_count; i++)

    xTaskCreatePinnedToCore(
                        core0TaskCode,      // Task function.
                        "core0Task",        // name of task.
                        10000,              // Stack size of task 
                        NULL,               // parameter of the task
                        0,                  // priority of the task 
                        &core0Task,         // Task handle to keep track of created task 
                        0);                 // pin task to core 0 
}

void readButtons()
{
    long time = millis();
    int vals[but_count] = {0};
    bool needToFireEvent[but_count];

    for(int i = 0; i<but_count; i++)
    {
        vals[i] = digitalRead(pins[i]);
        needToFireEvent[i] = false;
    }

    vals[0] = HIGH;
/*j
     = {false, false, false, false, false, false, 
                                        false, false, false, false, false, false};
*/
    for(int i = 0; i < but_count; i++)
    {
        if (vals[i] != HIGH) 
        {
            // pressed
            if(buttonIsInPressedState[i] || (time - releasedTime[i] < resetPeriod))
            {
                // been pressed before, or didn't release for long enough time
                buttonIsInPressedState[i] = true;;
                if(time - pressStartedTime[i] > repeatStart && time - lastRepeatedTime[i] > repeatPeriod)
                {
                    // it's time to start repeating behaviour and repeat time have come
                    lastRepeatedTime[i] = time;
                    needToFireEvent[i] = true;
                    //Serial.println("repeated " + String(i));
                }
            }
            else
            {
                // pressed for the first time
                buttonIsInPressedState[i] = true;
                pressStartedTime[i] = time;
                lastRepeatedTime[i] = 0;
                releasedTime[i] = 0;
                needToFireEvent[i] = true;
                //Serial.println("first " + String(i));
            }
        }
        else
        {
            // not pressed
/*
            // debugging version
            if(!buttonIsInPressedState[i])
            {
                // already for some time
                if(isPressed2[i])
                    Serial.println("not pressed " + String(i));
                isPressed2[i] = false;
            }
            else
            {
                // just released
                isPressed2[i] = true;
                Serial.println("after last " + String(i));
                releasedTime[i] = time;
            }
*/
            if(buttonIsInPressedState[i])
                releasedTime[i] = time;

            buttonIsInPressedState[i] = false;
        }
    }

    for(int i = 0; i<but_count; i++)
    {
        if(i == 0)
            continue;
        if(needToFireEvent[i])
            numberedButtonHandler(pins[i]);
            //handlers[i]();
    }
}

#endif