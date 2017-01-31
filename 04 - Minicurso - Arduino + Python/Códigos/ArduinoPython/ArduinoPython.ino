//DECLARANDO VARIÁVEIS
int g = 5; //LED VERDE - PORTA 5
int y = 6; //LED AMARELO - PORTA 6
int r = 7; //LED VERMELHO - PORTA 7

char op;

void setup() {
  //DEFININDO PORTAS 5,6,7 COMO SAÍDA.
  pinMode(r,OUTPUT);
  pinMode(g,OUTPUT);
  pinMode(y,OUTPUT);
  //INICIALIZANDO PORTA SERIAL
  Serial.begin(9600);
}

void loop() {
  //LENDO INFORMAÇÕES DO SERIAL
  digitalWrite(r,LOW);
  digitalWrite(g,LOW);
  digitalWrite(y,LOW);
  Serial.print('0');
  
  while(1) {
    op = Serial.read();
  //INICIANDO A COMPARAÇÃO DOS DADOS RECEBIDOS
    if (op == '7') {
    //ENVIANDO RETORNO
     Serial.print('7');
    //MUDANDO ESTADO DOS LEDS
      digitalWrite(r,HIGH);
      digitalWrite(y,LOW);
      digitalWrite(g,LOW);
    }
    else if (op == '4') {
      Serial.print('4');
      digitalWrite(r,LOW);
    }
    if (op == '6') {
    //ENVIANDO RETORNO
      Serial.print('6');
    //MUDANDO ESTADO DOS LEDS
      digitalWrite(r,LOW);
      digitalWrite(g,LOW);
      digitalWrite(y,HIGH);
    }
    else if (op == '3') {
      Serial.print('3');
      digitalWrite(y,LOW);
    }
    if (op == '5') {
      Serial.print('5');
    //MUDANDO ESTADO DOS LEDS
      digitalWrite(r,LOW);
      digitalWrite(y,LOW);
      digitalWrite(g,HIGH);
    }
    else if (op == '2') {
      Serial.print('2');
      digitalWrite(g,LOW);
    }
     if (op == '0') {
  //MUDANDO ESTADO DOS LEDS
      digitalWrite(r,LOW);
      digitalWrite(g,LOW);
      digitalWrite(y,LOW);
    //ENVIANDO RETORNO
      Serial.write('0');
    }
  }
}
