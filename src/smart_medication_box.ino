const int TRIGGER_PIN = 9;
const int ECHO_PIN = 10;

void setup() {
  pinMode(TRIGGER_PIN, OUTPUT);
  pinMode(ECHO_PIN, INPUT);
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

    delay(100);
  }
}
