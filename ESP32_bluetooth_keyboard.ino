#include <BleKeyboard.h>
BleKeyboard bleKeyboard("PEDAL_ESP32");

#define PIN_ARROW_DOWN 14
#define PIN_ARROW_UP 27

void setup() {
  Serial.begin(115200);
  
  pinMode(PIN_ARROW_DOWN, INPUT_PULLUP);
  pinMode(PIN_ARROW_UP, INPUT_PULLUP);
  
  bleKeyboard.begin();
}

void loop() {
  if (bleKeyboard.isConnected()) {
    if (digitalRead(PIN_ARROW_DOWN) == LOW) {
      bleKeyboard.press(KEY_DOWN_ARROW);
      delay(100);
      bleKeyboard.releaseAll();
    }
    if (digitalRead(PIN_ARROW_UP) == LOW) {
      bleKeyboard.press(KEY_UP_ARROW);
      delay(100);
      bleKeyboard.releaseAll();
    }
  }
}
