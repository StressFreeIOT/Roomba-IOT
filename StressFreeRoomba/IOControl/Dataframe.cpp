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
 *  \brief Constructs a data frame with the provided vector
 *  @param vector Vector to construct data frame with.
 ***********************************************/
Dataframe::Dataframe(const std::vector<uint8_t> &vector){
    int index = 0;
    for (auto &a:vector){
        data[index++] = a;
    }
    for (;index <= 255; index++){
        data[index] = 0;
    }
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

/********************************************//**
 *  Returns a copy of the data in the dataframe
 ***********************************************/
const std::array<uint8_t, 255> Dataframe::getData() {
    return std::array<uint8_t, 255>();
}

/********************************************//**
 *  checks if 2 dataframes are equel
 *  @returns bool
 *          (true) == equel
 *          (false) == not equel
 ***********************************************/
bool Dataframe::compare(Dataframe dataframe2) {
    const std::array<uint8_t, 255> data2 = dataframe2.getData();
    for(int i = 0; i <= 255; i++){
        if(data2[i] != data[i]) {
            return false;
        }
    }
    return true;
}
