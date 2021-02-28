#ifndef LOGGER_H
#define LOGGER_H

#include "WString.h"
#include "HardwareSerial.h"

class Logger
{
private:
public:
    Logger();
    void Log(String message);
};

#endif