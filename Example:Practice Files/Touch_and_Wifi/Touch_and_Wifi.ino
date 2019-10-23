#include <WiFi.h>
#include <WebServer.h>
#include <WiFiUdp.h>
//#include <OSCMessage.h>


/* Put your SSID & Password */
const char* ssid = "cynthia";  // Enter SSID here
const char* password = "12345678";  //Enter Password here

/* Put IP Address details */
IPAddress local_ip(192,168,1,1);
IPAddress gateway(192,168,1,1);
IPAddress subnet(255,255,255,0);

WebServer server(80);

WiFiUDP udp;

int greenPin = 18;
const int greenLEDChannel = 1;
const int freq = 5000;
const int resolution = 8;

void setup() {
  Serial.begin(9600);

  WiFi.softAP(ssid, password);
  WiFi.softAPConfig(local_ip, gateway, subnet);
  
  server.begin();

  pinMode(greenPin, OUTPUT);
  ledcSetup(greenLEDChannel, freq, resolution);
  ledcAttachPin(greenPin, greenLEDChannel);
}

void loop(){

    int touchVal = touchRead(T0);
    //Serial.println(touchVal);  // get value using T0
    if (touchVal < 20) 
      ledcWrite(greenLEDChannel, 255);
    else 
      ledcWrite(greenLEDChannel, 0);
    Serial.println(analogRead(34));
    
    udp.beginPacket("192.168.1.2",touchVal);
    udp.printf("elllo");
    udp.endPacket();
  
    //Wait for 1 second
    delay(1000);
  
}
