float temp;
int tempPin = 0;
int gas = 0;
int val = 0;
int fsrPin = A2;     // the FSR and 10K pulldown are connected to A2
int fsrReading;     // the analog reading from the FSR resistor divider
int fsrVoltage;     // the analog reading converted to voltage
unsigned long fsrResistance;  // The voltage converted to resistance
unsigned long fsrConductance; 
long fsrForce;       // Finally, the resistance converted to force
int value = 0;
unsigned long T;
int count=0;
float weight=1; //Empty cylinder weight in N
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
   //Pressure sensor:
  fsrReading = analogRead(fsrPin); 
  // analog voltage reading ranges from about 0 to 1023 which maps to 0V to 5V (= 5000mV)
  fsrVoltage = map(fsrReading, 0, 1023, 0, 5000);
  if (fsrVoltage == 0) {
      
  } else {
    // The voltage = Vcc * R / (R + FSR) where R = 10K and Vcc = 5V
    // so FSR = ((Vcc - V) * R) / V        yay math!
    fsrResistance = 5000 - fsrVoltage;     // fsrVoltage is in millivolts so 5V = 5000mV
    fsrResistance *= 10000;                // 10K resistor
    fsrResistance /= fsrVoltage;
    fsrConductance = 1000000;           // we measure in micromhos so 
    fsrConductance /= fsrResistance;
  }
 
    
    if (fsrConductance <= 1000) {
      fsrForce = fsrConductance / 80;      
    } else {
      fsrForce = fsrConductance - 1000;
      fsrForce /= 30;          
    }
  
  
  delay(10000); // update sensors readings each ten seconds
}












