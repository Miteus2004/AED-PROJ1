#include "Schedule.h"


using namespace std;

Schedule::Schedule(string uccode, string weekday, string start, string duration, string type) {
    this->uccode = uccode;
    this->weekday = weekday;
    this->start = start;
    this->duration = duration;
    this->type = type;
}
string Schedule::getuccode() {
    return this->uccode;
}
string Schedule::getweekday(){
    return this->weekday;
}
string Schedule::getstart(){
    return this->start;
}
string Schedule::getduration(){
    return this->duration;
}
string Schedule::gettype(){
    return this->type;
}




