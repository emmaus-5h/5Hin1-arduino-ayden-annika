const int pinLedA   = 12; // pin van LED A
const int pinKnopA  = 2; // pin van knop A


void setup() {
  pinMode(pinLedA, OUTPUT);

  // zet pinmode voor knoppen
  pinMode(pinKnopA, INPUT);
}

void loop() {
  // zet LedA aan/uit afhankelijk van stand van knopA
  if (digitalRead(pinKnopA) == LOW) {
    digitalWrite(pinLedA, LOW);
  } else {
    digitalWrite(pinLedA, HIGH);
  }

  
}
