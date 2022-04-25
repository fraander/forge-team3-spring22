
#include <SPI.h>
#include <MFRC522.h>

#define RST_PIN 9
#define SS_PIN 8

MFRC522 mfrc522;

String tagID = ""; 

void setup() {
  // put your setup code here, to run once:
  Serial.begin(9600);
  while(!Serial);
  SPI.begin();

  mfrc522.PCD_Init(SS_PIN, RST_PIN);

}

void loop() {
  // put your main code here, to run repeatedly:
  getID();

  if (tagID != "") {
    Serial.println("ID: " + tagID); 
  }
}

/**
 * Make a reading if possible, #t if read, #f if nothing to read/could not read
 * @return - true if read, false if nothing to read/could not read
 */
boolean getID() {
    if (!mfrc522.PICC_IsNewCardPresent()) { // is there a card there to read?
        return false;
    }

    if (!mfrc522.PICC_ReadCardSerial()) { // can it be read?
        return false;
    }

    tagID = ""; // clear the tag id before it gets reassigned

    for (uint8_t i = 0; i < 4; i++) { // read the tag id
        tagID.concat(String(mfrc522.uid.uidByte[i], HEX));
    }

    tagID.toUpperCase(); // make the tag id uppercase

    mfrc522.PICC_HaltA(); // stop reading

    return true; // Yay! Read something
}
