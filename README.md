# Sparkonic
This branch is the part where the Arduino program file has been attached.

The code incorporates data inputs from 3 sensors and one electronic component: Gas sensor, Force sensor, Temperature sensor and the potentiometer respectively.
The potentiometer has been used in place of the rotary sensor at the gas stove.

Gas leak situations can be broadly of 3 types: 
1. Gas leaks when stove is off and no flame is there. Could be from anywhere in the connections.
2. Gas leaks when stove is kept on but no flame. [High chances, very high risk]
3.Gas leaks when the stove is on.

The first part of the code takes in data input from all the sensors and the whole code runs in the void loop method iterating itself every
ten seconds.

The code does two things after taking input from all sensors and storing the input values in the variables assigned.
First it checks for any gas leaks. Second, it keeps track of weight.

The main if block checks if the temperature sensor is on or not. This indicates flame presence over the burner of gas stove.
If the temperature sensor shows flame is present, gas sensor shows gas is sensed and the potentiometer also says gas stove is on,
then the case is gas leakage occurring when stove is in use. 

If the temperature sensor is off, it means no flame. There are two cases here. 
If the temp sensor is off, gas sensor detects gas and potentiometer indicates stove regulator knob is in the "On" postion, 
it means the gas stove is on but there is no flame. 
Then the weight of lpg would decrease pretty fast, and that is also checked in the if else statements.

The other case under temp sensor being off is gas sensor being on but potentiometer indicates stove is off. This means leakage
is occurring although stove is off.

So the three scenarios have been taken into consideration in this manner.
Since the gas sensor detection is being checked only after checking temperature sensor being on, this logic above would alone 
make the gas sensor dependent on the others. Hence, before all the checks, the gas sensor is checked first at the start.

The last if else block is in case the stove is off but gas sensor malfunctions and does not detect anything, but a change in weight 
means gas leakage. 

After the safety checks, the last part of the code [After displaying gas cylinder weight] checks the lpg gas weight to 
help notify the user if it has gone below any threshold value.

