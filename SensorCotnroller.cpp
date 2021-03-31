#include "SensorController.h"
#include "parts/sensors_part.h"

float lastSentVoltage;
float voltageDifferenceThreshold;

SensorController::SensorController(Logger* logger, SensorsModel* model)
{
    this->logger = logger;
    this->sensorsModel = model;

    sensorsConfig.voltage_active = true;
    voltageDifferenceThreshold = 0.5;
    lastSentVoltage = 3.8;

    sensorsSetup(sensorsConfig);
}

void SensorController::RegularUpdate()
{
    pollSensors();

    sensorsModel->voltage = battery_voltage;
    sensorsModel->batteryPercentage = battery_percentage;

    if(abs(lastSentVoltage - sensorsModel->voltage)>voltageDifferenceThreshold)
    {
        logger->Log("sent new voltage " + String(battery_voltage));
        lastSentVoltage = sensorsModel->voltage;
        stateChangeWatcher->VoltageChanged(sensorsModel->voltage, sensorsModel->batteryPercentage);
    }
}

void SensorController::SetStateChangeWatcher(IStateChangeWatcher* watcher)
{
    this->stateChangeWatcher = watcher;
}
