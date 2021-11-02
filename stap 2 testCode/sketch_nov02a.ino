const int pinLedA   = 12; // pin van LED A
const int pinLedB   = 11; // pin van LED B
const int pinKnopA  = 2; // pin van knop A
const int pinKnopB  = 3; // pin van knop B

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
