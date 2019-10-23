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

int greenPin = 18;
const int greenLEDChannel = 1;
const int freq = 5000;
const int resolution = 8; 
bool playing = true;

WiFiUDP udp;

void setup() {
  Serial.begin(9600);

  pinMode(greenPin, OUTPUT);
  ledcSetup(greenLEDChannel, freq, resolution);
  ledcAttachPin(greenPin, greenLEDChannel);
  ledcWrite(greenLEDChannel, 255);

  WiFi.softAP(ssid, password);
  WiFi.softAPConfig(local_ip, gateway, subnet);
  
    server.begin();
}

void loop(){

    udp.beginPacket("192.168.1.2",5005);
    int touchVal = touchRead(T0);
    int piezoVal = analogRead(34);
    //Serial.println(touchVal);  // get value using T0
    Serial.println(piezoVal);
    if (touchVal < 20) {
      // light turns on when song is playing 
      if (playing) {
        ledcWrite(greenLEDChannel, 0);
        playing = false;
      }
      else {
        ledcWrite(greenLEDChannel, 255);
        playing = true;
      }
      udp.write(65); // A
    }
    else {
      udp.write(66); // B
    }

    if (piezoVal > 200) {
      // Serial.println("increase vol");
      udp.write(67); // C
    }
    else {
      // Serial.println("decrease vol");
      udp.write(68);  // D
    }
    udp.endPacket();
  
  
  //Wait for 1 second
  delay(100);
  
}
