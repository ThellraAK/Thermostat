//int setpointH = 70;
//int setpointL = 65;
/* Sunday = 1
 *  Monday = 2
 *  Tuesday = 3
 *  Wednesday = 4
 *  Thursday = 5
 *  Friday = 6
 *  Saturday = 7
 */

 /*
  * Sunday at 10PM - 5:30AM setpoint L50 H 55
  * Monday 5:30 AM - 730AM setpoint H72 L67
  * Monday 7:30 AM - 10 AM H65 L 60
  * Monday 10 AM - 4:45 PM L50 H55
  * Monday 445 PM 5:15PM L60 H 65
  * Monday 515 - 930 PM L 65 H 70
  * Monday 930 PM - Tuesday 530 AM L50 H55
  * 
  * Weekday 2, 3, 4, 5, 6  
  */

/*
 * Start_Day, Start_Hour, Start_Minute, Setpoint_High, Setpoint_Low, End_Day, End_Hour, End_Minute
 * 
 * 
 */
/*/
 * See schedulesglobal.h for details on the schedule.
 */
 
void Schedule_Caller(){
  bool valid;
  if (validschedule  == true ) return;

//  if (globalmillis -Schedule_Caller_millis <= Schedule_delay_millis) return;

  if (Schedule_index >= Schedule_index_Max){
    Schedule_index = 0;
//    IndexLoopTime = globalmillis - Indexloopmillis;
//    Indexloopmillis = globalmillis;
  }


//  Schedule_Caller_millis = globalmillis;

  int tocheckvalid = (int) pgm_read_byte_near(schedules + Schedule_index);
  if ( tocheckvalid != 255){
      Schedule_index += 1;
      return;
  }

  int SchedIndTemp = Schedule_index;

  byte Start_Day, Start_Hour, Start_Minute, Setpoint_High, Setpoint_Low, End_Day, End_Hour, End_Minute;
  Schedule_index += 1;
  Start_Day =  pgm_read_byte_near(schedules + Schedule_index);
  Schedule_index += 1;
  Start_Hour =  pgm_read_byte_near(schedules + Schedule_index);
  Schedule_index += 1;
  Start_Minute =  pgm_read_byte_near(schedules + Schedule_index);
  Schedule_index += 1;
  Setpoint_High =  pgm_read_byte_near(schedules + Schedule_index);
  Schedule_index += 1;
  Setpoint_Low =  pgm_read_byte_near(schedules + Schedule_index);
  Schedule_index += 1;
  End_Day =  pgm_read_byte_near(schedules + Schedule_index);
  Schedule_index += 1;
  End_Hour =  pgm_read_byte_near(schedules + Schedule_index);
  Schedule_index += 1;
  End_Minute =  pgm_read_byte_near(schedules + Schedule_index);
  Schedule_index = SchedIndTemp;
  valid = ScheduleBool(Start_Day, Start_Hour, Start_Minute, Setpoint_High, Setpoint_Low, End_Day, End_Hour, End_Minute);

  if (valid == true){
    validschedule = true;
}

  Schedule_index += 9;

  return;

}

void Schedule_Setup(){

}

//bool ScheduleBool(int Start_Day, int Start_Hour, int Start_Minute, int Setpoint_High, int Setpoint_Low, int End_day, int End_Hour, int End_Minute){
bool ScheduleBool(byte Start_Day, byte Start_Hour, byte Start_Minute, byte Setpoint_High, byte Setpoint_Low, byte End_day, byte End_Hour, byte End_Minute){

  if (Start_Day != weekday() ) return false;

  if ( hour() == Start_Hour && minute() >= Start_Minute ) {
      setpointH = Setpoint_High;
      setpointL = Setpoint_Low;
      return true;
  }
  if ( hour() == End_Hour && End_Minute > minute() ){
    /* 
     *  If It is the Start Hour, and the minute is greater than, or equal to, the start minute, we should set the setpoints
     */
    setpointH = Setpoint_High;
    setpointL = Setpoint_Low;
    return true;
  }
  if ( hour() > Start_Hour && hour() < End_Hour){
    /*
     * If it is the end hour, and the current minute is less than the end minute, start the setpoint 
     * Setting it to only less then to leave a minute to avoid schedule collisions.
     */
    setpointH = Setpoint_High;
    setpointL = Setpoint_Low;
    return true;
  }
  return false;
  
}

