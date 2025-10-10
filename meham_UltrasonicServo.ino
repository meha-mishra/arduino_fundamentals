#include <NewPing.h>
#include <Servo.h>

const int ServoPin = 6;
const int TriggerPin = 2; //digital pin
const int EchoPin = 3; //digital pin with PWM (pulse width modulator)

NewPing sonar (TriggerPin, EchoPin, 30);
Servo servo; 

void setup() {
  Serial.begin(9600);
  servo.attach(ServoPin);
  servo.write(25);

}

void loop() {
  int cm = sonar.ping_cm();
  Serial.println(cm);

  int angle = map (cm, 1, 30, 155, 25);
  servo.write(angle)

  delay(50)

}
