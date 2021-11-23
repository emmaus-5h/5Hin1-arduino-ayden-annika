const int pinLedA   = 12; // pin van LED A
const int pinLedB   = 11; // pin van LED B
const int pinKnopA  = 2; // pin van knop A
const int pinKnopB  = 3; // pin van knop B
const int voorStart = 1;
const int Start = 2;
const int eind = 3; 
int toestand = 1;
int puntenA = 0;
int puntenB = 0;
/*****************************************
   setup()
 *****************************************/
void setup() {
  // enable console en stuur opstartbericht

  // zet pinmode voor leds
  pinMode(pinLedA, OUTPUT);
  pinMode(pinLedB, OUTPUT);

  // zet pinmode voor knoppen
  pinMode(pinKnopA, INPUT);
  pinMode(pinKnopB, INPUT);

  // zet LEDs aan
  digitalWrite(pinLedA, HIGH);
  digitalWrite(pinLedB, HIGH);

}

/*****************************************
   loop()
 *****************************************/
void loop() {
if (digitalRead(pinKnopA) == HIGH && digitalRead(pinKnopB) == HIGH){
  toestand = Start;
}
  if (toestand == voorStart){
    digitalWrite(11, HIGH);
    digitalWrite(12, HIGH);
    delay(1000);
    digitalWrite(11, LOW);
    digitalWrite(12, LOW);
    delay(1000);
  }
  if (toestand == Start){
    if (digitalRead(pinKnopA) == HIGH){
      if (digitalRead(pinKnopA) == LOW) {
        } puntenA = puntenA + 1;
    }
    if (digitalRead(pinKnopB) == HIGH){
      if (digitalRead(pinKnopB) == LOW) {
        } puntenB = puntenB + 1;
  }
  if (millis() > 10000){
    toestand = eind;
    }
  }

  if (toestand == eind){
    if (puntenA > puntenB) {
      digitalWrite(pinLedA, HIGH);
    } else {
      digitalWrite(pinLedB, HIGH);
      }
      if (puntenA == puntenB){
        digitalWrite(pinLedA, HIGH);
        digitalWrite(pinLedB, HIGH);
        }
    }
  // zet LedA aan/uit afhankelijk van stand van knopA
  if (digitalRead(pinKnopA) == LOW) {
    digitalWrite(pinLedA, LOW);
  } else {
    digitalWrite(pinLedA, HIGH);
  }

  // zet LedB aan/uit afhankelijk van stand van nopB
  if (digitalRead(pinKnopB) == LOW) {
    digitalWrite(pinLedB, LOW);
  } else {
    digitalWrite(pinLedB, HIGH);
  }

}
