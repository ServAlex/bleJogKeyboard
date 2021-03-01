#include "ExecutionController.h"

ExecutionController::ExecutionController(Logger* aLogger, ModeSelector* aModeSelector)
{
	this->logger = aLogger;
	awaitingActionCompletion = false;
	actionCompletionWaitingStartedTime = 0;
	completionThreshold = 1000;
	modeSelector = aModeSelector;

	Keyboard.begin();
	Mouse.begin();
}

void ExecutionController::SetRefresher(IRefresher* aRefresher)
{
	refresher = aRefresher;
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
		case TabSwitchEncoder:
		{
			Awaited2KeyComboWithModifier(parameter<0, KEY_LEFT_CTRL, KEY_TAB, KEY_LEFT_SHIFT, abs(parameter), 40);
			break;
		}
		case VolumeEncoder:
		{
			const uint8_t* key = parameter>0?KEY_MEDIA_VOLUME_UP:KEY_MEDIA_VOLUME_DOWN;
			for(int i = 0; i<abs(parameter); i++)
			{
				Keyboard.write(key);
			}

			break;
		}
		case ZooomEncoder:
		{
			//if(!awaitingActionCompletion)
			Keyboard.press(KEY_LEFT_CTRL);

			Mouse.move(0, 0, char(parameter), 0);

			//Keyboard.release(KEY_LEFT_CTRL);
			completionThreshold = 1000;
			actionCompletionWaitingStartedTime = millis();
			awaitingActionCompletion = true;

			break;
		}
		case AltTabEncoder:
		{
			Awaited2KeyComboWithModifier(parameter<0, KEY_LEFT_ALT, KEY_TAB, KEY_LEFT_SHIFT, abs(parameter), 40);
			break;
		}
		case UndoEncoder:
		{
			Awaited2KeyComboWithAlternative(parameter<0, KEY_LEFT_CTRL, (uint8_t)'z', (uint8_t)'y', abs(parameter), 10);
			break;
		}
		case UndoUnixEncoder:
		{
			Awaited2KeyComboWithModifier(parameter>0, KEY_LEFT_CTRL, (uint8_t)'z', KEY_LEFT_SHIFT, abs(parameter), 10);
			break;
		}
		case MouseDragXEncoder:
		{
			Mouse.press(MOUSE_LEFT);
			Mouse.move(parameter, 0, 0);

			completionThreshold = 1000;
			actionCompletionWaitingStartedTime = millis();
			awaitingActionCompletion = true;
			break;
		}
		case MouseDragYEncoder:
		{
			Mouse.press(MOUSE_LEFT);
			Mouse.move(0, parameter, 0);

			completionThreshold = 1000;
			actionCompletionWaitingStartedTime = millis();
			awaitingActionCompletion = true;
			break;
		}
		case FusionOrbitXEncoder:
		case FusionOrbitYEncoder:
		case FusionOrbitXYEncoder:
		case FusionOrbitXYInvertedEncoder:
		{
			Keyboard.press(KEY_LEFT_SHIFT);
			Mouse.press(MOUSE_MIDDLE);
			Keyboard.release(KEY_LEFT_SHIFT);

			switch (action)
			{
				case FusionOrbitXEncoder:
					Mouse.move(parameter, 0, 0);
					break;
				case FusionOrbitYEncoder:
					Mouse.move(0, parameter, 0);
					break;
				case FusionOrbitXYEncoder:
					Mouse.move(parameter, parameter, 0);
					break;
				case FusionOrbitXYInvertedEncoder:
					Mouse.move(parameter, -parameter, 0);
					break;
			}
			//Mouse.move(parameter, 0, 0);

			completionThreshold = 400;
			actionCompletionWaitingStartedTime = millis();
			awaitingActionCompletion = true;
			break;
		}
		case MuteAction:
			Keyboard.write(KEY_MEDIA_MUTE);
			break;
		case PlayPouseAction:
			Keyboard.write(KEY_MEDIA_PLAY_PAUSE);
			break;
		case PreviousTrackAction:
			Keyboard.write(KEY_MEDIA_PREVIOUS_TRACK);
			break;
		case NextTrackAction:
			Keyboard.write(KEY_MEDIA_NEXT_TRACK);
			break;

		case SwitchUndoStyleAction:
			modeSelector->undoMode->SwitchStyle();
			refresher->FullRefresh();
			break;
		case SwithcModeToFusionXModeAction:
			modeSelector->switchToMode(modeSelector->fusionOrbitXMode);
			refresher->FullRefresh();
			break;
		case SwithcModeToFusionYModeAction:
			modeSelector->switchToMode(modeSelector->fusionOrbitYMode);
			refresher->FullRefresh();
			break;

		case SwitchMouseAxisAction:
			modeSelector->mouseMode->SwitchAxis();
			refresher->FullRefresh();
			break;
		case SwitchMouseStyleToRegularAction:
			modeSelector->mouseMode->SwitchToRegularStyle();
			refresher->FullRefresh();
			break;
		case SwitchMouseStyleToScrollAction:
			modeSelector->mouseMode->SwitchToScrollStyle();
			refresher->FullRefresh();
			break;
		case SwitchMouseStyleToDragAction:
			modeSelector->mouseMode->SwitchToDragStyle();
			refresher->FullRefresh();
			break;
		case SwitchArrowsAxisAction:
			modeSelector->arrowsMode->SwithcAxis();
			refresher->FullRefresh();
			break;

		default:
			break;
	}
}

