# Thermostat
From the current folder this was in

pio run -t upload --upload-port /dev/ttyUSB0

This is assuming /dev/ttyUSB0 is where the arduino is plugged in at.

screen *WHEREITIS* 115200 (The baud rate, connects you)

control A, then K kills the tab the screen it's in, but then you have to kill the screen with sudo pkill screen

We have a working bootstrap, That's awesome, no matter when the thermostat has power restored, it should find a valid temp window and use it.

TODO:

Figure out TimeAlrms : https://github.com/PaulStoffregen/TimeAlarms
  I think what I could do is Save the main schedule in PROGMEM if the delay isn't too unreasonable, and then use TimeAlarms to set up the schedule for the rest of the day.
  Have a set TimeAlarms at midnight or something to rescan the PROGMEM schedule to set schedules for the rest of the day.
   TODO: Figure out if PROGMEM is acceptable for a startup time
      Function to have set up as an alarm easily, TOCHECK: Can Existing SchedBool be used, could provide a nifty failsafe as it already returns a bool, so if it fails we could go
      back into bootstrap mode to find a valid schedule Alarm.alarmRepeat(DayOfWeek, Hour, Minute, Second,  AlarmFunction); Even day of Week is acceptable is should be able to set up
      Using the space we aren't going to be using with schedule in PROGMEM  11 byte vs 9 byte, but could be much easier to change

       Note: With TimeAlarms must not use delay() only Alarms.delay();
