#include <Time.h>         //http://www.arduino.cc/playground/Code/Time  

void SERIALPRINT() {
  if (validschedule  == false){
 return;
}
 
  //validschedule  = false;
//  if (validschedule == true){
//    Serialprintdelay = 0;
//}
//  digitalClockDisplay();
  if (globalmillis - Serialprintmillis <= Serialprintdelay) return;
  Serialprintmillis = globalmillis;
  digitalClockDisplay();  
  //byte displaybyte;
  //displaybyte =  pgm_read_byte_near(schedules + Schedule_index);
  //Serial.print("Byte of schedule +0:");
  //Serial.println(displaybyte);
  //Serial.print("Schedule Index Number: ");
  //Serial.println(Schedule_index);
  //digitalClockDisplay();
//  Serial.print("Index Loop Time: ");
//  Serial.println(IndexLoopTime);
//  Serialprintmillis = globalmillis;
  Serial.println(average);
  Serial.print(setpointL, DEC);
  Serial.print("-");
  Serial.println(setpointH, DEC);
/*
  if (validschedule  == true ){
    Serial.println("A Valid Schedule was found");
  }
  else {
    Serial.println("NO VALID SCHEDULE FOUND");
}
*/
  validschedule  = false;
  //Serial.println(Schedule_index);
//  Serial.println(failcount);
//  Serial.println(hitcount, DEC);
//  Serial.println(changed);
//  hitcount = 0;
//  failcount = 0;
//  changed = 0;
//  Serial.println(F("F: AVERAGE"));
//
  setTime(now()+60);
//  delay(500);
//  validschedule = false;
//  Serialprintdelay = 1000;
//  Serial.println(freeMemory());




  
  }

