const int pinLedA   = 12; // pin van LED A
const int pinLedB   = 11; // pin van LED B
const int pinKnopA  = 2; // pin van knop A
const int pinKnopB  = 3; // pin van knop B
const int voorStart = 1;
const int Start = 2;
const int eind = 3;
const int aftellen = 4;
int toestand = 1;
int toestandKnop = 1;
const int uit_Los = 1;
const int aan_in = 2;
const int aan_Los = 3;
const int uit_in = 4;
int puntenA = 0;
int puntenB = 0;
int tijdBegin = 0;
int tijdNu = 0;
int tijd = 0;

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

tijdNu = millis();

  if (toestand == voorStart) {
       puntenA = 0;
       puntenB = 0;
    if (digitalRead(pinKnopA) == HIGH && digitalRead(pinKnopB) == HIGH) {
      digitalWrite(pinLedA, LOW);
      digitalWrite(pinLedB, LOW);
      toestand = aftellen;
    } else {
      digitalWrite(11, HIGH);
      digitalWrite(12, HIGH);
      delay(1000);
      digitalWrite(11, LOW);
      digitalWrite(12, LOW);
      delay(1000);
    }
  }
  if (toestand == aftellen) {
    digitalWrite(pinLedA, HIGH);
    delay(1000);
    digitalWrite(pinLedB, HIGH);
    delay(1000);
    digitalWrite(pinLedB, LOW);
    digitalWrite(pinLedA, LOW);
    tijdNu = 0;
    toestand = Start;

  }

  if (toestand == Start) {
    if (digitalRead(pinKnopA) == HIGH) {
      if (digitalRead(pinKnopA) == LOW) {
        puntenA = puntenA + 1;
      }
    }
    if (digitalRead(pinKnopB) == HIGH) {
      if (digitalRead(pinKnopB) == LOW) {
        puntenB = puntenB + 1;
      }
    }
    if ((tijdBegin - tijdNu) >= 10000) {
      tijdBegin = millis();
      toestand = eind;
    
    }
  }

  if (toestand == eind) {
    if (puntenA > puntenB) {
      digitalWrite(pinLedA, HIGH);
      delay(5000);
     
      toestand = voorStart;
    } else {
      digitalWrite(pinLedB, HIGH);
      delay(5000);
      
      toestand = voorStart;
    }
    if (puntenA == puntenB) {
      digitalWrite(pinLedA, HIGH);
      digitalWrite(pinLedB, HIGH);
      delay(5000);
      toestand = voorStart;
    }
  }
}
