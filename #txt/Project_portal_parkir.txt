#include <Servo.h>

int infrared = D0;
int servo = D1;
int val = 0;

Servo myservo;

void setup()
{
  pinMode(infrared, INPUT);
  myservo.attach(servo);
}

void loop()
{
  val = digitalRead(infrared);

  if (val == LOW)
  {
    myservo.write(180); // Buka portal
    delay(5000);
  }
  else
  {
    myservo.write(0); // Tutup portal
  }

  delay(100);
}

// INFRARED : NODEMCU
// ==================
// OUT : D0 (bebas, deklarasikan variable)
// GND : GND
// VCC : 3V

// SERVO : NodeMCU
// ===============
// KUNING : D1 (bebas, deklarasikan variable)
// MERAH  : 3V
// COKLAT : GND