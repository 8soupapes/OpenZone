#include "Logger.h"

void Logger::begin()
{
    Serial.begin(115200);
    delay(500);
}

void Logger::info(const String& message)
{
    Serial.print("[INFO] ");
    Serial.println(message);
}

void Logger::warning(const String& message)
{
    Serial.print("[WARN] ");
    Serial.println(message);
}

void Logger::error(const String& message)
{
    Serial.print("[ERROR] ");
    Serial.println(message);
}