void ExecutionController::Awaited2KeyComboWithModifier(bool positive, uint8_t baseKey, uint8_t secondaryKey, uint8_t modifierKey, int32_t times, int32_t delay)
{
	Keyboard.press(baseKey);

	if(positive)
	{
		Keyboard.press(modifierKey);
	}
	
	for(int i = 0; i < times; i++)
	{
		Keyboard.write(secondaryKey);
		vTaskDelay(delay);
	}

	if(positive)
	{
		Keyboard.release(modifierKey);
	}

	completionThreshold = 1000;
	actionCompletionWaitingStartedTime = millis();
	awaitingActionCompletion = true;
}

void ExecutionController::Awaited2KeyComboWithAlternative(bool positive, uint8_t baseKey, uint8_t secondaryKey, uint8_t reverseSecondaryKey, int32_t times, int32_t delay)
{
	Keyboard.press(baseKey);

	for(int i = 0; i < times; i++)
	{
		Keyboard.write(positive?secondaryKey:reverseSecondaryKey);
		vTaskDelay(delay);
	}

	completionThreshold = 1000;
	actionCompletionWaitingStartedTime = millis();
	awaitingActionCompletion = true;
}

void ExecutionController::TryActionCompletion(Action action)
{
	if(!awaitingActionCompletion)
	{
		return;
	}
	int32_t time = millis();
	if(time - actionCompletionWaitingStartedTime < completionThreshold)
	{
		return;
	}

	switch(action)
	{
		case TabSwitchEncoder:
		{
			Keyboard.release(KEY_LEFT_CTRL);
			break;
		}
		case ZooomEncoder:
		{
			Keyboard.release(KEY_LEFT_CTRL);
			break;
		}
		case AltTabEncoder:
		{
			Keyboard.release(KEY_LEFT_ALT);
			break;
		}
		case MouseDragXEncoder:
		{
			Mouse.release(MOUSE_LEFT);
			Mouse.click(MOUSE_LEFT);
			break;
		}
		case MouseDragYEncoder:
		{
			Mouse.release(MOUSE_LEFT);
			Mouse.click(MOUSE_LEFT);
			break;
		}
		case FusionOrbitXEncoder:
		case FusionOrbitYEncoder:
		case FusionOrbitXYEncoder:
		case FusionOrbitXYInvertedEncoder:
		{
			//Keyboard.release(KEY_LEFT_SHIFT);

			Mouse.release(MOUSE_MIDDLE);
			//Mouse.click(MOUSE_MIDDLE);
			break;
		}
		default:
		{
			Keyboard.releaseAll();
			Mouse.release(MOUSE_MIDDLE);
			Mouse.release(MOUSE_LEFT);
			Mouse.release(MOUSE_RIGHT);
			break;
		}
	}
	
	awaitingActionCompletion = false;
}
