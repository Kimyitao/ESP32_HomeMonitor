//
// Created by 123 on 2024/1/6.
//

#ifndef ESP32_CONFIG_H
#define ESP32_CONFIG_H


class Config {
public:
    // MQTT 参数配置
    static const char* mqtt_broker; // MQTT服务器地址
    static const char* topic ;           // MQTT主题
    static const char* mqtt_username ;         // MQTT用户名
    static const char* mqtt_password ;       // MQTT密码
    static const int mqtt_port ;                 // MQTT端口号

    // WiFi 参数配置
    static const char* ssid ;         // 定义WiFi的SSID
    static const char* password ;   // 定义WiFi的密码

    // 串口配置
    static  const int portBaud; // 定义串口波特率
};


#endif //ESP32_CONFIG_H
