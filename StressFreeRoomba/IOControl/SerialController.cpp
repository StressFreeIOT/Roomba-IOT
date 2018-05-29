//
// Created by MrWolvetech-ADMIN on 5/29/2018.
//
#include <string>
#include <vector>
#include "SerialController.h"

//##############Public FUNCTIONS###########################
void SerialController::sendData(Dataframe frame) {
    const std::array<uint8_t, 255> data = frame.getData();
    std::vector<uint8_t> dataVector(data.begin(), data.end());
    _serialLink.write(dataVector);
}

Dataframe SerialController::recvData(int length) {
        std::vector<uint8_t> dt{};
        _serialLink.read(dt, length);
        return Dataframe(dt);
}

bool SerialController::sendCommand(Dataframe command, Dataframe &result) {
    const std::array<uint8_t, 255> data = command.getData();
    std::vector<uint8_t> dataVector(data.begin(), data.end());
    std::vector<uint8_t> ot{};

    _serialLink.readWrite(dataVector, ot, dataVector.size());
    Dataframe returnValue(ot);
    bool buff = result.compare(returnValue);
    result = returnValue;
    return buff;
}








