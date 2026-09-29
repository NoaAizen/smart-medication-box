const int TRIGGER_PIN = 9;
const int ECHO_PIN = 10;
const int LED_PIN = 11;
const int BUZZER_PIN = 6;
const int ALERT_THRESHOLD_CM = 5;

void setup() {
  pinMode(TRIGGER_PIN, OUTPUT);
  pinMode(ECHO_PIN, INPUT);
  pinMode(LED_PIN, OUTPUT);
  pinMode(BUZZER_PIN, OUTPUT);

  digitalWrite(LED_PIN, LOW);
  noTone(BUZZER_PIN);
}

void loop() {
  while (true) {
    // Send a 10 us trigger pulse after a 2 us LOW period.
    digitalWrite(TRIGGER_PIN, LOW);
    delayMicroseconds(2);
    digitalWrite(TRIGGER_PIN, HIGH);
    delayMicroseconds(10);
    digitalWrite(TRIGGER_PIN, LOW);

    // Measure the echo pulse duration in microseconds.
    long echoDurationUs = pulseIn(ECHO_PIN, HIGH);

    if (echoDurationUs == 0) {
      delay(500);
      continue;
    }

    // Convert round-trip time to whole centimeters using 0.0344 cm/us.
    long distanceCm = echoDurationUs * 0.0344 / 2;

    // Below 5 cm, keep the LED on and sound a 200 ms, 1 kHz beep.
    if (distanceCm < ALERT_THRESHOLD_CM) {
      digitalWrite(LED_PIN, HIGH);
      tone(BUZZER_PIN, 1000);
      delay(200);
      noTone(BUZZER_PIN);
      delay(200);
    } else {
      digitalWrite(LED_PIN, LOW);
      noTone(BUZZER_PIN);
    }

    delay(100);
  }
}
