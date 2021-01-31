#include "ExecutionController.h"

ExecutionController::ExecutionController(Logger* aLogger)
{
    this->logger = aLogger;

    Keyboard.begin();
    Mouse.begin();
}

void ExecutionController::ExecuteAction(Action action, int32_t parameter)
{
    logger->Log("executing action " + String(action));
    if(!Keyboard.isConnected())
    {
        logger->Log("not connected");
        return;
    }

    switch(action)
    {
        case ModeSelectionEncoderAction:
            break;

        case ArrowsXEncoderAction:
        {
            const uint8_t key = parameter > 0 ? KEY_RIGHT_ARROW : KEY_LEFT_ARROW;
            for(int i = 0; i<abs(parameter); i++)
            {
                Keyboard.write(key);
            }
            break;
        }
        case ArrowsYEncoderAction:
        {
            const uint8_t key = parameter > 0 ? KEY_UP_ARROW : KEY_DOWN_ARROW;
            for(int i = 0; i<abs(parameter); i++)
            {
                Keyboard.write(key);
            }
            break;
        }
        case MouseXEncoderAction:
        {
            Mouse.move(char(parameter), 0, 0, 0);
            break;
        }
        case MouseYEncoderAction:
        {
            Mouse.move(0, char(parameter), 0, 0);
            break;
        }
        case MouseScrollXEncoderAction:
        {
            Mouse.move(0, 0, 0, char(parameter));
            break;
        }
        case MouseScrollYEncoderAction:
        {
            Mouse.move(0, 0, -char(parameter), 0);
            break;
        }
        default:
            break;
    }
}
