#include <ESP8266WiFi.h>
#include "ThingSpeak.h"
const char* ssid = "KHUSI";
const char* pass = "09072010";
 WiFiClient  client;
unsigned long channel_number = 1126372;            // Channel ID
const char * read_api_key = "53OOWLQH7H2PXSTM"; // Read API Key
const int field_1 = 1;
int led ,statusCode;
void setup() {
  pinMode(D4,OUTPUT);
 Serial.begin(9600);
Serial.println("Connecting to Wifi");
 WiFi.begin(ssid,pass);
while(WiFi.status()!=WL_CONNECTED){
    Serial.print(".");
    delay(500);
  }
  Serial.println("Wifi Connected");
  ThingSpeak.begin(client);
 
}

void loop() {
 long led = ThingSpeak.readIntField(channel_number, field_1, read_api_key);
 Serial.println(int(led));
  statusCode = ThingSpeak.getLastReadStatus();
  if (statusCode == 200)
  {
    if (led == 0)
    digitalWrite(D4,HIGH);
    else
    digitalWrite(D4,LOW);
  }
  else
  {
    Serial.println("Unable to read channel / No internet connection");
  }
  delay(100);


}
