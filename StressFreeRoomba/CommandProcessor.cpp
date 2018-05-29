//
// Created by mrwolvetech on 5/29/18.
//
#include <iostream>
#include "CommandProcessor.h"

CommandProcessor::CommandProcessor(){}

CommandProcessor::CommandProcessor(std::map<std::string, commandfunction> &commandMap) : commands_{commandMap}{

}

CommandProcessor::CommandProcessor(std::initializer_list<std::pair<const std::string, commandfunction>> commandMap)
        : commands_{commandMap}{

}

void CommandProcessor::executeCommand(const std::string &command, int input){
    // p is an iterator
    auto p = commands_.find(command);
    if (p != end(commands_)){
        auto func = (*p).second;
        func();
    }else{
        std::cerr << "Command: " << input << " not found!" << std::endl;
    }
}

void CommandProcessor::addCommand(const std::string &command, commandfunction commandFunc){
    commands_.insert({command, commandFunc});
}