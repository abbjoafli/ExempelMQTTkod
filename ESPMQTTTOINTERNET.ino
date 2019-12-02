#include "EspMQTTClient.h"
//Install libraries PubSubClient and EspMQTTClient


void onConnectionEstablished();

EspMQTTClient client(
 "Nätverksnamn",           // Wifi ssid
  "password",           // Wifi password
  "maqiatto.com",  // MQTT broker ip
  1883,             // MQTT broker port
  "användarnamn på maqiatton",            // MQTT username
  "password",       // MQTT password
  "klientnamn",          // Client name
  onConnectionEstablished, // Connection established callback
  true,             // Enable web updater
  true              // Enable debug messages
);



#define led_pin D1


void setup() {
pinMode(led_pin, OUTPUT);
digitalWrite(led_pin,LOW);
Serial.begin(115200);
}

bool off=false;

void lampa(){
  if(off==true)
  {
  Serial.println("Släckt!");
  off=false;
  }
  else
  {
  off=true;
  
  Serial.println("Släckt!");
  }

digitalWrite(led_pin,off);
  
}

void onConnectionEstablished()
{
  client.subscribe("joakim.flink@abbindustrigymnasium.se/lampa", [] (const String &payload)
  {
    Serial.println(payload);
//    if(payload=="on")
  //  onlampa();
    lampa();
  });
  
  client.publish("joakim.flink@abbindustrigymnasium.se/lampa", "This is a message");

  client.executeDelayed(5 * 1000, []() {
    client.publish("joakim.flink@abbindustrigymnasium.se/lampa", "This is a message sent 5 seconds later");
  });
}


void loop() {
  // put your main code here, to run repeatedly:
client.loop();
}
