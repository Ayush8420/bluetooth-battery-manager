#include "Arduino.h"
#include <SoftwareSerial.h>

const byte rxPin = 9;
const byte txPin = 8;
const byte relayPin = 7;

SoftwareSerial BTSerial(rxPin, txPin);

void setup() {
  pinMode(LED_BUILTIN, OUTPUT);
  pinMode(rxPin,INPUT);
  pinMode(txPin,OUTPUT);
  pinMode(relayPin,OUTPUT);
  BTSerial.begin(9600);
  Serial.begin(9600);

}


int dataByte;

void loop() {

if(BTSerial.available() > 0){
  dataByte = BTSerial.read();
  Serial.println(dataByte);

  if(dataByte == 'A'){
    digitalWrite(LED_BUILTIN, HIGH);
    digitalWrite(relayPin, HIGH);
  }
  
  if(dataByte == 'B'){
    digitalWrite(LED_BUILTIN, LOW);
    digitalWrite(relayPin, LOW);
  }
}

}
