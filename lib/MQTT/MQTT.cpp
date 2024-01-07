//
// Created by 123 on 2024/1/6.
//

#include "MQTT.h"


void connectToMQTT(PubSubClient& client) {
    // 循环直到连接到MQTT服务器
    while (!client.connected()) {
        Serial.print("Connecting to MQTT Broker..."); // 打印正在连接MQTT服务器的信息
        String client_id = "esp32-client-";
        client_id += String(WiFi.macAddress()); // 生成一个基于MAC地址的唯一客户端ID

        // 尝试连接到MQTT服务器payload
        if (client.connect(client_id.c_str(), Config::mqtt_username, Config::mqtt_password)) {
            Serial.println("connected");
            client.publish(Config::topic, "connected"); // 发布消息到指定的MQTT主题
            client.subscribe(Config::topic);            // 订阅指定的MQTT主题
        } else {
            Serial.print("failed, rc=");
            Serial.print(client.state()); // 打印失败的状态码
            Serial.println(" try again in 5 seconds");
            delay(5000); // 等待5秒后重试
        }
    }
}

void publishToMQTT(PubSubClient& client ,const char * topic, const char * payload){
    if(!client.state()){
        client.publish(topic, payload);
    }
}