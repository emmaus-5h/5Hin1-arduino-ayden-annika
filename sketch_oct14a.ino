int toestand = 1;
int const buttonUit = 1;
int const buttonAan = 2;

void setup() {
  // put your setup code here, to run once:
pinMode(4, OUTPUT);
pinMode(5, OUTPUT);
pinMode(6, INPUT);
}

void loop() {
  // put your main code here, to run repeatedly:
if (toestand == buttonUit){
  if(digitalRead(6) == HIGH){
    digitalWrite(5, HIGH);
    toestand = buttonAan;
    }
  }
  if (toestand == buttonAan){
  if(digitalRead(6) == LOW){
    digitalWrite(5, LOW);
    toestand = buttonUit;
    }
  }
}
