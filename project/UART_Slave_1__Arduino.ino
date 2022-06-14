
#define LED0 9
#define LED1 10
#define TRIG 5
char trig;
void setup() {
  delay(7000);
	pinMode(LED0, OUTPUT);
	pinMode(LED1, OUTPUT);
  pinMode(TRIG,INPUT);
	digitalWrite(LED0, 0);
	digitalWrite(LED1, 0);
	trig='0';
	Serial.begin(9600);
  delay(1000);
}

void loop() {
	// Read one byte from Master.
	if(Serial.available()) {
		char rxd = Serial.read();
		trig='0';
		// Blinking LED1 indicate Rx works.
		digitalWrite(LED1, rxd & 1);
    if(rxd=='1'){
      delay(2000);
      if(digitalRead(TRIG)==HIGH){
        trig='1';
        while(digitalRead(TRIG)==HIGH);
        }
      }

		// Send trig value to second slave.
		Serial.write(trig);
	}
	
	delay(50); // [ms]
	
	static uint8_t slave_cnt = 0;
	slave_cnt++;
	// Blinking LED0 indicate Slave.
	digitalWrite(LED0, slave_cnt & 1);
}
