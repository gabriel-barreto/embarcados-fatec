/*Acionador Pushbutton

 Desenvolvido para minicurso de embarcador da Fatec Itapetininga.
 Autor: Gabriel Barreto
 Email: barreto-gabriel@outlook.com

 Project:
 ***
 Clear all information (char) in EEPROM of Arduino.
 ***

 created 2016
 by gabriel-barreto <mailto:barreto-gabreil@outlook.com>
 Available in: https://github.com/gabriel-barreto/embarcados-fatec
 This example code is in the public domain.*/

#include <EEPROM.h>

void setup() {
  Serial.begin(9600);
  while(!Serial);
  Serial.write("Initializing..");
  char x = '\0';
  Serial.write("\nClear EEPROM content...");
  for (int i = 0; i < 1024; i++) {
    EEPROM.write(i, x);
    Serial.write("\nPostion: ");
    Serial.print(i);
    Serial.write(" - Clear!");
  }
  Serial.write("\nEEPOM is Clear!");
  delay(500);
  Serial.write("\nEnd");
}

void loop() {}
