/*EEPROM WriteChar

 Desenvolvido para minicurso de embarcador da Fatec Itapetininga.
 Autor: Gabriel Barreto
 Email: barreto-gabriel@outlook.com

 Project:
 ***
 Store information (char) in EEPROM of Arduino.
 ***

 created 2016
 by gabriel-barreto <mailto:barreto-gabreil@outlook.com>
 Available in: https://github.com/gabriel-barreto/embarcados-fatec
 This example code is in the public domain.*/

#include <EEPROM.h>

//variables
char readSerial;
char x;

void setup() {
  Serial.begin(9600);
  while(!Serial);
  Serial.write("Initializing..");
  char x = '\0';
  Serial.write("\nAll Ready!");
  delay(500);
  Serial.write("\nSTART!");
  delay(500);
  Serial.write("\nPlease, inform a char: ");
  Serial.write("\n");
}

void loop() {
  Serial.write('.');
  if(Serial.available()) {
    readSerial = Serial.read();
    x = EEPROM.read(0);
    int i = 0;
    while(x != '\0') {
      i++;
      x = EEPROM.read(i);
    }
    EEPROM.write(i, readSerial);
    delay(1000);
    if ((EEPROM.read(i)) == readSerial) {
      Serial.write("\nSuccess!");
      Serial.write("\nWrite ");
      Serial.write(readSerial);
      Serial.write(" in position ");
      Serial.print(i);
      Serial.write(" of EEMPROM");
      Serial.write("\n");
    }
    else {
      Serial.write("\nFail!");
      Serial.write("\n");
    }
  }
  delay(1000);
}
