//
// Created by 123 on 2024/1/6.
//

#ifndef ESP32_DHTUSR_H
#define ESP32_DHTUSR_H

#include "DHT.h"
#include "DHT_U.h"
#include "ArduinoJson.h"

#define DHTPIN 15 // 设置获取数据的引脚
// 对应DHT的版本，选择一个取消注释
#define DHTTYPE DHT11 // DHTUSR 11

String getDHTmsg(DHT& dht);

#endif //ESP32_DHTUSR_H



