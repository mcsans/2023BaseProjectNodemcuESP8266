#include <LiquidCrystal_I2C.h>

#include <Wire.h>

LiquidCrystal_I2C lcd(0x27, 16, 2);

void setup() {

Serial.begin(115200);
Wire.begin(D1, D2);   // Use predefined PINS consts {SDA, SCL}
lcd.begin(20,4);      // The begin call takes the width and height. This
                      // Should match the number provided to the constructor.

lcd.backlight();      // Turn on the backlight.

lcd.home();

lcd.setCursor(3, 0);  // Move the cursor at origin
lcd.print("HELLO READERS,");
lcd.setCursor(0, 1);
lcd.print("Interfacing nodemcu");
lcd.setCursor(0, 2);
lcd.print("   with LCD 20X4.");
lcd.setCursor(0, 3);
lcd.print("     GOOD LUCK!");

}

void loop() {         

// do nothing here 

}

// LCD : NodeMCU
// =============
// GND : GND
// VCC : 3V / VIN (VIN lebih terang dan jelas)
// SDA : D1 (bebas di pin manapun karena dijadikan variable)
// SCL : D2 (bebas di pin manapun karena dijadikan variable)

