// ESP32 Touch Test
// Just test touch pin - Touch0 is T0 which is on GPIO 4.

int greenPin = 18;
const int greenLEDChannel = 1;
const int freq = 5000;
const int resolution = 8;

void setup()
{
  Serial.begin(9600);
  delay(1000); // give me time to bring up serial monitor
  Serial.println("ESP32 Touch Test");

  pinMode(greenPin, OUTPUT);
  ledcSetup(greenLEDChannel, freq, resolution);
  ledcAttachPin(greenPin, greenLEDChannel);

  ledcWrite(greenLEDChannel, 0);
  Serial.println(255);
}

void loop()
{
  int touchVal = touchRead(T0);
  //Serial.println(touchVal);  // get value using T0
  if (touchVal < 20) 
    ledcWrite(greenLEDChannel, 255);
  else 
    ledcWrite(greenLEDChannel, 0);
  Serial.println(analogRead(34));
  
}
