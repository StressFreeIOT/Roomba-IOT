//
// Created by MrWolvetech-ADMIN on 5/29/2018.
//

#include "CommandQueue.h"

//serial queue met callback functies
void CommandQueue::push(Dataframe frame, std::function<void(Dataframe)> callback) {
    std::unique_lock<std::mutex> lck(mtx);
    queue.push(std::pair(frame, callback));
    cv.notify_one();
}

void CommandQueue::push(Dataframe frame) {
    std::unique_lock<std::mutex> lck(mtx);
    queue.push(std::pair(frame, nullptr));
    cv.notify_one();
}

commandPair CommandQueue::next() {
    commandPair elem = nullptr;

    std::unique_lock<std::mutex> lck(mtx);
    cv.wait(lck, !queue.empty());

    if(!queue.empty()) {
        elem = queue.front();
        queue.pop();
    }

    return elem;
}

void CommandQueue::executeQueue() {
    while(running){

    }
}

void CommandQueue::join() {
    running = false;
    thread::join();
}


