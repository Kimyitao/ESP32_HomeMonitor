//
// Created by 123 on 2024/1/6.
//

#include "LocalWifi.h"
#include "TimeTools.h"

void connectToWifi() {
    Serial.println("Connecting to WiFi..."); // 打印正在连接WiFi的信息
    WiFi.begin(Config::ssid, Config::password);              // 初始化WiFi连接
    unsigned long startAttemptTime = millis(); // 记录开始尝试连接WiFi的时间

    // 循环等待WiFi连接成功或超时
    while (WiFiClass::status() != WL_CONNECTED && millis() - startAttemptTime < 5000) {
        Serial.print("."); // 打印等待连接的点
        delay(500);
    }

    // 判断WiFi是否连接成功
    if(WiFiClass::status() != WL_CONNECTED) {
        Serial.println("Failed to connect to WiFi. Please check your parameters.");
    } else {
        Serial.print("Connected to WiFi network with IP Address: ");
        Serial.println(WiFi.localIP());
    }
}

String signalStrength(){
    // 创建JSON对象
    if (WiFiClass::status() == WL_CONNECTED){
        JsonDocument doc;
        long rssi = WiFi.RSSI();
        doc["信号强度"] =String(rssi)+" dBm";
        doc["上报时间"] = timeStamp();
        // 序列化JSON
        String output;
        serializeJson(doc, output);
        Serial.println(output); // 打印读取并组装好的wifi信息
        return output;
    } else
    {
        Serial.println("WiFi未连接");
        return "WiFi未连接";
    }
}

