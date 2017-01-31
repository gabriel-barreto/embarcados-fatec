#define gLed 5
#define rLed 6
#define yLed 7

void setup() {
	pinMode(gLed, OUTPUT);
	pinMode(rLed, OUTPUT);
	pinMode(yLed, OUTPUT);
	Serial.begin(9600);
	while(!Serial);
}

void loop() {
	char op;
	if (Serial.available()) {
		op = Serial.read();
		if (op == '5') {
			digitalWrite(gLed, HIGH);
			Serial.write('5');
		}
		else if (op == '6') {
			digitalWrite(rLed, HIGH);
			Serial.write('6');
		}
		else if (op == '7') {
			digitalWrite(yLed, HIGH);
			Serial.write('7');
		}
		else if (op == '0') {
			digitalWrite(gLed, LOW);
			digitalWrite(rLed, LOW);
			digitalWrite(yLed, LOW);
			Serial.write('0');
		}
	}
}