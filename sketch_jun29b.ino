#define PAN_STEP 18
#define PAN_DIR 19

#define TILT_STEP 21
#define TILT_DIR 22

void stepMotor(int stepPin) {
  digitalWrite(stepPin, HIGH);
  delayMicroseconds(700);
  digitalWrite(stepPin, LOW);
  delayMicroseconds(700);
}

void setup() {
  Serial.begin(115200);

  pinMode(PAN_STEP, OUTPUT);
  pinMode(PAN_DIR, OUTPUT);

  pinMode(TILT_STEP, OUTPUT);
  pinMode(TILT_DIR, OUTPUT);
}

void loop() {
  while (Serial.available()) {
    char c = Serial.read();

    switch (c) {
      case 'L':
        digitalWrite(PAN_DIR, LOW);
        stepMotor(PAN_STEP);
        break;

      case 'R':
        digitalWrite(PAN_DIR, HIGH);
        stepMotor(PAN_STEP);
        break;

      case 'U':
        digitalWrite(TILT_DIR, HIGH);
        stepMotor(TILT_STEP);
        break;

      case 'D':
        digitalWrite(TILT_DIR, LOW);
        stepMotor(TILT_STEP);
        break;
    }
  }
}