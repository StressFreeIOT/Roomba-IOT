//
// Created by MrWolvetech-ADMIN on 5/29/2018.
//

#include "Pilot.h"

Pilot::Pilot(){
  std::cout << "Pilot made" << std::endl;
}

Pilot::Pilot(int speed, int angle){
  std::cout << "Pilot made" << std::endl;
  pilotDrive(speed, radius);
}

void Pilot::serialConstructDataframe(Dataframe &data, int type){
  if (type == _formatDrive){
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
    if (_radius == radiusRotateCCW){
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

    return 0;  
  } else if (type == _formatData){
    /* Add bytes
    19   distance
    20   angle
    */

    //Make dataframe
    data.push_back(19);
    data.push_back(20);

    return 0;
  } else {
    return -1;
  }  
}
  
void Pilot::serialSendCommand(Dataframe &data){

}

void Pilot::serialCallback(Dataframe &data){
  
}
      
int Pilot::serialDeconstructDataframe(Dataframe &data){
   //19 for distance -> gives signed 16-bit variable, msb first
   //20 for angle -> gives signed 16-bit variable, msb first
  
   //Check for checksum
   if (!data.checksumIsCorrect()){
      return -1;
   }  
  
   //Get data
   short distance = 0, angle = 0;
  
   //Comment by Bert
   //Is the opcode sent back? If so the data bytes must be changed to the correct ones
  
   distance = data.at(1);
   distance += (data.at(0) << 8) & 0xFF00;
   
   angle = data.at(3);
   angle += (data.at(2) << 8) & 0xFF00;  
  
   //Add data to previous      
   _distance += distance;
   _angle += angle;
           
   return 0;
}  

void Pilot::pilotDrive(int speed, int radius){
  //Set variables
  _speed = speed;
  _radius = radius;
  
  //Construct dataframe
  serialConstructDataframe(data);
  
  //Send command
  serialSendCommand(data);
}  

    
void Pilot::pilotData(int &distance, int &angle){
  //Construct dataframe
  serialConstructDataframe(data);
  
  //Send command
  serialSendCommand(data);
}
