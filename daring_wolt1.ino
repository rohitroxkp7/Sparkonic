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
     Serial.println("no pressure");
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
  if(count==0){
    value=fsrForce+0;
  }
  
  if(gas>85)
  { Serial.println("Possible gas leak");}  /*In case other sensors fails,
  this ensures at least giving a warning. 
  */
  
  if(temp>44)
  {
    Serial.println("Flame on ");
    if(gas>85)
    {
      Serial.println("Gas presence in atmosphere detected ");
      if(val>0)
      {
        Serial.println("Flame on but gas presence in atmosphere detected. Switch off burners immediately");
      }
    }
  }
   else
   { 
     Serial.println("No flame detected");
    if(gas>85)
    { 
      if(val>0)
      {
        
        if((fsrForce-value)<0)
        {
          Serial.println("Gas leakage confirmed. Check gas stove regulators immediately");
        }
      }
      else
      {
        Serial.println("Gas leakage detected");
      }
    }
  }
 
   if(temp<=44)
  {
    if((fsrForce-value)<0)
        {
          Serial.println("Possible gas leakage detected");
        }
  }
   
   
  count=count+1;
  
  
  
  Serial.println("Weight of Cylinder: ");
  Serial.println(fsrForce);
  if((fsrForce-weight)<1&&(fsrForce-weight)>0)
  {
    Serial.println("Cylinder is getting empty. Book a new cylinder asap");
  }
  if((fsrForce-weight)==0)
  {
    Serial.println("Cylinder is empty. Book a new cylinder immediately");
  }
  
  
  
  Serial.println();
  value=fsrForce;
  delay(10000); // update sensors readings each ten seconds
}












