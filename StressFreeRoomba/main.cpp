/*
Authors
@ Wesley Werter     585233
@ Jens Wolvers      575542
@ Bert van Rossem   584395
@ Lars van Lent     579960
*/

#include <iostream>
#include "AppInfo.h"
#include "IOControl/Dataframe.h"
#include "CommandQueue.h"

Dataframe startCommand({128});
Dataframe safeCommand({130});
//Initialize queue...
CommandQueue queue;

void exiting() {
    std::cout << "Exiting";
    queue.join();
}

int main(int argc, char *argv[]) {
    std::atexit(exiting);
    std::cout << "Firmware version: " << APPNAME << VERSION << std::endl;
    std::cout << "Application has started" << std::endl;

    //Send Start Command
    queue.push(startCommand);
    //Send safe mode command
    queue.push(safeCommand);

    return 0;
}
