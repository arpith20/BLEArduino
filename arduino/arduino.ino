#include <SoftwareSerial.h>
#define LED_PIN 13
#define RELAY1 7
#define RELAY2 8

SoftwareSerial mySerial(2, 4); // RX, TX  
// Connect HM10 or HC08   Arduino Uno
//     Pin 1/TXD          Pin 2
//     Pin 2/RXD          Pin 4

void setup() {
  Serial.begin(9600);

  // If the baudrate of the HM-10 module has been updated,
  // you may need to change 9600 by another value
  // Once you have found the correct baudrate,
  // you can update it using AT+BAUDx command 
  // e.g. AT+BAUD0 for 9600 bauds
  mySerial.begin(9600);

  pinMode(RELAY1, OUTPUT);
  pinMode(RELAY2, OUTPUT);
}

void loop() {
  int c;

  if (mySerial.available()) {
    c = mySerial.read();
    Serial.println(c);
    Serial.println("Got input:");
    if (c == 48) {
      digitalWrite(RELAY2, 1);
    } 
    if (c == 49) {
      digitalWrite(RELAY2, 0);
    }
    if (c == 50) {
      digitalWrite(RELAY1, 1);
    }
    if (c == 51) {
      digitalWrite(RELAY1, 0);
    }
    delay(1000);
  }
}

