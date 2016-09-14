//#include <MemoryFree.h>
#include <avr/pgmspace.h>
#include "schedulesglobal.h" //This is where you store the schedules



long SERIALSPEED = 115200; // Serial speed
float average = 0; //Declared here so we can access average temp globally
float h = 0; //Declared here so humidity is available globally as well
unsigned long globalmillis = 0;
unsigned long dhtmillis = 0;
unsigned long pidmillis = 0;
unsigned long Serialprintmillis = 0;
unsigned long Serialprintdelay = 0;
//unsigned long Schedule_Caller_millis = 0;
//unsigned long Schedule_delay_millis = 0;


//Below is How often to take temp, and how many to average from
//Number of numReadings * tempreadingdelay == How many millis for a completely new temperature to happen
const int numReadings = 3; //keep this many for averaging
const unsigned int tempreadingdelay = 2000; // can't be less than 2k due to AM2302 limits


// Below this are heating variables
//unsigned long PIDdelay = 30000 //Not checking until average has had a chance to change
int setpointH = 65;
int setpointL = 55;
bool HeaterOn = false; //Status of heater, default on startup, off

unsigned long heaterontime = 0; //how long has the heater been running?
unsigned long heaterontimeMIN = 300000 ; //Whats the minimum time the heater should run?

unsigned long heaterlastofftime = 0; //When did heater turn off?
unsigned long heaterOFFmin = 600000; //How long should the heater be off for min?



void setup() {
  globalmillis = millis();
  Serial.begin(SERIALSPEED);
  tempsetup();
  timesetup();

}

void loop() {
  globalmillis = millis();
  tempread();
  SERIALPRINT();
  PID();
  if (HeaterOn == true){
    Red();
  }
  if (HeaterOn == false){
    Black();
  }
if (validschedule  == false){
  Schedule_Caller();
  }
}


