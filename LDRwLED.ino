/* Pins for LED and LDR */
const int led = D0;
const int ldr = A0;

int ldrValue;

void setup() {
  Serial.begin(115200); //open the serial port at 115200 bps
}

void loop() {
  ldrValue = analogRead(ldr); //read LDR value
  ldrValue = map(ldrValue, 0, 4095, 0, 255); //map value from 13 bit to 8 bit
  Serial.println(ldrValue); //print modified LDR value
  analogWrite(led, ldrValue); //write modified LDR value to LED
  delay(100);
}
