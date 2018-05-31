//
// Created by jens on 11-2-18.
//

#include <iostream>
#include <string>
#include "Dataframe.h"

/********************************************//**
 *  \brief Constructs a empty dataframe
 *         Constructs a empty dataframe, not very useful
 ***********************************************/
Dataframe::Dataframe():std::vector<uint8_t>(){
    setChecksum();
}

/********************************************//**
 *  \brief Constructs a data frame with the provided vector
 *  @param array Array to construct data frame with.
 ***********************************************/
Dataframe::Dataframe(const std::vector<uint8_t> &vector):std::vector<uint8_t>(){
    setChecksum();
}

/********************************************//**
 *  \brief Generates the checksum
 *  @returns checksum in uint8_t
 ***********************************************/
uint8_t Dataframe::genChecksum(){
    uint8_t checksum = 0;
    for (auto &a:this){
        checksum += a;
    }
    this->_checksum = ((uint8_t)256 - checksum
    return _checksum;
}

/********************************************//**
 *  checks is data frame is correct
 *  @returns bool
 *          (true) == correct
 *          (false) == incorrect
 ***********************************************/
const bool Dataframe::checksumIsCorrect(){
    uint8_t checksum = 0;
    for (auto &a:this){
        checksum += a;
    }
    checksum = ((uint8_t)256 - checksum);
    return(checksum == this->_checksum);
}

/********************************************//**
 *  Prints data frame to cout
 ***********************************************/
void Dataframe::show(){
    for(auto &a:this){
        std::cout << std::to_string(a) << " ";
    }
    std::cout << std::endl;
}

const int Dataframe::getChecksum() {
    return _checksum;
}

