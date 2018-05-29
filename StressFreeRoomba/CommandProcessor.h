//
// Created by mrwolvetech on 5/29/18.
//

#ifndef ROOMBA_IOT_COMMANDPROCESSOR_H
#define ROOMBA_IOT_COMMANDPROCESSOR_H
#include <map>
#include <functional>
using commandfunction = std::function<void()>;
class CommandProcessor{
public:
    CommandProcessor();
    CommandProcessor(std::map<std::string, commandfunction> &commandMap);
    CommandProcessor(std::initializer_list<std::pair<const std::string, commandfunction>> commandMap);
    void executeCommand(const std::string &command, int input = 0);
    void addCommand(const std::string &command, commandfunction commandFunc);
private:
    std::map<std::string, commandfunction> commands_;

};


#endif //ROOMBA_IOT_COMMANDPROCESSOR_H
