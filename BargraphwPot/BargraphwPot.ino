/* BargraphwPot

#  Maintainer & Author
Maintainer: Turkish Technology Team (T3) Foundation (https://deneyapkart.org/)
Author: Dogus Cendek (https://github.com/DogushC)

#  Description
Read potentiometer and display value an Bargraph.

#  Hardware Components
1 x Deneyap Kart
1 x Bargraph
1 x Potentiometer
1 x Breadboard
1 x Micro-B USB Cable
*/

/*Pins for potentiometer and bargraph*/
const int potPin = A0; //the pin that the potentiometer is attached to
int ledPins[] = {D0, D1, D4, D5, D6, D7, D9, D10, D11, D12}; //an array of pin numbers to which LEDs of Bargraph

const int ledCount = 10; //the number of LEDs in the bar graph

void setup() {
  for (int i = 0; i < ledCount; i++) {
    pinMode(ledPins[i], OUTPUT);
  }
}

void loop() {
  int potValue = analogRead(potPin);
  int ledLevel = map(potValue, 0, 4095, 0, ledCount); //map the result to a range from 0 to the number of LEDs

  /*loop over the LED array*/
  for (int j = 0; j < ledCount; j++) {
    if (j < ledLevel) {
      digitalWrite(ledPins[j], HIGH);
    }
    else {
      digitalWrite(ledPins[j], LOW);
    }
  }
}
