# Smart Medication Box

## Overview

An Arduino-based Embedded Systems academic project that demonstrates proximity detection inside a medication box. An HC-SR04 ultrasonic sensor measures distance, and an LED and buzzer activate when the calculated distance is below 5 cm.

The implementation was reconstructed from the original project report and retains its measurement and alert behavior, with a small improvement to clear alerts after failed measurements.

## Hardware

- Arduino Uno
- HC-SR04 ultrasonic distance sensor
- LED with a current-limiting resistor
- Buzzer/speaker
- Breadboards and connecting wires
- USB cable and computer for power
- Plastic box used for the prototype

## Pin Configuration

| Component connection | Arduino Uno pin |
| --- | --- |
| HC-SR04 TRIG | D9 |
| HC-SR04 ECHO | D10 |
| LED control | D11 |
| Buzzer control | D6 |
| HC-SR04 VCC | 5V |
| Common ground | GND |

## How It Works

1. Start with the LED and buzzer off.
2. Hold TRIG LOW for 2 microseconds, then HIGH for 10 microseconds, then LOW again.
3. Measure the echo pulse with `pulseIn()` and calculate distance in centimeters as `echoDurationUs * 0.0344 / 2`.
4. Below 5 cm, keep the LED on and sound a 1000 Hz buzzer alert for 200 ms, followed by 200 ms of silence. At 5 cm or above, turn both outputs off.
5. Wait 100 ms after each valid measurement cycle before repeating.

If no valid echo is received, turn both outputs off, wait 500 ms, and retry. The additional 100 ms delay is skipped for failed measurements.

The report's examples show an alert at 4 cm and no alert at 7 cm. The sketch does not print distance readings.

## Project Structure

```text
.
├── README.md
├── .gitignore
└── src/
    └── smart_medication_box.ino
```

The original PDF report is not included in this repository.

## Implementation Notes

- Uses built-in Arduino functions without additional libraries.
- Named constants define the pins and the strict `< 5` cm threshold.
- Distance remains a `long`, preserving the original whole-centimeter calculation.
- The original blocking loop and timing are retained. Failed measurements now clear the previous alert state.
- No compilation or hardware testing was performed during repository cleanup.

## Limitations

- Proximity is only a demonstration of object presence; it does not confirm medication intake or identify medication.
- There is no dose scheduling or remote notification functionality.
- Fractional centimeters are discarded. Echo measurement and delays block further measurements, so the system does not respond continuously.
- A failed measurement disables the alert without a separate fault indicator.
- This is an academic prototype, not a medical device intended for clinical use.
