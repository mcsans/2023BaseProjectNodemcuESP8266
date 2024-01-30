#define ldr_pin_digital_do D0
#define ldr_pin_analog_ao A0

void setup() {
  Serial.begin(9600);
}

void loop() {
  delay(1000);

  Serial.println("");
  Serial.println("digital : " + String(digitalRead(ldr_pin_digital_do))); // digital hanya mengeluarkan output 1 atau 0
  Serial.println("Analog  : " + String(analogRead(ldr_pin_analog_ao)));
}

// LDR : NodeMCU
// =============
// VCC : 3V
// GND : GND
// DO  : D0 (bebas, deklarasikan variable)
// AO  : A0 (bebas, deklarasikan variable)