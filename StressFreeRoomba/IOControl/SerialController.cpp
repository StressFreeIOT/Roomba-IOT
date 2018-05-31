//
// Created by MrWolvetech-ADMIN on 5/29/2018.
//
#include <string>
#include <vector>
#include "SerialController.h"

//##############Public FUNCTIONS###########################
void SerialController::sendData(Dataframe frame) {
    frame.push_back(frame.getChecksum());
    _serialLink.write(frame);
}

Dataframe SerialController::recvData(int length) {
        std::vector<uint8_t> dt{};
        _serialLink.read(dt, length);
        return Dataframe(dt);
}

bool SerialController::sendCommand(Dataframe command, Dataframe &result) {
    Dataframe returnValue{};

    _serialLink.readWrite(command, returnValue, command.size());
    bool buff = result == returnValue;
    result = returnValue;
    return buff;
}








