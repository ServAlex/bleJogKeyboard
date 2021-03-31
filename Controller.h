#ifndef CONTROLLER_H
#define CONTROLLER_H

#include "Logger.h"
#include "ExecutionController.h"
#include "ModeSelector.h"
#include "View.h"
#include "ViewModel.h"
#include "modes_classes/IMode.h"
#include "modes_classes/Action.h"
#include "IRefresher.h"
#include "IStateChangeWatcher.h"
#include "SensorController.h"

class Controller: IRefresher, IStateChangeWatcher
{
    private: 
        Logger* logger;
        ExecutionController* executionController;
        ModeSelector* modeSelector;
        View* view;
        ViewModel* viewModel;
        SensorController* sensorController;

        void FillViewModel();
        
    public:
        Controller(Logger* aLogger, 
            ExecutionController* anExecutionController, 
            ModeSelector* aModeSelector, 
            View* aView, 
            ViewModel* aViewModel, 
            SensorController* aSensorController);
        void ButtonPressed(int32_t pinNumber);
        void EncderChanged(int32_t newValue, int32_t diff);
        void VoltageChanged(float voltage, float chargePortion);
        void IsConnectedChanged(bool isConnected);
        void RegularUpdate();

        void FullRefresh()
        {
            logger->Log("refresh requested");
            FillViewModel();
            view->fullRedraw(viewModel);
        }
};

#endif