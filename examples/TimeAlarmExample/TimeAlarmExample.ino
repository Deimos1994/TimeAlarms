// Questions?  Ask them here:
// http://forum.arduino.cc/index.php?topic=66054.0

#include <TimeLib.h>
#include <time.h>
#include <TimeAlarms.h>
// add necessery ESP libs for wi-fi, etc.

bool alarmsSetOk = false;

void setup() {
  Serial.begin(9600);
  while (!Serial) ; // wait for Arduino Serial Monitor
}

void loop() {
  Alarm.delay(0); // handle alarms
  
  // ================ for ESP8266/ESP32
  // ============== set alarms only if got time sync
  if(time(nullptr) > 1546136826 && alarmsSetOk == false){
    Serial.println("===============================");
    Serial.println("Ok, got time...");
    Serial.println("Setting alarms...");
    Alarm.alarmRepeat(4,41,0, EveningAlarm);  // every day, call fun
     alarmsSetOk = true;
    }==============
}

// functions to be called when an alarm triggers:

void EveningAlarm() {
  Serial.println("Alarm: - turn lights on");
}


