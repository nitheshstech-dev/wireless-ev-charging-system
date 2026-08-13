/*
  Wireless EV Charging Prototype — Low-Voltage Monitoring
  --------------------------------------------------------
  Measures a voltage-divider output and an analog current-sensor output.

  Safety:
  - Do not connect Arduino/ESP32 ADC pins directly to high voltage.
  - Recalculate the divider ratio for the actual resistor values.
  - This sketch is telemetry only; it is not a high-power charging controller.
*/

const int VOLTAGE_PIN = A0;
const int CURRENT_PIN = A1;
const float ADC_REF = 5.0;
const int ADC_MAX = 1023;

// Example only. Recalculate for your hardware.
const float VOLTAGE_DIVIDER_RATIO = 5.0;

void setup() {
  Serial.begin(9600);
}

float readReceiverVoltage() {
  int raw = analogRead(VOLTAGE_PIN);
  float adcVoltage = (raw * ADC_REF) / ADC_MAX;
  return adcVoltage * VOLTAGE_DIVIDER_RATIO;
}

void loop() {
  float receiverVoltage = readReceiverVoltage();
  int currentRaw = analogRead(CURRENT_PIN);

  Serial.print("Receiver Voltage: ");
  Serial.print(receiverVoltage, 2);
  Serial.print(" V | Current sensor ADC: ");
  Serial.println(currentRaw);

  delay(500);
}
