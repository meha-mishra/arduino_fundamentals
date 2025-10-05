int LEDpin = 13;

void setup() { 
  pinMode(LEDpin, OUTPUT);

  // put your setup code here, to run once:

}

void loop() {
  digitalWrite(LEDpin, HIGH);
  delay(250);
  digitalWrite(LEDpin, LOW);
  delay(250);
  // put your main code here, to run repeatedly:

}
