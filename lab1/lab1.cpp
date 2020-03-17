#include <Arduino.h>

const int buttonPin = 2;
const int ledPin = 13;


int buttonState;
int lastButtonState = HIGH;


unsigned long lastDebounceTime = 0;
unsigned long debounceDelay = 200;

void setup() {
  pinMode(buttonPin, INPUT);
  pinMode(ledPin, OUTPUT);

  digitalWrite(ledPin, lastButtonState);
}

void loop() {

  int reading = digitalRead(buttonPin);
  if (reading != HIGH && (millis() - lastDebounceTime) > debounceDelay) {
    lastDebounceTime = millis();
    lastButtonState = !lastButtonState;
    digitalWrite(ledPin, lastButtonState);
  }
}
