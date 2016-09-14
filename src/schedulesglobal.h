
/* Sunday = 1
 *  Monday = 2
 *  Tuesday = 3
 *  Wednesday = 4
 *  Thursday = 5
 *  Friday = 6
 *  Saturday = 7
 */

/*
 * In Schedules, each 9 byte block is a schedule event
 * First byte is a True/False if it is in fact a schedule (To allow empty ones) True is 255 False is anything else, 255 should not be used anywhere in the schedule.
 * Start Day [1-7], Start_Hour, Start_Minute, Setpoint_High, Setpoint_low, End_Day, End_Hour, End_Minute
 * A
 ***BLANK TEMPLATE** 
 ***ALL SCHEDULES MUST END BY Saturday at 11:59 PM
  255, // Is a entry
  0,//Day of Week
  0,//Start Hour (24)
  0,//Start Minute
  55, //High Setpoint on Thermostat
  50, //Low Setpoint on Thermostat
  0, //Day to End things
  0, //Hour to End Things
  0, //Minute to End Things
 *
 */
bool validschedule;
//unsigned long changed = 0;
//unsigned long hitcount = 0;
//unsigned long totalseconds;
//unsigned long failcount = 0;
int Schedule_index = 0 ;
int Schedule_index_Max = 459; //This should equal what schedules was created with minus one (Index is zero)
//int currentusedindex = 0;

//unsigned long IndexLoopTime  = 0;
//unsigned long Indexloopmillis  = 0;
const byte PROGMEM  schedules[459] =
{

  255, 1, 0, 0, 55, 50, 1, 8, 0,
  255, 1, 8, 0, 55, 60, 1, 9, 0,
  255, 1, 9, 0, 60, 65, 1, 10, 0,
  255, 1, 10, 0, 66, 72, 1, 22, 0,
  255, 1, 22, 0, 55, 50, 1, 23, 60,
  255, 2, 0, 0, 55, 50, 2, 6, 0,
  255, 2, 6, 0, 70, 65, 2, 7, 45,
  255, 2, 7, 45, 65, 60, 2, 10, 0,
  255, 2, 10, 0, 55, 50, 2, 16, 45,
  255, 2, 16, 45, 60, 55, 2, 17, 20,
  255, 2, 17, 20, 65, 60, 2, 17, 30,
  255, 2, 17, 30, 72, 67, 2, 21, 15,
  255, 2, 21, 15, 68, 62, 2, 22, 0,
  255, 2, 22, 0, 55, 50, 2, 23, 60,
  255, 3, 0, 0, 55, 50, 3, 6, 0,
  255, 3, 6, 0, 70, 65, 3, 7, 45,
  255, 3, 7, 45, 65, 60, 3, 10, 0,
  255, 3, 10, 0, 55, 50, 3, 16, 45,
  255, 3, 16, 45, 60, 55, 3, 17, 20,
  255, 3, 17, 20, 65, 60, 3, 17, 30,
  255, 3, 17, 30, 72, 67, 3, 21, 15,
  255, 3, 21, 15, 68, 62, 3, 22, 0,
  255, 3, 22, 0, 55, 50, 3, 23, 60,
  255, 4, 0, 0, 55, 50, 4, 6, 0,
  255, 4, 6, 0, 70, 65, 4, 7, 45,
  255, 4, 7, 45, 65, 60, 4, 10, 0,
  255, 4, 10, 0, 55, 50, 4, 16, 45,
  255, 4, 16, 45, 60, 55, 4, 17, 20,
  255, 4, 17, 20, 65, 60, 4, 17, 30,
  255, 4, 17, 30, 72, 67, 4, 21, 15,
  255, 4, 21, 15, 68, 62, 4, 22, 0,
  255, 4, 22, 0, 55, 50, 4, 23, 60,
  255, 5, 0, 0, 55, 50, 5, 6, 0,
  255, 5, 6, 0, 70, 65, 5, 7, 45,
  255, 5, 7, 45, 65, 60, 5, 10, 0,
  255, 5, 10, 0, 55, 50, 5, 16, 45,
  255, 5, 16, 45, 60, 55, 5, 17, 20,
  255, 5, 17, 20, 65, 60, 5, 17, 30,
  255, 5, 17, 30, 72, 67, 5, 21, 15,
  255, 5, 21, 15, 68, 62, 5, 22, 0,
  255, 5, 22, 0, 55, 50, 5, 23, 60,
  255, 6, 0, 0, 55, 50, 6, 6, 0,
  255, 6, 6, 0, 70, 65, 6, 7, 45,
  255, 6, 7, 45, 65, 60, 6, 10, 0,
  255, 6, 10, 0, 55, 50, 6, 16, 45,
  255, 6, 16, 45, 55, 50, 6, 17, 20,
  255, 6, 17, 20, 55, 50, 6, 18, 0,
  255, 6, 18, 0, 72, 67, 6, 23, 60,
  255, 7, 0, 0, 55, 50, 7, 8, 0,
  255, 7, 8, 0, 65, 60, 7, 10, 0,
  255, 7, 10, 0, 72, 66, 7, 23, 60
  
};
//int place = 0;  
