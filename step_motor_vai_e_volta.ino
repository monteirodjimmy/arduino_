#include <Stepper.h>

// Define stepper motor connections and steps per revolution:
#define dirPin 2
#define stepPin 3
#define stepsPerRevolution 200


void setup() {
    // Declare pins as output:
  Serial.begin(9600);
  pinMode(stepPin, OUTPUT);
  pinMode(dirPin, OUTPUT);
}

void loop() {

  // Set the spinning direction clockwise:
  digitalWrite(dirPin, HIGH);

  // Spin the stepper motor 1 revolution slowly:
  for (int i = 0; i < stepsPerRevolution; i++) {
    // These four lines result in 1 step:
    digitalWrite(stepPin, HIGH);
    /*Serial.println(digitalRead(stepPin));*/
    delayMicroseconds(500);
    digitalWrite(stepPin, LOW);
   /* Serial.println(digitalRead(stepPin));*/
    delayMicroseconds(500);
  }
  delay(1000);

  // Set the spinning direction counterclockwise:
  digitalWrite(dirPin, LOW);

  // Spin the stepper motor 1 revolution quickly:
  for (int i = 0; i < stepsPerRevolution; i++) {
    // These four lines result in 1 step:
    digitalWrite(stepPin, HIGH);
    /*Serial.println(digitalRead(stepPin));*/
    delayMicroseconds(500);
    digitalWrite(stepPin, LOW);
    /*Serial.println(digitalRead(stepPin));*/
    delayMicroseconds(500);
  }
  delay(1000);

}
