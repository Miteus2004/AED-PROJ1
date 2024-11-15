#include "Slot.h"

using namespace std;

Slot::Slot(string uccode, string ccode, string weekday,string start,string duration, string type) {
    this->uccode = uccode;
    this->ccode = ccode;
    this->weekday = weekday;
    this->start = start;
    this->duration = duration;
    this->type = type;
}

string Slot::getuccode() {
    return this->uccode;
}
string Slot::getccode() {
    return this->ccode;
}
string Slot::getweekday(){
    return this->weekday;
}
string Slot::getstart(){
    return this->start;
}
string Slot::getduration(){
    return this->duration;
}
string Slot::gettype(){
    return this->type;
}
