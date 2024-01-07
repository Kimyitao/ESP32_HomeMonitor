//
// Created by 123 on 2024/1/6.
//
#include "TimeTools.h"

WiFiUDP ntpUDP;
NTPClient timeClient(ntpUDP, "pool.ntp.org");// "pool.ntp.org" 是一个广泛使用的公共NTP服务器

String timeStamp(){
    timeClient.update();
    unsigned long epochTime = timeClient.getEpochTime();
    return String(epochTime);
}
