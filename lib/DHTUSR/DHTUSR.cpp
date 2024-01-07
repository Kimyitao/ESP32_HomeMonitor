//
// Created by 123 on 2024/1/6.
//

#include "DHTUSR.h"
#include "TimeTools.h"

String getDHTmsg(DHT& dht){

    delay(2000); // 暂停2秒，读取数据官方说明需要250毫秒
    float h = dht.readHumidity();          // 读取湿度
    float t = dht.readTemperature();       // 读取摄氏度
    float f = dht.readTemperature(true);   // 读取华氏度

    if (isnan(h) || isnan(t) || isnan(f)) {    // 如果读取错误
        JsonDocument doc;
        doc["error"] = "读取传感器失败";
        String output;
        serializeJson(doc, output);
        return output;
    } else{
        float hif = dht.computeHeatIndex(f, h);  // 计算华氏度的热指数
        float hic = dht.computeHeatIndex(t, h, false); // 计算摄氏度的热指数
        // 创建JSON对象
        JsonDocument doc;
        doc["湿度"] =String(h)+"%";
        doc["摄氏度"] = String(t) +"°c";
        doc["华氏度"] = String(f)+"℉";
        doc["摄氏热指数"] = String(hic)+"°c";
        doc["华氏热指数"] = String(hif)+"℉";
        doc["上报时间"] = timeStamp();
        // 序列化JSON
        String output;
        serializeJson(doc, output);
        Serial.println(output); // 打印读取并组装好的温湿度数据
        return output;
    }
}

