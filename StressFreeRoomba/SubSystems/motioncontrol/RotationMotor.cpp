//
// Created by jens on 11-2-18.
//

#include <cstdlib>
#include <exception>
#include <iostream>
#include "RotationMotor.h"
#include "../../CommandProcessor.h"

RotationMotor::RotationMotor() : rpm{0},
                                 started{false},
                                 commandProcessor{{{"start", std::bind(&RotationMotor::start, this)},
                                                          {"restart", std::bind(&RotationMotor::restart, this)},
                                                          {"shutdown", std::bind(&RotationMotor::shutdown, this)},
                                                          {"incRPM", std::bind(&RotationMotor::incRPM, this)},
                                                          {"decRPM", std::bind(&RotationMotor::decRPM, this)},
                                                          {"getRPM", std::bind(&RotationMotor::getRPM, this)}}} {
}

void RotationMotor::start(){
    started = true;
    std::cout << "starting..." << std::endl;
}

const int RotationMotor::getRPM(){
    if (!started){
        throw std::exception();
    }
    std::cout << rpm << std::endl;
    return rpm;
}

const int RotationMotor::incRPM(){
    if (!started){
        throw std::exception();
    }
    int temp_rpm = rpm + INC_RPM;
    if (temp_rpm > MAX_RPM){
        rpm = MAX_RPM;
    } else if (temp_rpm < MIN_RPM){
        rpm = MIN_RPM;
    } else{
        rpm = temp_rpm;
    }
    std::cout << rpm << std::endl;
    return rpm;
}

const int RotationMotor::decRPM(){
    if (!started){
        throw std::exception();
    }
    int temp_rpm = rpm - INC_RPM;
    if (temp_rpm > MAX_RPM){
        rpm = MAX_RPM;
    } else if (temp_rpm < MIN_RPM){
        rpm = MIN_RPM;
    } else{
        rpm = temp_rpm;
    }
    std::cout << rpm << std::endl;
    return rpm;
}

void RotationMotor::restart(){
    if (!started){
        throw std::exception();
    }
    std::cout << "restarting..." << std::endl;
    rpm = 0;
}

void RotationMotor::shutdown(){
    if (!started){
        throw std::exception();
    }
    std::cout << "shutting down..." << std::endl;
    rpm = 0;
    exit(0);
}