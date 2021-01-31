#include "Logger.h"
#include "Wire.h"

Logger::Logger()
{
    Serial.begin(115200);
}

void Logger::Log(String message)
{
    Serial.println(message);
}