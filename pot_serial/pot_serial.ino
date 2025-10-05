int POTpin = A0;

void setup() {
  // put your setup code here, to run once:
  pinMode(POTpin, INPUT);
  Serial.begin(9600);
}

void loop() {
  // put your main code here, to run repeatedly:
  int sensorValue = analogRead(POTpin);
  Serial.println(sensorValue);
  delay(50);
}
