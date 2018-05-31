//
// Created by MrWolvetech-ADMIN on 5/29/2018.
//

#ifndef ROOMBA_IOT_PILOT_H
#define ROOMBA_IOT_PILOT_H


class Pilot {
  public:
    void serialSendCommand(Dataframe &data);
    void serialCallback(Dataframe &data);
    void serialMakeDataframe(Dataframe &data);
  
  private:
    Dataframe data{};
    int _angle, _speed;
};


#endif //ROOMBA_IOT_PILOT_H
