
#define LED0 9
#define LED1 10

void setup() {
	pinMode(LED0, OUTPUT);
	pinMode(LED1, OUTPUT);
	digitalWrite(LED0, 0);
	digitalWrite(LED1, 0);
  randomSeed(analogRead(0));
	
	Serial.begin(9600);
  delay(9000);
}

void loop() {
	static uint8_t master_cnt = 0;
	// mod 10 counting.
	master_cnt++;
	if(master_cnt == 10){
		master_cnt = 0;
	}
	char txd = random(11)/10+48;//dodavanjem 48 pretvaramo int u char
	Serial.write(txd);
	if(txd=='1'){
	  delay(2000);
	  }

	// Blinking LED0 indicate Tx works.
	digitalWrite(LED0, txd & 1);

	// Read one byte from Slave.
	if(Serial.available()) {
		char rxd = Serial.read();

		// Blinking LED1 indicate Rx works.
		digitalWrite(LED1, rxd & 1);
	}
	delay(1000); // [ms]
}
