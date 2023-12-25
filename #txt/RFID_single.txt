/* Read RFID Tag with RC522 RFID Reader
 *  Made by miliohm.com
 */
 
#include <SPI.h>
#include <MFRC522.h>

constexpr uint8_t RST_PIN = D3;     // Configurable, see typical pin layout above
constexpr uint8_t SDA_PIN = D4;     // Configurable, see typical pin layout above

MFRC522 rfid(SDA_PIN, RST_PIN); // Instance of the class
MFRC522::MIFARE_Key key;

String tag;

void setup() {
  Serial.begin(9600);
  SPI.begin(); // Init SPI bus
  rfid.PCD_Init(); // Init MFRC522
}

void loop() {
  if ( ! rfid.PICC_IsNewCardPresent())
    return;
  if (rfid.PICC_ReadCardSerial()) {
    for (byte i = 0; i < 4; i++) {
      tag += rfid.uid.uidByte[i];
    }
    Serial.println(tag);
    tag = "";
    rfid.PICC_HaltA();
    rfid.PCD_StopCrypto1();
  }
}

// RFID : NODEMCU
// ==============
// SDA  : D4
// SCK  : D5
// MOSI : D7
// MISO : D6
// IRQ  : NOT CONNECTED
// GND  : GND
// RST  : D3
// 3.3V : 3V

// CATATAN
// Untuk RST dan SDA bebas di pin manapun
// Jika ingin multi rfid (lebih dari 1), semua pin RST sama, lalu pin SDA berbeda-beda (tiap rfid pasangkan di pin berbeda untuk SDA