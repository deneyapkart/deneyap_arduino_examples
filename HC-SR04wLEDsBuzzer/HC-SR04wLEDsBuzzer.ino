/* HC-SR04wLEDsBuzzer

#  Maintainer & Author
Maintainer: Turkish Technology Team (T3) Foundation (https://deneyapkart.org/)
Author: Dogus Cendek (https://github.com/DogushC)

#  Description
Measure distance and show in Serial Monitor. Depends on distance, turn on/off LEDs and/or buzzer.

#  Hardware Components
1 x Deneyap Kart
1 x HC-SR04 Ultrasonic Distance Sensor Module
1 x Red LED
1 x Yellow LED
1 x Green LED
1 x Buzzer
4 x Resistor (100 ohm)
1 x Breadboard
1 x Micro-B USB Cable

#  Library
Add "HCSR04" Library by Martin Sosic (https://github.com/Martinsos/arduino-lib-hc-sr04)
*/

#include <HCSR04.h> //HC-SR04 lib

/* Pins for HC-SR04 */
#define trigPin D0
#define echoPin D1

UltraSonicDistanceSensor distanceSensor(trigPin, echoPin);  //HC-SR04 config

/* Pins for LEDs and buzzer */
const int buzzer = D12; //buzzer
const int rLed = D13;  //red LED
const int yLed = D14;  //yellow LED
const int gLed = D15; //green LED

float distance; //variable for distance

void setup() {
  pinMode(rLed, OUTPUT); //set the rLed pin as output
  pinMode(yLed, OUTPUT); //set the yLed pin as output
  pinMode(gLed, OUTPUT); //set the gLed pin as output
  pinMode(buzzer, OUTPUT); //set the buzzer pin as output
  Serial.begin(115200); //open the serial port at 115200 bps
}

void loop() {
  distance = distanceSensor.measureDistanceCm(); //measure distance as centimeter
  Serial.print("Distance: ");
  Serial.println(distance); //show the distance in Serial Monitor
  delay(100);
  /* Depends on distance turn on/off LEDs and buzzer. */
  if (distance <= 25 && distance > 0) {
  digitalWrite(buzzer, HIGH);
  digitalWrite(rLed, HIGH);
  delay(50);
  digitalWrite(buzzer, LOW);
  digitalWrite(rLed, LOW);
  delay(50);
  } else if (distance <= 45 && distance > 25) {
  digitalWrite(buzzer, HIGH);
  digitalWrite(yLed, HIGH);
  delay(50);
  digitalWrite(buzzer, LOW);
  digitalWrite(yLed, LOW);
  delay(50);
  } else {
  digitalWrite(buzzer, LOW);
  digitalWrite(gLed, HIGH);
  }
}
