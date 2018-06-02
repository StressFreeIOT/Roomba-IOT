//
// Created by MrWolvetech-ADMIN on 5/29/2018.
//

#ifndef ROOMBA_IOT_PILOT_H
#define ROOMBA_IOT_PILOT_H


class Pilot {
  public:
    //For sending via serial
    void serialMakeDataframe(Dataframe &data);
    void serialSendCommand(Dataframe &data);
  
    //For receiving via serial
    void serialCallback(Dataframe &data);
    void serialDeconstruct(Dataframe &data);
  
    //Communication with Roomba class
    
    
  private:
    Dataframe data{};
    int _angle, _speed;
    
    //Optional
    int _distance, int _angle;
};


#endif //ROOMBA_IOT_PILOT_H
