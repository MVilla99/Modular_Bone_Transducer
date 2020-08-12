/*
 * Project Modular_Sensor_Workspace
 * Description: workspace intended to refine sensor modules to integrate in capstone project
 * Author: Mauricio Villa
 * Date: 12 - August - 2020
 */

/* CHANGE GITHUB BRANCH TO DEVELOPMENT INSTEAD OF MASTER
*/
#include <Wire.h>
#include <Adafruit_Sensor.h>
#include <Adafruit_SSD1306.h>
#include <Grove_Air_Quality_Sensor.h>
#include <Adafruit_BME280.h>
  #define OLED_RESET A0

  
Adafruit_BME280 bme;
Adafruit_SSD1306 display(OLED_RESET);
// setup() runs once, when the device is first turned on.
void setup() {
  // Put initialization like pinMode and begin functions here.
  Serial.begin(9600);
  
  Wire.begin();
  display.begin(SSD1306_SWITCHCAPVCC, 0x3C);
  display.display();
  bme.begin(0x76);

}

// loop() runs over and over again, as quickly as it can execute.
void loop() {
  // The core of your code will likely live here.

}