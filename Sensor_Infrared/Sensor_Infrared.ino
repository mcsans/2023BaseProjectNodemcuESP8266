int inputPin = D0; // choose input pin (for Infrared sensor) 
int val = 0; // variable for reading the pin status

void setup() 
{ 
  Serial.begin(9600);
  pinMode(inputPin, INPUT); // declare Infrared sensor as input
}

void loop()
{ 
  val = digitalRead(inputPin); // read input value 

  // check if the input is HIGH
  if (val == LOW)
  {
    Serial.println("Objek Terdeteksi");
  } 

  delay(1000);
}

// INFRARED : NODEMCU
// ==================
// OUT : D0 (bebas, deklarasikan variable)
// GND : GND
// VCC : 3V