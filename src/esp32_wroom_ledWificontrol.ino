

#include <WiFi.h>
#include <WebServer.h>

const char* ssid = "XW"; // 你的WiFi网络名称
const char* password = "99999999"; // 你的WiFi网络密码

WebServer server(80); // 创建一个Web服务器对象，监听端口80

int ledPins[] = {5, 18, 19, 21, 22}; // 设置LED连接的引脚

void handleRoot() {
   String html = "<html><body style='font-size: 48px;'>"; // 设置字号为24px
  html += "<h1>Control LEDs</h1>";
  html += "<p><a href='/on'>all LEDs on</a></p>";
  html += "<p><a href='/off'>all LEDs off</a></p>";
  html += "</body></html>";
  

  server.send(200, "text/html", html);
}

void handleOn() {
  for (int i = 0; i < 5; i++) {
    digitalWrite(ledPins[i], HIGH); // 打开所有LED
  }
  server.send(200, "text/plain", "All LEDs are ON");
}

void handleOff() {
  for (int i = 0; i < 5; i++) {
    digitalWrite(ledPins[i], LOW); // 关闭所有LED
  }
  server.send(200, "text/plain", "All LEDs are OFF");
}

void setup() {
  Serial.begin(115200);

  WiFi.begin(ssid, password); // 连接WiFi网络

  while (WiFi.status() != WL_CONNECTED) {
    delay(1000);
    Serial.println("Connecting to WiFi...");
     Serial.print("ESP32 IP Address: ");
     Serial.println(WiFi.localIP());
  }

  Serial.println("Connected to WiFi");

  server.on("/", handleRoot);
  server.on("/on", handleOn);
  server.on("/off", handleOff);

  server.begin(); // 启动Web服务器
  Serial.println("Server started");

  for (int i = 0; i < 5; i++) {
    pinMode(ledPins[i], OUTPUT); // 设置引脚为输出模式
    digitalWrite(ledPins[i], LOW); // 初始状态设置为关闭
  }
}

void loop() {
  server.handleClient(); // 处理网络请求
}