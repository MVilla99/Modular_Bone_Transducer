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

#include <Adafruit_MQTT.h>
  #include "Adafruit_MQTT/Adafruit_MQTT.h"
  #include "Adafruit_MQTT/Adafruit_MQTT_SPARK.h"
  #include "Adafruit_MQTT/Adafruit_MQTT.h"

  #define AIO_SERVER "io.adafruit.com"
  #define AIO_SERVERPORT 1833
/*      PUT AIO KEYS IN IGNORE FILE       */

  #define OLED_RESET A0

  TCPClient TheClient;
  Adafruit_MQTT_SPARK mqtt(&TheClient,AIO_SERVER,AIO_SERVERPORT,AIO_USERNAME,AIO_KEY);


Adafruit_BME280 bme;
Adafruit_SSD1306 display(OLED_RESET);
AirQualitySensor senseAQ( ); // put sensor pin in here

/*    for AirQualitySensor use    */
int quality;
int AQvalue;
/*    for BME use   */
float temp;
float press;
float hum;
float alt;

void setup() {
  Serial.begin(9600);
  delay(100); // waiting for serial monitor to initialize 
  Wire.begin();
  display.begin(SSD1306_SWITCHCAPVCC, 0x3C);
  display.display();
  display.clearDisplay();
  display.display();

  bme.begin(0x76);
  senseAQ.init();

}


void loop() {


}

void airQualitySensor(){
  quality = senseAQ.slope();
  AQvalue = senseAQ.getValue();

  if(quality == AirQualitySensor::FORCE_SIGNAL){
    // do something for very high pollution
  }
  else if(quality == AirQualitySensor::HIGH_POLLUTION){
    // do something for high pollution
  }
  else if(quality == AirQualitySensor::LOW_POLLUTION){
    // do something for low pollution
  }
  else if(quality == AirQualitySensor::FRESH_AIR){
    // do something for fresh air
  }
}
/* for the above function, maybe tie leds or neopixels to the module
tie a neopixel into the actual transducer frame, only blink red in users peripherals
if dangerous value. if "danger acknowledged" (make dangerAcknowleged a boolean) 
then just make a dim red emit in users peripherals. 
*/

void dustSensor(){
  dustDuration = pulseIn( ,LOW); // put in the pin for dustsensor here. 
  lowPulseOccupance = lowPulseOccupancy+dustDuration;

  if((millis()-dustStartTime)>     ){ // put in a value assigned to time. in plant water it was "replace this time"

  } 

}