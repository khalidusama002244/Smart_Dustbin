#include <ESP32Servo.h>

const int servoPin = 15;
const int trigPin = 5;
const int echoPin = 35;
Servo lid;

int getDistance();

void setup() {
  pinMode(trigPin, OUTPUT);
  pinMode(echoPin, INPUT);
  lid.attach(servoPin);
  lid.write(0);
}

void loop() {
  int distance = getDistance();

  if (distance <= 15) {
    for (int i = 0; i <= 80; i++) {
      lid.write(i);
      delay(10);
    }
    delay(1000);
    distance = getDistance();
    while (distance > 15) {
      delay(1000);
    }

    for (int j = 80; j >= 0; j--) {
      lid.write(j);
      delay(10);
    }
  }
}

int getDistance() {
  int distance, duration;
  digitalWrite(trigPin, LOW);
  delayMicroseconds(2);
  digitalWrite(trigPin, HIGH);
  delayMicroseconds(10);
  digitalWrite(trigPin, LOW);
  duration = pulseIn(echoPin, HIGH);
  distance = duration * 0.034 / 2;
  Serial.print("Distance: ");
  Serial.println(distance);
  return distance;  // Add this line to return the calculated distance
}
