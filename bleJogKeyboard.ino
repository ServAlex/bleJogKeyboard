
// downloaded https://github.com/ServAlex/ESP32-BLE-Combo and manually extracted to a library folder next to fastled
//#include "BleKeyboard.h"
// moved #include "BleCombo.h"

// my libs
#include "parts/buttons_part.h"
//#include "wifi_part.h"
//#include "led_part.h"
#include "parts/encoder_part.h"
//#include "parts/display_part.h"
/*
#include "Logger.h"
#include "ExecutionController.h"
#include "ModeSelector.h"
#include "ViewModel.h"
#include "View.h"
*/

#include "modes_classes/IMode.h"
#include "modes_classes/ArrowsXMode.h"
#include "modes_classes/ArrowsYMode.h"
#include "modes_classes/ModeSelectionMode.h"
#include "Controller.h"

uint32_t lastUpdated = 0;

Controller* controller;

void setup()
{
    delay(1000);

    int32_t modesCount = 2;
    int32_t activeIndex = 0;
    IMode** modes = (IMode**)malloc(modesCount*sizeof(IMode*));
    modes[activeIndex++] = new ArrowsXMode();
    modes[activeIndex++] = new ArrowsYMode();
    IMode* modeSelectionMode = new ModeSelectionMode();

    Logger* logger = new Logger();
    ExecutionController* executionController = new ExecutionController(logger);
    ModeSelector* modeSelector = new ModeSelector(logger, modes, modesCount, modeSelectionMode);
    View* view = new View(logger);
    ViewModel* viewModel = new ViewModel();

    controller = new Controller(logger, 
                            executionController,
                            modeSelector,
                            view,
                            viewModel);

    lastUpdated = millis();

    buttonsSetup();
    encoderSetup();

    //bleKeyboard.begin();
    Keyboard.begin();
    Mouse.begin();

    delay(200);
}

void secondTask()
{
    encoderLoop();
    // probably let the mode execute some regular action

    //modes[activeMode].fastLoopHandler(Keyboard, Mouse);
    //vTaskDelay(10);
}

void loop()
{
    //encoderLoop();
    uint32_t time = millis();
    if (time - lastUpdated > 50)
    {
        //report_regular();
        /*
        if(report_needed)
        {
            report_on_demand();
        }
        */
        lastUpdated = time;
        vTaskDelay(10); // while there are no actions in this if
    }
    else
    {
        vTaskDelay(10);
    }
}

void encoderChanged(int32_t dir)
{
    /*
    Serial.println("enc " + String(dir) + " amp " + String(encoderDeltaAmplified) + " connected " + String(Keyboard.isConnected()) + " mode " + String(activeMode));
    modes[activeMode].encoderScrollHandler(Keyboard, Mouse, encoderDeltaAmplified);
    report_needed = true;
    */
    controller->EncderChanged(encoderValue, encoderDeltaAmplified);
    return;
    //report();
}

// buttons

void buttonEncoderPresHandler()
{
    //controller->ButtonPressed(asdf;lkj);
}

void button1PresHandler()
{
    controller->ButtonPressed(0);
}

void button2PresHandler()
{
    controller->ButtonPressed(35);
}

void buttonUpPresHandler()
{
    //controller->ButtonPressed();
}
void buttonDownPresHandler()
{
    //controller->ButtonPressed();
}
void buttonLeftPresHandler()
{
    //controller->ButtonPressed();
}
void buttonRightPresHandler()
{
    //controller->ButtonPressed();
}
