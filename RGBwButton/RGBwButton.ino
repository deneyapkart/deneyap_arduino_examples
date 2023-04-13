/* RGBwButton

#  Maintainer & Author
Maintainer: Turkish Technology Team (T3) Foundation (https://deneyapkart.org/)
Author: Dogus Cendek (https://github.com/DogushC)

#  Description
Generate a random number. Set the RGB LED on depends on position of the button.

#  Hardware Components
1 x Deneyap Kart
1 x Pushbutton
1 x RGB LED (Cathode)
4 x Resistor (220 ohm)
1 x Breadboard
1 x Micro-B USB Cable
*/

/* Pins for RGB LED and button */
int pins[] = {D0, D1, D4};
const int button = D5;

int buttonValue;
int randomLED;

void setup() {
  Serial.begin(115200); //open the serial port at 115200 bps
  pinMode(button, INPUT); //sets the button pin as input
  for (int i=0; i<3; i++) {
    pinMode(pins[i], OUTPUT); //sets the RGB LED pins as output
  }
}

void loop() {
  buttonValue = digitalRead(button); //read LDR value
  randomLED = random(0, 3); //generate a random number from 0 to 2
  if (buttonValue == HIGH){ //prees and hold the button
     digitalWrite(pins[randomLED], HIGH); //set the random pin of RGB LED on
  } else {
     digitalWrite(pins[0], LOW); //set the Red LED pin off
     digitalWrite(pins[1], LOW); //set the Green LED pin off
     digitalWrite(pins[2], LOW); //set the Blue LED pin off
  }
  delay(100);
}
