
// downloaded https://github.com/ServAlex/ESP32-BLE-Combo and manually extracted to a library folder next to fastled
//#include "BleKeyboard.h"
// moved #include "BleCombo.h"

// my libs
#include "parts/buttons_part.h"
//#include "wifi_part.h"
//#include "led_part.h"
#include "parts/encoder_part.h"
//#include "parts/display_part.h"

#include "modes_classes/IMode.h"
#include "modes_classes/ArrowsXMode.h"
#include "modes_classes/ArrowsYMode.h"
#include "modes_classes/MouseXMode.h"
#include "modes_classes/MouseYMode.h"
#include "modes_classes/MouseScrollXMode.h"
#include "modes_classes/MouseScrollYMode.h"

#include "modes_classes/AltTabMode.h"
#include "modes_classes/TabSwitchMode.h"
#include "modes_classes/VolumeMode.h"
#include "modes_classes/ZoomMode.h"
#include "modes_classes/UndoMode.h"
#include "modes_classes/MouseDragXMode.h"
#include "modes_classes/MouseDragYMode.h"

#include "modes_classes/FusionOrbitXMode.h"
#include "modes_classes/FusionOrbitYMode.h"
#include "modes_classes/FusionOrbitXYMode.h"
#include "modes_classes/FusionOrbitXYInvertedMode.h"

#include "modes_classes/ModeSelectionMode.h"

#include "Controller.h"

uint32_t lastUpdated = 0;

Controller* controller;

void setup()
{
    delay(1000);

    Logger* logger = new Logger();

    int32_t modesCount = 30;
    int32_t activeIndex = 0;

    IMode** modes = (IMode**)malloc(modesCount*sizeof(IMode*));
    IMode* modeSelectionMode = new ModeSelectionMode(logger);
    ModeSelector* modeSelector = new ModeSelector(logger, modes, 13, modeSelectionMode);

    modes[activeIndex++] = modeSelector->volumeMode = new VolumeMode(logger);

    modes[activeIndex++] = modeSelector->altTabMode = new AltTabMode(logger);
    modes[activeIndex++] = modeSelector->tabSwitchMode =  new TabSwithcMode(logger);
    modes[activeIndex++] = modeSelector->zoomMode = new ZoomMode(logger);
    modes[activeIndex++] = modeSelector->undoMode = new UndoMode(logger);

    modes[activeIndex++] = modeSelector->arrowsXMode = new ArrowsXMode(logger);
    modes[activeIndex++] = modeSelector->arrowsYMode = new ArrowsYMode(logger);
    modes[activeIndex++] = modeSelector->mouseXMode = new MouseXMode(logger);
    modes[activeIndex++] = modeSelector->mouseYMode = new MouseYMode(logger);
    modes[activeIndex++] = modeSelector->mouseDragXMode = new MouseDragXMode(logger);
    modes[activeIndex++] = modeSelector->mouseDragYMode = new MouseDragYMode(logger);
    modes[activeIndex++] = modeSelector->mouseScrollXMode = new MouseScrollXMode(logger);
    modes[activeIndex++] = modeSelector->mouseScrollYMode = new MouseScrollYMode(logger);

/*
    modes[activeIndex++] = modeSelector->fusionOrbitXMode = new FusionOrbitXMode(logger);
    modes[activeIndex++] = modeSelector->fusionOrbitYMode = new FusionOrbitYMode(logger);
    modes[activeIndex++] = new FusionOrbitXYMode(logger);
    modes[activeIndex++] = new FusionOrbitXYInvertedMode(logger);
*/


    ExecutionController* executionController = new ExecutionController(logger, modeSelector);
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

    delay(200);
}

void secondTask()
{
    encoderLoop();
    // probably let the mode execute some regular action
    controller->RegularUpdate();
    //modes[activeMode].fastLoopHandler(Keyboard, Mouse);
    vTaskDelay(10);
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

void numberedButtonHandler(int32_t button)
{
    controller->ButtonPressed(button);
}
/*
void button1PresHandler()
{
    controller->ButtonPressed(0);
}

void button2PresHandler()
{
    controller->ButtonPressed(35);
}
*/