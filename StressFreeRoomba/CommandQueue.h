//
// Created by MrWolvetech-ADMIN on 5/29/2018.
//

#ifndef ROOMBA_IOT_COMMANDQUEUE_H
#define ROOMBA_IOT_COMMANDQUEUE_H

#include "IOControl/Dataframe.h"

#include <queue>
#include <functional>
#include <condition_variable>
#include <thread>

using commandPair = std::pair<Dataframe, std::function<void(Dataframe)>>;

class CommandQueue: public std::thread {
private:
    std::queue<commandPair> queue;
    std::mutex mtx;
    std::condition_variable cv;
    void executeQueue();
    bool running{true};
public:
    CommandQueue(){
        thread::thread(executeQueue);
    }
    void push(Dataframe frame);
    void push(Dataframe frame, std::function<void(Dataframe)> callback);
    commandPair next();
    void join();

};


#endif //ROOMBA_IOT_COMMANDQUEUE_H
