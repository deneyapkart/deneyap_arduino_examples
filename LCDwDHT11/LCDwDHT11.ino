/* LCDwDHT11

#  Maintainer & Author
Maintainer: Turkish Technology Team (T3) Foundation (https://deneyapkart.org/)
Author: Dogus Cendek (https://github.com/DogushC)

#  Description
Sense temperature and humidity values of air with DHT11 module and show the values at LCD screen.

#  Hardware Components
1 x Deneyap Kart
1 x 2x16 LCD
1 x DHT11 Temperature and Humidity Sensor Module
1 x Potentiometer
1 x Resistor (220 ohm)
1 x Breadboard
1 x Micro-B USB Cable

#  Library
Add "DHT sensor library" Library version 1.4.4 by Adafruit (https://github.com/adafruit/DHT-sensor-library)
*/

#include <LiquidCrystal.h> //Internal library for LCD screen.
#include "DHT.h" //DHT11 Lib

/* Pins for 2x16 lCD */
const int rs = D1;
const int en = D0;
const int d4 = D15;
const int d5 = D14;
const int d6 = D13;
const int d7 = D12;

LiquidCrystal mylcd(rs, en, d4, d5, d6, d7); //lCD screen config

DHT myDHT11(D9,DHT11); //DHT11 config

float temp; //variable for temperature
float humidity; //variable for humidity

void setup() {
  myDHT11.begin(); //initialize DHT11
  mylcd.begin(16, 2); //initialize 2 rows x 16 columns LCD screen
}

void loop() {
   temp=myDHT11.readTemperature(); //sense temperature
   humidity=myDHT11.readHumidity(); //sense humidity
   mylcd.setCursor(0,0); //set the initial location of written text
   mylcd.print("Temperature: "); //print text to the LCD screen
   mylcd.setCursor(10,0);
   mylcd.print(temp);
   mylcd.setCursor(0,1);
   mylcd.print("Humidity     :% ");
   mylcd.setCursor(10,1);
   mylcd.print(humidity);
   delay(500);
}
