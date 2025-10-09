

// Define all of the pins used.  These are NOT up to us, but rather what Elegoo decided.  Don't change.
// If your car doesn't function properly  with these pins, please double check your pin connections.
const int LEFT_MOTORS = 5; // pin that controls the speed of the 2 left side motors - PWM pin
const int RIGHT_MOTORS = 6; // pin that controls the speed of the 2 right side motors - PWM pin
const int LEFT_MOTOR_DIR = 8; // pin that controls the polarity, or direction, of the 2 left side motors (HIGH = forward, LOW = backward)
const int RIGHT_MOTOR_DIR = 7; // pin that controls the polarity, or direction, of the 2 right side motors (HIGH = forward, LOW = backward)
const int MOTOR_OUTPUT = 3; // controls whether the motors are allowed to run or not

// IR Detector Pins
const int RIGHT = A0;
const int MIDDLE = A1;
const int LEFT = A2;

// Threshold values for IR detection
// ran another code to find out these values - black is usually in between 200-300
const int THRESHOLD_ABOVE_IS_BLACK = 100;
const int THRESHOLD_ABOVE_IS_NOISE = 400;

// The number of lines your car should detect. This value should not be changed.
const int LINES_TO_COUNT = 2;

// TODO: Make a global counter to represent the number of counted lines (this integer is not constant)
int globalCounter = 0;

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
  // The line below is important for debugging
  Serial.begin(9600);
}

void loop() {
  if (globalCounter >= LINES_TO_COUNT) { //safety line?? in case the exit function at the end doesn't work: program will only run if the count is less than 2
    off();
  }
    else {
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
      //delay(250);
      middlePin = analogRead(MIDDLE); // this  line is important :) otherwise the program will stay in the while loop 
  }
      if (blackline == 1) {
      globalCounter++;
      Serial.println("I'm counting:");
      Serial.print(globalCounter);
  }
      if (globalCounter >= LINES_TO_COUNT) {
      delay(300);
      off();
      //delay(250);
      exit(0);
      // stops the function after have counted two lines
  }
    }
    
 