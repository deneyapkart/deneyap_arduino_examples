/* DCwButtonBC547

#  Maintainer & Author
Maintainer: Turkish Technology Team (T3) Foundation (https://deneyapkart.org/)
Author: Dogus Cendek (https://github.com/DogushC)

#  Description
Rotate the motor using BC547 transistor depends on position of the button.

#  Hardware Components
1 x Deneyap Kart
1 x 6V DC Motor
1 x BC547 Transistor
1 x Push Button
1 x Diode
1 x Resistor (10 kohm)
1 x Resistor (220 ohm)
1 x 9V Battery
1 x 9V Battery Cable
1 x Breadboard
1 x Micro-B USB Cable
*/

/* Pins for button and transistor */
const int button = D0;
const int motor = D12;

int buttonValue;

void setup() {
  pinMode(button, INPUT); //sets the button pin as input
  pinMode(motor, OUTPUT); //sets the transistor pin as output
}

void loop() {
  if (buttonValue == HIGH) { //prees and hold the button
  digitalWrite(motor, HIGH); //rotate the motor
} else { //release the button
  digitalWrite(motor, LOW); //stop the motor
}
  delay(100);
}
