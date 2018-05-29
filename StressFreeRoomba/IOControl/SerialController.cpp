//
// Created by MrWolvetech-ADMIN on 5/29/2018.
//

#include "SerialController.h"

SerialController::SerialController(std::string devPath, int busSpeed) {

}

//##############PRIVATE FUNCTIONS#######################
bool SerialController::openBus(std::string devPath) {
    return false;
}

void SerialController::setBusSpeed(int speed) {

}

//##############Public FUNCTIONS###########################
void SerialController::sendMessage() {

}

std::string SerialController::recvMessage() {
    return std::__cxx11::string();
}

bool SerialController::sendCommand(std::string command, std::string &result) {
    return false;
}






