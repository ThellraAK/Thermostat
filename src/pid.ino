//bool HeaterOn = false //Status of heater, default on startup, off

//unsigned long heaterontime = 0; //how long has the heater been running?
//unsigned long heaterontimeMIN = 0 //Whats the minimum time the heater should run?

//unsigned long heaterlastofftime = 0; //When did heater turn off?
//unsigned long heaterOFFmin = 0; //How long should the heater be off for min?

void PID() {
  if ( HeaterOn == false ) {
    if ( globalmillis - heaterlastofftime >= heaterOFFmin ){
      if ( average <= setpointL ) {
        HeaterOn = true;
        heaterontime = globalmillis;
        //Red();
      }
    }
  }
  if (HeaterOn == true) {
    if ( globalmillis - heaterontime >= heaterontimeMIN) {
      if ( average >= setpointH ) {
        HeaterOn = false;
        heaterlastofftime = globalmillis;
        //Blue();
      }
      }
    }
  }


