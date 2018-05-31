//
// Created by MrWolvetech-ADMIN on 5/29/2018.
//

#ifndef ROOMBA_IOT_PILOT_H
#define ROOMBA_IOT_PILOT_H


class Pilot {
  public:
    void serialMakeDataframe(Dataframe &data);
    void serialSendCommand(Dataframe &data);
  
    void serialCallback(Dataframe &data);
    void 
    
  
  
  private:
    Dataframe data{};
    int _angle, _speed;
  
    int _distance, int _angle;
};


#endif //ROOMBA_IOT_PILOT_H
