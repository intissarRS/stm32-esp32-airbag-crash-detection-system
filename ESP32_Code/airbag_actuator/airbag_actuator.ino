#include <Arduino.h>

#define LED_PIN 2
#define BUZZER_PIN 13

void setup() {
  Serial.begin(115200);        // Debugging to PC
  Serial2.begin(115200, SERIAL_8N1, 16, 17); // RX=16, TX=17
  pinMode(LED_PIN, OUTPUT);
  pinMode(BUZZER_PIN, OUTPUT);
}

void loop() {

  if (Serial2.available()) {
    String data = Serial2.readStringUntil('\n');
    data.trim();

    if (data == "DEPLOY") {
      Serial.println("Crash Signal Received! Activating Alerts...");
      executeAlert();
    }
  }
}

void executeAlert() {
  digitalWrite(LED_PIN, HIGH);
  tone(BUZZER_PIN, 1000); // 1kHz sound
  delay(2000);            // Alert duration
  noTone(BUZZER_PIN);
  digitalWrite(LED_PIN, LOW);
}
