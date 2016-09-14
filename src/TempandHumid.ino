#include "DHT.h"
#define DHTPIN 12     // what digital pin we're connected to
#define DHTTYPE DHT22   // DHT 22  (AM2302), AM2321
DHT dht(DHTPIN, DHTTYPE);
//const int numReadings = 30;


float readings[numReadings];      // the readings from the analog input
int readIndex = 0;              // the index of the current reading
float total = 0;                  // the running total
//float average = 0;                // the average

void tempsetup() {
  dht.begin();
  dhtmillis = millis();
  for (int thisReading = 0; thisReading < numReadings; thisReading++) {
    readings[thisReading] = 0;
    }
  float t = numReadings * 500;
  total = total - readings[readIndex];
  readings[readIndex] = t;
  total = total + readings[readIndex];
  readIndex = readIndex + 1;
  if (readIndex >= numReadings) {
    readIndex = 0;
  }
  average = total / numReadings;
  average =dht.readTemperature(true);
}

void tempread() {
  // Reading temperature or humidity takes about 250 milliseconds!
  // Sensor readings may also be up to 2 seconds 'old' (its a very slow sensor)
  if (globalmillis - dhtmillis < tempreadingdelay) {
    return;//Don't do a reading if less than 2k millis have passed.
  }
  
  dhtmillis = millis();
  h = dht.readHumidity();
  // Read temperature as Celsius (the default)
  float t = dht.readTemperature(true);
  // subtract the last reading:
  total = total - readings[readIndex];
  // read from the sensor:
  readings[readIndex] = t;
  // add the reading to the total:
  total = total + readings[readIndex];
  // advance to the next position in the array:
  readIndex = readIndex + 1;

  // if we're at the end of the array...
  if (readIndex >= numReadings) {
    // ...wrap around to the beginning:
    readIndex = 0;
  }

  // calculate the average:
  average = total / numReadings;
  if ( average >= 100 ){
    average = t;
    }


//  Serial.println(h);
//  Serial.println(t);
//  Serial.println(dhtmillis);
//  delay(100);

}
