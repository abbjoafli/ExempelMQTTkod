# ExempelMQTTkod
[Sway!](https://sway.office.com/4wekNvX2nqSH0zCX?ref=Link&loc=mysways)

## Exempelkod till videorna med MQTT

Saker är självförklarande men här kommer en förklaring:
1. index.html = Landningssida för vår httpserver inuti vår mqtt server.
2. index.js = MQTT brokern
3. IOTCODE.txt = Koden till mikroenheten.
4. Kopplingsschema.png= Bild som visar hur du ska koppla Esp 8266 till led.
5. mqttwebclient.html = HTML/JS sida som pub och subscribar till brokern.
6. package = package.
7. pub.js = Vår publisher kod i nodejs.
8. sub.j =vår subscriber kod i nodejs.
9. mqttwebclientConnectToInternet.html  = uppdaterad för att kunna skicka och hämta värden från Maqiatto. Kan kikas på om man vill ha hjälp att koppla upp sig till Maqiatto brokern.
10. ESPMQTTTOINTERNET.ino = ESP8266 kod för att skicka data till en internet broker (Maqiatto).


## Länkar
[Guiden för att göra MQTTklient i webbläsare (thomaslaurenson)](https://www.thomaslaurenson.com/blog/2018/07/10/mqtt-web-application-using-javascript-and-websockets/)



[Maqiatto, MQTT Online broker](https://www.maqiatto.com/connect)

![alt text](https://www.maqiatto.com/images/maqiattowebsock.png "Maqiatto connect instruktioner")

## Tips för att göra mqttwebclient fungerande med Maqiatto
Host: maqiatto.com
Port: 8883
topic: joakim.flink@abbindustrigymnasium.se/lampa1 //Detta måste du byta ut om ditt Maqiatto konto + /din topicnamn

När vi ansluter till brokern så måste vi skicka med användarnamnet och lösenord, detta lösenordet måste vara generat för mqtt och kan inte vara det som du gjorde när du skapade ditt maqiatto konto!! 
```      
client.connect({userName : "namn",password : "något",
                    onSuccess: onConnect,
                    onFailure: onFail,
                               });

```                               
                               
                               
## Tips för att göra Mqtt på mikrokontrollen fungerande med Maqiatto
Se till att  Client Name är något unikt, har man samma som andra stör de ut varandra.
```
EspMQTTClient client(
 "Nätverksnamn",           // Wifi ssid
  "Pass",           // Wifi password
  "maqiatto.com",  // MQTT broker ip
  1883,             // MQTT broker port
  "något.något@abbindustrigymnasium.se",            // MQTT username
  "Pass",       // MQTT password
  "MÅSTE VARA UNIKT!",          // Client name
  onConnectionEstablished, // Connection established callback
  true,             // Enable web updater
  true              // Enable debug messages
);
```
