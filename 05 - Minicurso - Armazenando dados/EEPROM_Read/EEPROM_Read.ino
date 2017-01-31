/*EEPROM Read

 Desenvolvido para minicurso de embarcador da Fatec Itapetininga.
 Autor: Gabriel Barreto
 Email: barreto-gabriel@outlook.com

 Project:
 ***
 Read information (char) in EEPROM of Arduino.
 ***

 created 2016
 by gabriel-barreto <mailto:barreto-gabreil@outlook.com>
 Available in: https://github.com/gabriel-barreto/embarcados-fatec
 This example code is in the public domain.*/

#include <EEPROM.h>

//variables
int i = 0;

void setup() {
  Serial.begin(9600);
  Serial.write("Initializing...");
  Serial.write("\nRead EEPROM content...");
  while(EEPROM.read(i) != '\0') {
    Serial.write("\nPosition: ");
    if(i < 10) {
      Serial.write('0');
    }
    Serial.print(i);
    Serial.write(" - Content: "); 
    Serial.write(EEPROM.read(i));
    i++;
  }
  delay(500);
  Serial.write("\nEnd EEPROM");
}

void loop() {}
