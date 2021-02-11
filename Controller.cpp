#include "Controller.h"

Controller::Controller(Logger* aLogger, 
                        ExecutionController* anExecutionController, 
                        ModeSelector* aModeSelector, 
                        View* aView,
                        ViewModel* aViewModel)
{
    this->logger = aLogger;
    this->executionController = anExecutionController;
    this->modeSelector = aModeSelector;
    this->view = aView;
    this->viewModel = aViewModel;
    this->viewModel->encoderValue = 0;

    FillViewModel();
    view->fullRedraw(viewModel);
}

void Controller::ButtonPressed(int32_t pinNumber)
{
    IMode* mode = modeSelector->getCurrentMode();
    Action action = mode->ActionNameForButton(pinNumber);

    switch (action)
    {
        case StartModeSelection:
            logger->Log("button for mode selection");
            modeSelector->switchToSelectionMode();
            FillViewModel();
            view->fullRedraw(viewModel);
            // todo: start timer?
            break;

        case ConfirmModeSelection:
            logger->Log("button for confirming mode selection");
            modeSelector->completeSelectionMode();
            FillViewModel();
            view->fullRedraw(viewModel);
            break;

        case None:
            logger->Log("Controller button with no action");

            break;
        default:
            logger->Log("Controller button for action " + String(action));
            executionController->ExecuteAction(action, 0);
            break;
    }
}

void Controller::EncderChanged(int32_t newValue, int32_t diff)
{
    Action action = modeSelector->getCurrentMode()->ActionNameForEncoder();

    switch(action)
    {
        case ModeSelectionEncoderAction:
            logger->Log("switch to diffirent mode " + String(diff));
            for(int i = 0; i < abs(diff); ++i)
            {
                if(diff>0)
                {
                    modeSelector->switchToNextMode();
                }
                else
                {
                    modeSelector->switchToPreviousMode();
                }

                //update view model
                viewModel->encoderValue = newValue;
                viewModel->isInModeSelectionMode = true;
                FillViewModel();
                view->fullRedraw(viewModel);
            }
            break;

        case ArrowsXEncoderAction:
            logger->Log("scroll mouse horizontally");

                viewModel->encoderValue = newValue;
                viewModel->isInModeSelectionMode = true;
                executionController->ExecuteAction(action, diff);
                FillViewModel();
                view->fullRedraw(viewModel);
            break;

        default:
            logger->Log("Controller encoder for action " + String(action));
            executionController->ExecuteAction(action, diff);
            break;
    }
}

void Controller::RegularUpdate()
{
    Action action = modeSelector->getCurrentMode()->ActionNameForEncoder();
    executionController->TryActionCompletion(action);
}

void Controller::FillViewModel()
{
    viewModel->isInModeSelectionMode = modeSelector->isInSelectionMode();
    //viewModel->encoderValue = newValue;
    viewModel->modeIndex = modeSelector->getCurrentModeIndex() + 1;
    viewModel->modesCount = modeSelector->getModesCount();
    viewModel->modeName = modeSelector->getSelectedMode()->GetName();
    viewModel->nextModeName = "next";
    viewModel->previousModeName = "prev";
}