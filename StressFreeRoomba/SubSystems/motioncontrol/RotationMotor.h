//
// Created by MrWolvetech-ADMIN on 5/29/2018.
//

#ifndef ROOMBA_IOT_ROTATIONMOTOR_H
#define ROOMBA_IOT_ROTATIONMOTOR_H


#include "CommandProcessor.h"
#include "../../../_libMQTT/CommandProcessor.h"

class RotationMotor{
public:
    RotationMotor();
    const int getRPM();
    const int incRPM();
    const int decRPM();
    void restart();
    void shutdown();
    void start();
    CommandProcessor commandProcessor;
private:
    int rpm;
    int started;
    static const int MAX_RPM = 6000;
    static const int MIN_RPM = -3500;
    static const int INC_RPM = 500;
};


#endif //ROOMBA_IOT_ROTATIONMOTOR_H
