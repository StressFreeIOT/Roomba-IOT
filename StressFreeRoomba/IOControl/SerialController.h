//
// Created by MrWolvetech-ADMIN on 5/29/2018.
//

#ifndef ROOMBA_IOT_SERIALCONTROLLER_H
#define ROOMBA_IOT_SERIALCONTROLLER_H

#include <string>
#include "../CommandQueue.h"
#include "../../_libUtils/SerialLink/SerialLink.h"
#include "Dataframe.h"

class SerialController {
private:
    SerialLink _serialLink;
public:
    SerialController(std::string devPath, int busSpeed): _serialLink(devPath, busSpeed){}
    void sendData(Dataframe frame);
    Dataframe recvData(int length);
    bool sendCommand(Dataframe command, Dataframe &result);
    void Shutdown();
};


#endif //ROOMBA_IOT_SERIALCONTROLLER_H
