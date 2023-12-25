#include <ESP8266WiFi.h>
#include <ESP8266HTTPClient.h>
#include <WiFiClient.h>
#include <ArduinoJson.h>

const char* ssid = "IHSAN";
const char* pass = "##Splhzans9";
const char* host = "http://192.168.18.2/laravel-arduino/public";

void setup()
{
  Serial.begin(115200);
  Serial.println();

  WiFi.begin(ssid, pass);

  Serial.print("Connecting");
  while (WiFi.status() != WL_CONNECTED)
  {
    delay(500);
    Serial.print(".");
  }
  Serial.println();

  Serial.print("Connected, IP address: ");
  Serial.println(WiFi.localIP());
}

void loop() 
{
  WiFiClient client;
  HTTPClient http;
  String url;

  // API GET 
  url = String(host) + "/api/sensor";
  http.begin(client, url);
  
  int httpCode = http.GET();
  if (httpCode > 0) 
  {
    String payload = http.getString();
    char json[500];
    payload.toCharArray(json, 500);

    StaticJsonDocument<200> data;
    deserializeJson(data, json);

    // Database minimal harus sudah ada 1 data
    String name = data[0]["name"];
    String value = data[0]["value"];

    Serial.println("");
    Serial.println(name);
    Serial.println(value);
    Serial.println(payload);
  }
  http.end();

  // API CREATE / UPDATE / DELETE
  url = String(host) + "/api/sensor/humidity/100";
  http.begin(client, url);
  http.sendRequest("PUT", "");
  http.end();

  delay(2000);
}