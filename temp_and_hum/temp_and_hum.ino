#include <Arduino.h>
#include <Wire.h>
#include "SHT31.h"
#include <SeeedOLED.h>
SHT31 sht31 = SHT31();

void setup() {
    Serial.begin(9600);
    while (!Serial);
    Serial.println("begin...");
    sht31.begin();
      Wire.begin();
  SeeedOled.init();  //initialze SEEED OLED display
  SeeedOled.clearDisplay();          //clear the screen and set start position to top left corner
  SeeedOled.setNormalDisplay();      //Set display to normal mode (i.e non-inverse mode)
  SeeedOled.setPageMode();
}

void loop() {
    float temp = sht31.getTemperature();
    float hum = sht31.getHumidity();
    delay(500);
    SeeedOled.setTextXY(0,0); 
    SeeedOled.putString("Temp = ");
    SeeedOled.putFloat(temp);
    SeeedOled.putString(" C"); //The unit for  Celsius because original arduino don't support speical symbols
    SeeedOled.setTextXY(1,0);
    SeeedOled.putString("Hum = ");
    SeeedOled.putFloat(hum);
    SeeedOled.putString("%");
//    Serial.print("Temp = ");
//    Serial.print(temp);
//    Serial.println(" C"); //The unit for  Celsius because original arduino don't support speical symbols
//    Serial.print("Hum = ");
//    Serial.print(hum);
//    Serial.println("%");
//    Serial.println();
    delay(1000);
}
