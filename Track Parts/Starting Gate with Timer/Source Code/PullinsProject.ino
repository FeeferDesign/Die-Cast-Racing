#include  <Wire.h>
#include  <LiquidCrystal_I2C.h>

LiquidCrystal_I2C lcd(0x27,20,4);  // set the LCD address to 0x27 for a 16 chars and 2 line display
#define LEDPIN 13
#define SENSORPIN 4

long end_time; // When Sensor 2 is triggered
long start_time; // When Sensor 1 is triggered
long elapsed_time; // End time minus start time

// variables will change:
int sensorState = 0, lastState=0;         // variable for reading the pushbutton status

void setup()
{
  lcd.init();                      // initialize the lcd 
  lcd.backlight(); 
  
  // initialize the LED pin as an output:
  pinMode(LEDPIN, OUTPUT);      
  // initialize the sensor pin as an input:
  pinMode(SENSORPIN, INPUT);     
  digitalWrite(SENSORPIN, HIGH); // turn on the pullup
  Serial.begin(9600);
}

void loop()
{
  readSensor();  
  
}
void readSensor(){
  // read the state of the pushbutton value:
  sensorState = digitalRead(SENSORPIN);
 
  // check if the sensor beam is broken
  // if it is, the sensorState is LOW:
  if (sensorState == LOW) {     
    // turn LED on:
    digitalWrite(LEDPIN, HIGH);  
  } 
  else {
    // turn LED off:
    digitalWrite(LEDPIN, LOW); 
  }
  
  if (sensorState && !lastState) {
    Serial.println("Unbroken");
    DisplayStatus("Unbroken");    
  } 
  if (!sensorState && lastState) {
    Serial.println("Broken");
    DisplayStatus("Broken");    
  }
  lastState = sensorState;
}

void DisplayStatus(String msg){
  lcd.clear();
  lcd.print(msg);
  }
