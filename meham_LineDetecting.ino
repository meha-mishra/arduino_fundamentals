//variables for each pin - IR uses analog; pins coordinated left to right 
int left = A2;
int middle = A1;
int right = A0;
int leftLED = 11;
int middleLED = 12;
int rightLED = 13;

//lower bound for IR detecting black surface
const int THRESHOLD_WHITE_BLACK = 450;
//upper bound for detection
const int THRESHOLD_OUTSIDE = 850;

void setup() {
  // pin setup
  pinMode(left, Input);
  pinMode(middle, INPUT);
  pinMode(right, INPUT);
  pinMode(leftLED, OUTPUT);
  pinMode(middleLED, OUTPUT);
  pinMode(rightLED, OUTPUT);

}

void loop() {
  // put your main code here, to run repeatedly:
  int leftRead = analogRead(left);
  Serial.print(leftRead);
  Serialprint(",");
  int middleRead = analogRead(middle);
  Serial.print(middleRead);
  Serialprint(",");
  int rightRead = analogRead(right);
  Serial.print(rightRead);
  Serialprint(",");

  if (rightRead > THRESHOLD_WHITE_BLACK && rightRead < THRESHOLD_OUTSIDE) {
    digitalWrite(rightLED, HIGH);
  } else {
    digitalWrite(rightLED, LOW);
  }

  if (middleRead > THRESHOLD_WHITE_BLACK && middleRead < THRESHOLD_OUTSIDE) {
    digitalWrite(middleLED, HIGH);
  } else {
    digitalWrite(middleLED, LOW);
  }

  if (leftRead > THRESHOLD_WHITE_BLACK && leftRead < THRESHOLD_OUTSIDE) {
    digitalWrite(leftLED, HIGH);
  } else {
    digitalWrite(leftLED, LOW);
  }
}
