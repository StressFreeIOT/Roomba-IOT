//
// Created by MrWolvetech-ADMIN on 5/29/2018.
//

#ifndef ROOMBA_IOT_PILOT_H
#define ROOMBA_IOT_PILOT_H

class Pilot {
  public:
    //Constructor
    Pilot();
    Pilot(int speed, int angle);
  
    //For sending via serial
    void serialConstructDataframe(Dataframe &data, int type);
    void serialSendCommand(Dataframe &data);
  
    //For receiving via serial
    void serialCallback(Dataframe &data);
    void serialDeconstructDataframe(Dataframe &data);
  
    //Communication with Roomba class
    void pilotDrive(int speed, int radius);
    void pilotData(int &distance, int &angle);
    
    //Special cases
    static const int radiusStraight = 2001;
    static const int radiusRotateCW = 2002;
    static const int radiusRotateCCW = 2003;
  
  private:
    Dataframe data{};
    int _radius, _speed;
    
    //Optional
    int _distance, int _angle;
  
    static const int _formatDrive = 0, _formatData = 1;
};


#endif //ROOMBA_IOT_PILOT_H
