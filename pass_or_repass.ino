/*
  Acionador Pushbutton

 Desenvolvido para minicurso de embarcador da Fatec Itapetininga.
 Data: 24 de Setembro de 2016
 Autor: Gabriel Barreto
 Email: barreto-gabriel@outlook.com

 Circuito:
 * 3 LED (Yellow, Green, Red)
 * 3 Pushbuttons
 * 3 10K resistors
 * 1 Buzzer (Piezo Speaker)

 Ports:
 * Yellow LED on Port 7
 * Green LED on Port 3
 * Red LED on Port 11
 * Pushbuttons on Ports 2, 12, 8
 * Buzzer on Port 5

 Project:
 ***
 When button was pressed to trigger the corresponding LED,
 preventing other to fire waiting for the project due to the 
 reset.
 Order to act as a trigger to a set of questions and answers.
 ***

 created 2016
 by gabriel-barreto <mailto:barreto-gabreil@outlook.com>
 Available in: https://github.com/gabriel-barreto/embarcados-fatec
 This example code is in the public domain. */

#define ledA 3
#define buttonA 2

#define ledB 11
#define buttonB 12

#define ledReset 7
#define buttonReset 8

#define bzz 5

int buttonA_read = 0;
int buttonB_read = 0;
int buttonReset_read = 0;

void setup() {
  pinMode(ledA, OUTPUT);
  pinMode(ledB, OUTPUT);

  pinMode(buttonA, INPUT);
  pinMode(buttonB, INPUT);
  pinMode(buttonReset, INPUT);

  pinMode(bzz, OUTPUT);
  
  pinMode(ledReset, OUTPUT);
  
  digitalWrite(ledReset, LOW);
  
  digitalWrite(bzz, HIGH);
  delay(250);
  digitalWrite(bzz, LOW);
  delay(250);
  digitalWrite(bzz, HIGH);
  delay(250);
  digitalWrite(bzz, LOW);
  delay(250);
  digitalWrite(bzz, HIGH);
  delay(300);
  digitalWrite(bzz, LOW);

  Serial.begin(9600);
}

void loop() {

  buttonA_read = digitalRead(buttonA);
  buttonB_read = digitalRead(buttonB);
  
  
  if (buttonA_read == HIGH) {
    Serial.write('A');
    digitalWrite(ledA, HIGH);
    digitalWrite(ledReset, HIGH);
    digitalWrite(bzz, HIGH);
    delay(500);
    digitalWrite(bzz, LOW);
    while(true) {
      buttonReset_read = digitalRead(buttonReset);
      if(buttonReset_read == HIGH) {
        digitalWrite(bzz, HIGH);
        delay(75);
        digitalWrite(bzz, LOW);
        digitalWrite(ledA, LOW);
        digitalWrite(ledReset, LOW);
        break;
      }
    }
  } else if (buttonB_read == HIGH) {
    Serial.write('B');
    digitalWrite(ledB, HIGH);
    digitalWrite(ledReset, HIGH);
    digitalWrite(bzz, HIGH);
    delay(500);
    digitalWrite(bzz, LOW);
    while(true) {
      buttonReset_read = digitalRead(buttonReset);
      if(buttonReset_read == HIGH) {
        digitalWrite(bzz, HIGH);
        delay(75);
        digitalWrite(bzz, LOW);
        digitalWrite(ledB, LOW);
        digitalWrite(ledReset, LOW);
        break;
      }
    }   
  }
}
