#define TRIG 5

void setup() {
  // put your setup code here, to run once:
  pinMode(TRIG,INPUT);
  Serial.begin(9600);
  delay(10000);
}

void loop() {
  // put your main code here, to run repeatedly:
  if(digitalRead(TRIG)==HIGH){
      Serial.println("Motion detected!");
      while(digitalRead(TRIG)==HIGH);
      Serial.println("Motion ended!");
    }

    
}
