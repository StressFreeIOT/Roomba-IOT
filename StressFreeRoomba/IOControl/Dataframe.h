//
// Created by MrWolvetech-ADMIN on 5/29/2018.
//

#ifndef ROOMBA_IOT_DATAFRAME_H
#define ROOMBA_IOT_DATAFRAME_H

#include <array>
class Dataframe{
public:
    Dataframe();
    Dataframe(const std::array<uint8_t, 255> &array);
    const bool checksumIsCorrect();
    void show();
private:
    std::array<uint8_t, 255> data;
    uint8_t genChecksum();
    void setChecksum();
};

#endif //ROOMBA_IOT_DATAFRAME_H
