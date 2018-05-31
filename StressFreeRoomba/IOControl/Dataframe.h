//
// Created by MrWolvetech-ADMIN on 5/29/2018.
//

#ifndef ROOMBA_IOT_DATAFRAME_H
#define ROOMBA_IOT_DATAFRAME_H

#include <array>
#include <vector>

class Dataframe : public std::vector<uint8_t>{
public:
    Dataframe();
    Dataframe(const std::vector<uint8_t> &vector);
    const bool checksumIsCorrect();
    const int getChecksum();
    void show();
private:
    uint8_t genChecksum();
    int _checksum;
};

#endif //ROOMBA_IOT_DATAFRAME_H
