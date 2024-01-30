#define relay D0

void setup() {
  // put your setup code here, to run once:
  pinMode(relay, OUTPUT);
}

void loop() {
  // put your main code here, to run repeatedly:
  digitalWrite(relay, HIGH);
  delay(5000);

  digitalWrite(relay, LOW);
  delay(5000);
}


// RELAY : NodeMCU
// ===============
// VCC : 3V
// GND : GND
// IN  : D0 (bebas, deklarasikan)


// WATER PUMP : RELAY : NodeMCU
// ============================
//            :  NO   :   5V
//     RED    :  COM  :
//    BLACK   :       :   GND