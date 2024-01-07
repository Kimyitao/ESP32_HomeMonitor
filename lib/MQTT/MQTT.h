//
// Created by 123 on 2024/1/6.
//

#ifndef ESP32_MQTT_H
#define ESP32_MQTT_H

#include <PubSubClient.h>
#include <Wifi.h>
#include "Config.h"

void connectToMQTT(PubSubClient& client);
void publishToMQTT(PubSubClient& client , const char * topic,const char * payload);

#endif //ESP32_MQTT_H
