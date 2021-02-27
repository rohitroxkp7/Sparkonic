float temp;
int tempPin = 0;
int gas = 0;
int val = 0;

void setup() {
   Serial.begin(9600);
}

void loop() {
   temp = analogRead(tempPin);
   // read analog volt from sensor and save to variable temp
   temp = temp * 0.48828125;
   // convert the analog volt to its temperature equivalent
  //Gas sensor:
  gas  = analogRead(A1);
  //Rotary
  val = analogRead(A3);
  
  
  delay(10000); // update sensors readings each ten seconds
}












