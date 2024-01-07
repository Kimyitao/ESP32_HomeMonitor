//
// Created by 123 on 2024/1/6.
//

#ifndef ESP32_LOCALWIFI_H
#define ESP32_LOCALWIFI_H

#include <Wifi.h>
#include "Config.h"
#include "ArduinoJson.h"

void connectToWifi();
String signalStrength();

#endif //ESP32_LOCALWIFI_H
