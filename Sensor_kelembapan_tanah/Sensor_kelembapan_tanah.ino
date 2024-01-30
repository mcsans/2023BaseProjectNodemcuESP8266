int digital = D0;
int analog = A0;

const int dry = 1024; // value for dry sensor
const int wet = 512; // value for wet sensor

void setup() {
  Serial.begin(9600);
  pinMode(digital, INPUT);
  pinMode(analog, INPUT);
}

void loop() {
  int sensorValDigital = digitalRead(digital);
  int sensorValAnalog = analogRead(analog);

  int percentageHumididy = map(sensorValAnalog, wet, dry, 100, 0);

  Serial.println("digital: " + String(sensorValDigital) + " analog: " + String(sensorValAnalog) + " percent : " + String(percentageHumididy) + "%");

  delay(1000);
}


// SENSOR : NodeMCU
// ================
// VCC : 3V
// GND : GND
// DO  : D0 (bebas, deklarasikan)
// AO  : A0 (wajib analog, deklarasikan)
