const int dry = 645; // value for dry sensor
const int wet = 300; // value for wet sensor

void setup() {
  Serial.begin(9600);
}

void loop() {
  int sensorVal = analogRead(A0);

  int percentageHumididy = map(sensorVal, wet, dry, 100, 0);

  Serial.println("value: " + String(sensorVal) + " percent : " + String(percentageHumididy) + "%");

  delay(1000);
}


// SENSOR : NodeMCU
// ================
// GND  : GND
// VCC  : 3V
// AOUT : A0 (wajib analog, deklarasikan)