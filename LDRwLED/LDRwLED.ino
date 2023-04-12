/* LDRwLED

#  Maintainer & Author
Maintainer: Turkish Technology Team (T3) Foundation (https://deneyapkart.org/)
Author: Dogus Cendek (https://github.com/DogushC)

#  Description
Measure light intensity and show in Serial Monitor. Depends on the light intensity, adjust the brightness of the LED.

#  Hardware Components
1 x Deneyap Kart
1 x LDR
1 x Red LED
2 x Resistor (220 ohm)
1 x Breadboard
1 x Micro-B USB Cable
*/

/* Pins for LED and LDR */
const int led = D0;
const int ldr = A0;

int ldrValue;

void setup() {
  Serial.begin(115200); //open the serial port at 115200 bps
}

void loop() {
  ldrValue = analogRead(ldr); //read LDR value
  ldrValue = map(ldrValue, 4095, 0, 0, 255); //map value from 13 bit to 8 bit and reverse it
  Serial.println(ldrValue); //show the value in Serial Monitor
  analogWrite(led, ldrValue); //adjust the brightness of the LED
  delay(100);
}
