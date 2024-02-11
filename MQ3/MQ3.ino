//OLED
#include  <Wire.h>
#include <Adafruit_GFX.h>
#include <Adafruit_SSD1306.h>
#define Sober 250   // Define max value that we consider sober
#define Drunk 500   // Define min value that we consider drunk
//OLED  define
#define SCREEN_WIDTH 128 // OLED display width, in pixels
#define SCREEN_HEIGHT  64 // OLED display height, in pixels
// Declaration for an SSD1306 display connected  to I2C (SDA, SCL pins)
Adafruit_SSD1306 display(SCREEN_WIDTH, SCREEN_HEIGHT,  &Wire, -1);

#define MQ3pin A0

float sensorValue;  //variable to store sensor value

void setup() {
  Serial.begin(9600); // sets the serial port to 9600
  Serial.println("MQ3 warming up!");
  pinMode(MQ3pin, INPUT);
  display.begin(SSD1306_SWITCHCAPVCC, 0x3C); 
  display.clearDisplay();
  delay(2000); 
}

void loop() {
  sensorValue = analogRead(MQ3pin); // read analog input pin 0

  Serial.print("Sensor Value: ");
  Serial.print(sensorValue);

  display.setTextSize(1);
    display.setTextColor(WHITE);
    display.setCursor(20,0);
    display.print("Alcohol Detector");
    display.display();
    delay(100);
  
  // Determine the status
  if (sensorValue < Sober) {
    Serial.println("  |  Status: Stone Cold Sober");
    display.setTextSize(2);
    display.setTextColor(WHITE);
    display.setCursor(25,30);
    display.print("Sober");
    display.display();
    display.clearDisplay();
    delay(100);
  } else if (sensorValue >= Sober && sensorValue < Drunk) {
    Serial.println("  |  Status: Drinking but within legal limits");
    display.setTextSize(2);
    display.setTextColor(WHITE);
    display.setCursor(0,30);
    display.print("Drunk in \nlimit");
    display.display();
    display.clearDisplay();
    delay(100);
  } else {
    Serial.println("  |  Status: DRUNK");
    display.setTextSize(2);
    display.setTextColor(WHITE);
    display.setCursor(0,30);
    display.print("Heavily \nDrunk");
    display.display();
    display.clearDisplay();
    delay(100);
  }
  
  delay(2000); // wait 2s for next reading
}
