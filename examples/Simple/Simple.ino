#include <EasyEncoder.h>          //Include EasyEncoder library

EasyEncoder encoder;              //Create an instance of EasyEncoder class

void setup()
{
  pinMode(2, INPUT_PULLUP);       //Set both of encoder pins to INPUT_PULLUP for avoid any issues
  pinMode(3, INPUT_PULLUP);       //
  if (!encoder.begin(2, 3))       //If pins aren't on INPUT_PULLUP
    while (true);                 //Loop forever (REMINDER: If you don't begin the encoder, the check method returns -2 forever.)
  Serial.begin(9600);             //Begin the serial communication
}

int value = 0, previousValue = 0; //Declare variables

void loop()
{
  if (value != previousValue)     //If previousValue is net equal to value then
    Serial.println("New value: " + String(value)); //Print new value
  previousValue = value;          //Assign new value to previousValue
  value += encoder.check();       //Check if the encoder state changed
}