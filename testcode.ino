const int pinLedA   = 13; // pin van LED A
const int pinLedB   = 12; // pin van LED B
const int pinKnopA  = 2; // pin van knop A
const int pinKnopB  = 3; // pin van knop B

void setup() {
  // put your setup code here, to run once:
  pinMode(pinLedA, OUTPUT);
  pinMode(pinLedB, OUTPUT);

  // zet pinmode voor knoppen
  pinMode(pinKnopA, INPUT);
  pinMode(pinKnopB, INPUT);
}

void loop() {
  // put your main code here, to run repeatedly:
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
