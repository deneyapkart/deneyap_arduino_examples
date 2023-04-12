/* GearDCwPotBC547

#  Maintainer & Author
Maintainer: Turkish Technology Team (T3) Foundation (https://deneyapkart.org/)
Author: Dogus Cendek (https://github.com/DogushC)

#  Description
Read potentiometer and show value in Serial Monitor. Control speed of the motor using BC547 transistor depends on the value of the potentiometer.

#  Hardware Components
1 x Deneyap Kart
1 x 6V Gear DC Motor
1 x BC547 Transistor
1 x Potentiometer
1 x Diode
1 x Resistor (220 ohm)
1 x Breadboard
1 x Micro-B USB Cable
*/

/* Pins for potentiometer and transistor */
const int pot = A0;
const int motor = D12;

int potValue;

void setup() {
  Serial.begin(115200); //open the serial port at 115200 bps
  pinMode(pot, INPUT); //sets the pot pin as input
}

void loop() {
  potValue = analogRead(pot); //read potentiometer value
  potValue = map(knobValue, 0, 4095, 0, 255); //map value from 13 bit to 8 bit
  Serial.println(potValue); //show the value in Serial Monitor
  analogWrite(motor, potValue); //adjust speed of the motor
  delay(100);
}
