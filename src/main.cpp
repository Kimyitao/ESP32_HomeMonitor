//
// Created by 123 on 2024/1/6.
//


#include <LocalWifi.h>
#include <PubSubClient.h>
#include <DHT.h>
#include "DHTUSR.h"
#include "MQTT.h"
#include "Config.h"

DHT dht(DHTPIN, DHTTYPE);     //创建一个DHT对象
WiFiClient espClient;                       // 创建用于连接网络的WiFi客户端对象
PubSubClient client(espClient);             // 创建MQTT客户端对象

void setup() {
    Serial.begin(Config::portBaud); // 初始化串口通信
    dht.begin();               //初始化DHT传感器
    connectToWifi();      // 连接WiFi
    client.setServer(Config::mqtt_broker, Config::mqtt_port); // 设置MQTT服务器和端口
    connectToMQTT(client);      // 连接MQTT服务器
}

void loop() {
    // 如果MQTT客户端断开连接，则重新连接
    if (!client.connected()) {
        connectToMQTT(client);
    }
    String DHTmsg = getDHTmsg(dht); // 获取DHTpayload
    const char* cstr_DHTmsg = DHTmsg.c_str(); // 使用c_str()获取const char*指针
    String wifiSignal = signalStrength();
    const char* cstr_wifiSignal =wifiSignal.c_str();
    //
    publishToMQTT(client,"DHT11/message", cstr_DHTmsg);
    publishToMQTT(client,"wifi/signal/strength",cstr_wifiSignal);

    delay(10000); // 等待10秒后再次上报
    client.loop(); // 维持MQTT客户端活动状态
}
