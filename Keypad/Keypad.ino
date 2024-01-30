#include <Keypad.h>

const byte ROWS = 4;
const byte COLS = 4;

char hexaKeys[ROWS][COLS] = {
  {'1','2','3','A'},
  {'4','5','6','B'},
  {'7','8','9','C'},
  {'*','0','#','D'}
};

byte rowPins[ROWS] = {D7, D6, D5, D4};
byte colPins[COLS] = {D3, D2, D1, D0};

Keypad customKeypad = Keypad( makeKeymap(hexaKeys), rowPins, colPins, ROWS, COLS); 

void setup(){
  Serial.begin(9600);
}
  
void loop(){
  char customKey = customKeypad.getKey();
  
  if (customKey){
    Serial.println(customKey);
  }
}

// KEYPAD  : NodeMCU
// ================
// ROW1 (8) : D7 (bebas, deklarasikan variable)
// ROW2 (7) : D6 (bebas, deklarasikan variable)
// ROW3 (6) : D5 (bebas, deklarasikan variable)
// ROW4 (5) : D4 (bebas, deklarasikan variable)
// COL1 (4) : D3 (bebas, deklarasikan variable)
// COL2 (3) : D2 (bebas, deklarasikan variable)
// COL3 (2) : D1 (bebas, deklarasikan variable)
// COL4 (1) : D0 (bebas, deklarasikan variable)
