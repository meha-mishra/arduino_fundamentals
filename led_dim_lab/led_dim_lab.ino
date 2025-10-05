int POTpin = A0;
int button = 12;
int PWMLEDpin = 3;
int numPresses = 0;


void setup() {
  // put your setup code here, to run once:
  pinMode(PWMLEDpin, OUTPUT);
  pinMode(button, INPUT);
  pinMode(POTpin, INPUT);
}

void loop() {
  // put your main code here, to run repeatedly:
  int buttonPressed = digitalRead(button);
  if (buttonPressed == 1){
    numPresses++;
    delay(200);
  Serial.begin(9600);
  }
  switch (numPresses % 3){
    case 0:
      digitalWrite(PWMLEDpin, LOW);
      Serial.println("off");
      break;
    case 1: 
      digitalWrite(PWMLEDpin, HIGH);
      Serial.println("on");
      break;
    case 2: 
      int POTpinValue = analogRead(POTpin);
      POTpinValue = map(POTpinValue, 0, 1023, 0, 255);
      analogWrite(PWMLEDpin, POTpinValue);
      Serial.print("dim");
      Serial.println(POTpinValue);
      break;
    
    }
  }


