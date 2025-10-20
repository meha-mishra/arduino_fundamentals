#include <NewPing.h>
#include <Servo.h>

// Define all of the pins used.  These are NOT up to us, but rather what Elegoo decided.  Don't change.
// If your car doesn't function properly  with these pins, please double check your pin connections.
const int LEFT_MOTORS = 5; // pin that controls the speed of the 2 left side motors - PWM pin
const int RIGHT_MOTORS = 6; // pin that controls the speed of the 2 right side motors - PWM pin
const int LEFT_MOTOR_DIR = 8; // pin that controls the polarity, or direction, of the 2 left side motors (HIGH = forward, LOW = backward)
const int RIGHT_MOTOR_DIR = 7; // pin that controls the polarity, or direction, of the 2 right side motors (HIGH = forward, LOW = backward)
const int MOTOR_OUTPUT = 3; // controls whether the motors are allowed to run or not
const int ServoPin = 10 ; // pin that connects to Servo motor (other servo wires connect to power)
const int TriggerPin = 13 ; //middle pin on ultasonic sensor
const int EchoPin = 12 ; // middle pin on ultrasonic sensor
// IR Detector Pins
const int RIGHT = A0;
const int MIDDLE = A1;
const int LEFT = A2;

// Threshold values for IR detection
// ran another code to find out these values - black is usually in between 200-300
const int THRESHOLD_ABOVE_IS_BLACK = 100;
const int THRESHOLD_ABOVE_IS_NOISE = 400;

// The number of lines your car should detect. This value should not be changed.
const int numLine = 7; // 2-8
const int distVal = 9; //5-25

// TODO: Make a global counter to represent the number of counted lines (this integer is not constant)
int globalCounter = 0;

NewPing sonar (TriggerPin, EchoPin, 30); // 30 is max distance to start detecting - should be greater than distval
Servo servo;

void forward (int speed) {
  digitalWrite(MOTOR_OUTPUT, HIGH);
  digitalWrite(LEFT_MOTOR_DIR, HIGH);
  digitalWrite(RIGHT_MOTOR_DIR, HIGH);
  analogWrite(LEFT_MOTORS, speed);
  analogWrite(RIGHT_MOTORS, speed);
}
void off(){
  digitalWrite(MOTOR_OUTPUT, LOW); // to call when i want to turn the robot off
}
void setup() {
  // put your setup code here, to run once:

  pinMode(MOTOR_OUTPUT, OUTPUT);
  pinMode(LEFT_MOTOR_DIR, OUTPUT);
  pinMode(RIGHT_MOTOR_DIR, OUTPUT);
  pinMode(RIGHT_MOTOR_DIR, OUTPUT);
  pinMode(LEFT_MOTORS, OUTPUT);
  pinMode(RIGHT_MOTORS, OUTPUT);
  pinMode(RIGHT, INPUT);
  pinMode(LEFT, INPUT);
  pinMode(MIDDLE, INPUT);
  digitalWrite(MOTOR_OUTPUT, HIGH);
  servo.attach(ServoPin);
  servo.write (180); //this integer is an angle on a scale from 0 (complete left) to 180 (complete right)
  // The line below is important for debugging
  Serial.begin(9600);
}

void loop() {
  while (globalCounter <= numLine) { //safety line?? in case the exit function at the end doesn't work: program will only run if the count is less than 2
    forward(60);
    Serial.println("I'm moving");
      //delay(250);
  // TODO: Establish a boolean or integer variable to keep track of whether a black line was observed or not
  // TODO: Get an initial IR reading
    bool blackline = 0;
    int middlePin = analogRead(MIDDLE);
  

    while (middlePin >= THRESHOLD_ABOVE_IS_BLACK && middlePin <= THRESHOLD_ABOVE_IS_NOISE) {
    blackline = 1;
    //Serial.println("black line!");
    Serial.print("middle pin value: ");
    Serial.println(middlePin);
    
    middlePin = analogRead(MIDDLE); // this  line is important :) otherwise the program will stay in the while loop 
    } 
    if (blackline == 1) {
      globalCounter++;
      Serial.println("I'm counting:");
      Serial.print(globalCounter);

     //swivel servo
      int angle = map(blackline, 0, 1, 180, 90);
      servo.write(angle);
      Serial.print("swiveled"); 
      delay(250);
      servo.write(180);
    }
    if (globalCounter >= numLine){
      off();
      delay(300);
      break;// stops the function after have counted numLine lines
    } 
  }
      

  servo.write(90);
  int cm = sonar.ping_cm();

  while (cm >= distVal || cm == 0) {
    forward(50);
    cm = sonar.ping_cm(); //reads Ultrasonic sensor every iteration; allows break
  }

  off(); //outside of all while loops; default
  
}

   
 