//
// Created by MrWolvetech-ADMIN on 5/29/2018.
//

#include "BatteryChecker.h"
#include <mutex>
#include <atomic>

//Mutex
std::mutex mtx;

BatteryChecker::BatteryChecker(){
  std::cout << "BatteryChecker started" << std::endl;
}  
  
void BatteryChecker::serialConstructDataframe(Dataframe &data){
  /* Add bytes
  21   charging state
  22   voltage
  23   current
  24   temperature
  25   charge
  26   capacity
  */

  //Make dataframe
  data.push_back(21);
  data.push_back(22);
  data.push_back(23);
  data.push_back(24);
  data.push_back(25);
  data.push_back(26);

  return 0;
}

void BatteryChecker::serialSendCommand(Dataframe &data){
  
}  
  
void BatteryChecker::serialCallback(Dataframe &data){
  
}

int BatteryChecker::serialDeconstructDataframe(Dataframe &data){
   /* Add bytes
   21   charging state  ->gives 1 unsigned byte
   22   voltage         ->gives 2 unsigned bytes
   23   current         ->gives 2 signed bytes
   24   temperature     ->gives 1 signed byte
   25   charge          ->gives 2 unsigned bytes
   26   capacity        ->gives 2 unsigned bytes
   */
  
    /*
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
    */
  
   //Check for checksum
   if (!data.checksumIsCorrect()){
      return -1;
   }  
 
   battery_info_t batteryInfo;
   
   batteryInfo.chargingState = data.at(0);
  
   batteryInfo.voltage_mV = data.at(2);
   batteryInfo.voltage_mV |= (data.at(1) << 8) & 0xFF00;
  
   short current = data.at(4);
   current |= (data.at(3) << 8) & 0xFF00;
   batteryInfo.current_mA = current;
  
   batteryInfo.temperatureCelsius = data.at(5);
  
   batteryInfo.batteryCharge = data.at(7);
   batteryInfo.batteryCharge |= (data.at(6) << 8) & 0xFF00;
  
   batteryInfo.batteryCapacity = data.at(9);
   batteryInfo.batteryCapacity |= (data.at(8) << 8) & 0xFF00;
  
   batteryInfo.batteryLevel = (100 * batteryInfo.batteryCharge) / batteryInfo.batteryCapacity;
  
   batteryInfo.newData = 1;
  
   lock_guard<mutex> lock(mtx);
   _batteryInfo = batteryInfo;
           
   return 0;
}  
  
//Communication with Roomba class
battery_level_t BatteryChecker::batteryCheckerGetInfo(){
  battery_level_t result = _batteryInfo;
  _batteryInfo.newData = 0;
  return result;
}
