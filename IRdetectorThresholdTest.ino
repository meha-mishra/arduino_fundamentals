const int RIGHT = A0;
const int MIDDLE = A1;
const int LEFT = A2;

void setup() {
  // put your setup code here, to run once:
  pinMode(RIGHT, INPUT);
  pinMode(LEFT, INPUT);
  pinMode(MIDDLE, INPUT);
  // The line below is important for debugging
  Serial.begin(9600);
}

void loop() {
  // put your main code here, to run repeatedly:
  int middlePin = analogRead(MIDDLE);
  Serial.print( middlePin);
  Serial.print (", ");
  int rightPin = analogRead(RIGHT);
  Serial.print(rightPin);
  Serial.print (", ");
  int leftPin = analogRead(LEFT);
  Serial.println(leftPin);
  delay(250);
}
