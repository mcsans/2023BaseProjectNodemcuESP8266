#include <Servo.h>

Servo myservo;

void setup()
{
  myservo.attach(D8);
}

void loop()
{
  int sudut = 0;

  while (sudut <= 180)
  {
    myservo.write(sudut);
    sudut = sudut + 15;

    delay(100);
  }
}

// SERVO  : NodeMCU
// ================
// KUNING : D8 (pin bebas karena dijadikan variable)
// MERAH  : 3V
// COKLAT : GND