//
// Created by jens on 11-2-18.
//

#include <iostream>
#include "Dataframe.h"

/********************************************//**
 *  \brief Constructs a empty dataframe
 *         Constructs a empty dataframe, not very useful
 ***********************************************/
Dataframe::Dataframe(){
    for (auto &a:data){
        a = 0;
        std::cout << a << std::endl;
    }
    setChecksum();
}

/********************************************//**
 *  \brief Constructs a data frame with the provided array
 *  @param array Array to construct data frame with.
 ***********************************************/
Dataframe::Dataframe(const std::array<uint8_t, 255> &array){
    data = array;
    setChecksum();
}

/********************************************//**
 *  \brief Generates the checksum
 *  @returns checksum in uint8_t
 ***********************************************/
uint8_t Dataframe::genChecksum(){
    uint8_t checksum = 0;
    for (auto i = data.begin()+1; i != data.end(); ++i){
        checksum += *i;
    }
    return ((uint8_t)256 - checksum);
}

/********************************************//**
 *  sets checksum, self generating
 ***********************************************/
void Dataframe::setChecksum(){
    int lastPacket = data[1] + 1;
    data[lastPacket] = genChecksum();
}

/********************************************//**
 *  checks is data frame is correct
 *  @returns bool
 *          (true) == correct
 *          (false) == incorrect
 ***********************************************/
const bool Dataframe::checksumIsCorrect(){
    uint8_t checksum = 0;
    for (auto i = data.begin()+1; i != data.end() - 1; ++i){
        checksum += *i;
    }
    checksum = ((uint8_t)256 - checksum);
    return(checksum == data[data[1] + 2]);
}

/********************************************//**
 *  Prints data frame to cout
 ***********************************************/
void Dataframe::show(){
    for(auto &a:data){
        std::cout << std::to_string(a) << " ";
    }
    std::cout << std::endl;
}