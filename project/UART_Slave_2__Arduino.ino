#include <SoftwareSerial.h>
SoftwareSerial sim(5, 6);
#define LED0 9
#define LED1 10
int _timeout;
String _buffer;
String number = "+381621537295";

void setup() {
  delay(7000);
	pinMode(LED0, OUTPUT);
	pinMode(LED1, OUTPUT);
	digitalWrite(LED0, 0);
	digitalWrite(LED1, 0);
	
	Serial.begin(9600);
  _buffer.reserve(50);
  sim.begin(9600);
  delay(1000);
}

void loop() {
	// Read one byte from Slave 1.
	if(Serial.available()) {
		char rxd = Serial.read();
		
		// Blinking LED1 indicate Rx works.
		digitalWrite(LED1, rxd & 1);
    if(rxd=='1'){
      SendMessage();
      Serial.println("Motion detected, SMS should have been sent!");
      }
		// Loop it back to Master.
		Serial.write(rxd);
	}
	
	delay(50); // [ms]
	
	static uint8_t slave_cnt = 0;
	slave_cnt++;
	// Blinking LED0 indicate Slave.
	digitalWrite(LED0, slave_cnt & 1);
}

void SendMessage()
{
  //Serial.println ("Sending Message");
  sim.println("AT+CMGF=1");    //Sets the GSM Module in Text Mode
  delay(1000);
  //Serial.println ("Set SMS Number");
  sim.println("AT+CMGS=\"" + number + "\"\r"); //Mobile phone number to send message
  delay(1000);
  String SMS = "Motion detected!";
  sim.println(SMS);
  delay(100);
  sim.println((char)26);// ASCII code of CTRL+Z
  delay(1000);
  _buffer = _readSerial();
  Serial.println(_buffer); //debug line
  
}
String _readSerial() {
  _timeout = 0;
  while  (!sim.available() && _timeout < 12000  )
  {
    delay(13);
    _timeout++;
  }
  if (sim.available()) {
    return sim.readString();
  }
}
