#ifndef UNTITLED_SCHEDULE_H
#define UNTITLED_SCHEDULE_H
#include <iostream>
#include <string>
#include <set>
#include <vector>
#include <stack>

class Schedule{
public:
    Schedule(std::string uccode, std::string weekday, std::string start, std::string duration, std::string type);
    std::string getweekday();
    std::string getstart();
    std::string getduration();
    std::string gettype();
    std::string getuccode();
    std::string uccode;
    std::string weekday;
    std::string start;
    std::string duration;
    std::string type;
    static std::stack<Schedule> scheduleStack;
};
#endif //UNTITLED_SCHEDULE_H
