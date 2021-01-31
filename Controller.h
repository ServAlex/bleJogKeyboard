#ifndef CONTROLLER_H
#define CONTROLLER_H

#include "Logger.h"
#include "ExecutionController.h"
#include "ModeSelector.h"
#include "View.h"
#include "ViewModel.h"
#include "modes_classes/IMode.h"
#include "modes_classes/Action.h"

class Controller
{
    private: 
        Logger* logger;
        ExecutionController* executionController;
        ModeSelector* modeSelector;
        View* view;
        ViewModel* viewModel;

        void FillViewModel();
        
    public:
        Controller(Logger* aLogger, ExecutionController* anExecutionController, ModeSelector* aModeSelector, View* aView, ViewModel* aViewModel);
        void ButtonPressed(int32_t pinNumber);
        void EncderChanged(int32_t newValue, int32_t diff);
};

#endif