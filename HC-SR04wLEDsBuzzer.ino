#include <HCSR04.h> //HC-SR04 lib

/* Pins for HC-SR04 */
#define trigPin D0
#define echoPin D1

UltraSonicDistanceSensor distanceSensor(trigPin, echoPin);  //HC-SR04 Config

/* Pins for LEDs and Buzzer */
const int buzzer = D12; //buzzer
const int rLed = D13;  //red LED
const int yLed = D14;  //yellow LED
const int gLed = D15; //green LED

float distance; //Variable for Distance

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
  Serial.println(distance); //print distance
  delay(100);

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
