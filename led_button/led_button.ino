int LEDpin = 13;
int button = 12;

void setup() { 
  pinMode(LEDpin, OUTPUT);
  pinMode(button, INPUT);

  // put your setup code here, to run once:

}

void loop() {
  int buttonPressed = digitalRead(button);
  if (buttonPressed == 1) {
    digitalWrite(LEDpin, HIGH);
   delay(250);
   digitalWrite(LEDpin, LOW);
   delay(250);
  }
  else {
    digitalWrite(LEDpin, LOW);
  }
  // put your main code here, to run repeatedly:

}