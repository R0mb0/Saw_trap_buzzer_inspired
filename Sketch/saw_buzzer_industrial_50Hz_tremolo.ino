// Industrial buzzer with 50Hz tremolo effect (AC simulation)
// PWM output on D3, pushbutton on pin 10 to toggle on/off
// Version: translated to English

const int PIN_BUZZER = 3;
const int PIN_BUTTON = 10;

// Buzzer frequency pattern
const int freqPattern[] = {1029, 735, 1176, 1029, 735, 1176};
const int PATTERN_LEN = sizeof(freqPattern) / sizeof(freqPattern[0]);

const int SWITCH_MS = 2;        // Change frequency every 2 ms (fast pattern)
const int MOD_50HZ_MS = 10;     // Every 10 ms simulate the 50Hz "pulse" (half-cycle)

bool buzzerActive = false;
bool lastBtnState = LOW;

void setup() {
  pinMode(PIN_BUZZER, OUTPUT);
  pinMode(PIN_BUTTON, INPUT);
  Serial.begin(9600);
  Serial.println("Industrial buzzer test with 50Hz tremolo. Button on pin 10 to toggle ON/OFF.");
}

void loop() {
  bool btnState = digitalRead(PIN_BUTTON);

  // Toggle buzzer ON/OFF on button press (rising edge)
  if (btnState == HIGH && lastBtnState == LOW) {
    buzzerActive = !buzzerActive;
    Serial.println(buzzerActive ? "Buzzer ACTIVATED." : "Buzzer DEACTIVATED.");
    delay(250); // simple debounce
  }
  lastBtnState = btnState;

  static unsigned long lastSwitch = 0;
  static unsigned long lastMod50Hz = 0;
  static int patternIndex = 0;
  static bool tremoloOn = true;

  if (buzzerActive) {
    unsigned long now = millis();

    // Every 10 ms simulate the 50Hz effect by toggling tremolo on/off
    if (now - lastMod50Hz >= MOD_50HZ_MS) {
      tremoloOn = !tremoloOn;
      lastMod50Hz = now;
    }

    // If tremolo is ON, step through the fast frequency pattern every SWITCH_MS
    if (tremoloOn && (now - lastSwitch >= SWITCH_MS)) {
      lastSwitch = now;
      tone(PIN_BUZZER, freqPattern[patternIndex]);
      patternIndex++;
      if (patternIndex >= PATTERN_LEN) patternIndex = 0;
    }

    // If tremolo is OFF, silence the buzzer to simulate the negative half-cycle
    if (!tremoloOn) {
      noTone(PIN_BUZZER);
    }
  } else {
    noTone(PIN_BUZZER);
  }
}