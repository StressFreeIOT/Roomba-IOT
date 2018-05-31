//
// Created by MrWolvetech-ADMIN on 5/29/2018.
//

#include "Pilot.h"


  
void Pilot::serialSendCommand(Dataframe &data){

}

void serialCallback(Dataframe &data){
  
}
      
void serialMakeDataframe(Dataframe &data){
  /* Add bytes
  137   drive
  ?     speed high
  ?     speed low
  ?     radius high
  ?     radius low
  */
  
  //Limits
  int speed = min(max(_speed, MIN_SPEED), MAX_SPEED); //-500 to 500 mm/s
  int radius = min(max(_radius, MIN_RADIUS), MAX_RADIUS); //-2000 to 2000 mm/s
  
  //Check for special cases
  if (_radius == radiusStraight){
    radius = 32767;
  }
  if (_radius == radiusRotateCW){
    radius = 65535;
  }
  if (_radius == radiusRotateCW){
    radius = 1;
  }
  
  //Deconstruct data
  std::vector<uint8_t, 2> speedData{};
  std::vector<uint8_t, 2> radiusData{};
  
  speedData.at(0) = (speed & 0x000000FF) << 8;
  speedData.at(1) = speed & 0x000000FF;
  
  radiusData.at(0) = (radius & 0x000000FF) << 8;
  radiusData.at(1) = radius & 0x000000FF;
  
  //Make dataframe
  data.push_back(137);
  data.push_back(speedData.at(0));
  data.push_back(speedData.at(1));
  data.push_back(radiusData.at(0));
  data.push_back(radiusData.at(1));
}  
