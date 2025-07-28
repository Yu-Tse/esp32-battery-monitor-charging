// Analog input pin for measuring battery voltage
const int batteryPin = 35;

// PWM output pin for controlling the base of S9014 transistor
const int pwmPin = 25;

// Analog input pin for measuring voltage drop across current-sense resistor
const int currentSensePin = 34;

// Voltage divider ratio: R1 = 10kΩ, R2 = 2.73kΩ
const float voltageDividerRatio = 2.73 / (10.0 + 2.73);

// Maximum voltage of fully charged Li-ion battery
const float maxBatteryVoltage = 3.84;

// Current sense resistor value (in ohms)
const float currentSenseResistor = 0.1;

void setup() {
  Serial.begin(115200);

  pinMode(26, OUTPUT);              // Control pin for external switch (always HIGH)
  pinMode(batteryPin, INPUT);       // Battery voltage input
  pinMode(pwmPin, OUTPUT);          // PWM charging control
  pinMode(currentSensePin, INPUT);  // Current sensing input
}

void loop() {
  analogWrite(26, 4095); // Ensure external switch is always ON

  // Read battery voltage
  int analogValue = analogRead(batteryPin);
  float batteryVoltage = analogValue * 3.23 * voltageDividerRatio / 4095.0;

  // Read charging current via voltage drop across sense resistor
  int currentSenseValue = analogRead(currentSensePin);
  float currentVoltageDrop = currentSenseValue * 3.23 / 4095.0;
  float chargingCurrent = 1000 * currentVoltageDrop / currentSenseResistor; // Convert to mA

  // Display measured values
  Serial.print("Battery Voltage: ");
  Serial.print(batteryVoltage);
  Serial.print(" V, Charging Current: ");
  Serial.print(chargingCurrent);
  Serial.println(" mA");

  // Charging control logic
  if (batteryVoltage >= maxBatteryVoltage) {
    // Stop charging
    analogWrite(pwmPin, 0);
    Serial.println("Battery is fully charged. Stop charging.");
  } else {
    // Continue charging with dynamic PWM adjustment
    int pwmValue = map(batteryVoltage, 0, maxBatteryVoltage, 4095, 0);
    analogWrite(pwmPin, pwmValue);
    Serial.println("Battery is charging...");
  }

  delay(500); // Delay for 0.5 seconds before next measurement
}
