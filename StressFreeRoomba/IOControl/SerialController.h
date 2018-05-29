//
// Created by MrWolvetech-ADMIN on 5/29/2018.
//

#ifndef ROOMBA_IOT_SERIALCONTROLLER_H
#define ROOMBA_IOT_SERIALCONTROLLER_H

#include <string>

class SerialController {
public:
    SerialController(std::string devPath, int busSpeed);
    void sendMessage();
    std::string recvMessage();
    bool sendCommand(std::string command, std::string &result);
private:
    int _busspeed;
    std::string _devPath;

    bool openBus( std::string devPath);
    void setBusSpeed(int speed);
};


#endif //ROOMBA_IOT_SERIALCONTROLLER_H
