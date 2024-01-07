//
// Created by 123 on 2024/1/6.
//

#include "Config.h"

// MQTT 参数配置
const char* Config::mqtt_broker = "150.158.98.144"; // MQTT服务器地址
const char* Config::topic = "DHT11/message";           // MQTT主题
const char* Config::mqtt_username = "";         // MQTT用户名
const char* Config::mqtt_password = "";       // MQTT密码
const int Config::mqtt_port = 1883;                 // MQTT端口号


// WiFi 参数配置
const char* Config::ssid = "TP-LINK_1308";         // 定义WiFi的SSID
const char* Config::password = "19980103";   // 定义WiFi的密码

// 串口配置

const int Config::portBaud = 9600; // 定义串口波特率

