#ifndef SensorController_h
#define SensorController_h

#include "Logger.h"
#include "SensorsModel.h"
#include "IStateChangeWatcher.h"

class SensorController
{
    private:
        Logger* logger;
        SensorsModel* sensorsModel;
        IStateChangeWatcher* stateChangeWatcher;

    public:
        SensorController(Logger* logger, SensorsModel* model);
        void RegularUpdate();
        void SetStateChangeWatcher(IStateChangeWatcher* watcher);
};

#endif