//
// Created by MrWolvetech-ADMIN on 5/29/2018.
//

#ifndef ROOMBA_IOT_BATTERYCHECKER_H
#define ROOMBA_IOT_BATTERYCHECKER_H

typedef struct{
  unsigned int chargingState;
  unsigned int voltage_mV;
  unsigned int current_mA;
  int temperatureCelsius;
  unsigned int batteryCharge;
  unsigned int batteryCapacity;
  int batteryLevel;
  int newData;
} battery_info_t;  

class BatteryChecker {
  public:
    //Constructor
    BatteryChecker();
  
    //For sending via serial
    void serialConstructDataframe(Dataframe &data);
    void serialSendCommand(Dataframe &data);
  
    //For receiving via serial
    void serialCallback(Dataframe &data);
    void serialDeconstructDataframe(Dataframe &data);
  
    //Communication with Roomba class
    battery_level_t batteryCheckerGetLevel();
  
  private:
    volatile battery_info_t _batteryInfo;
};

#endif //ROOMBA_IOT_BATTERYCHECKER_H
