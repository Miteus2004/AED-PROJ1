#include "Student.h"

using namespace std;

Student::Student(string name,string upcode){
    this->name = name;
    this->upcode = upcode;
}
Student::Student(std::string uccode, std::string ccode, std::string upcode){
    this->uccode = uccode;
    this->ccode = ccode;
    this->upcode = upcode;
}
UC::UC(std::string uCode) {
    this->uCode = uCode;
}
Student::Student(){}
Class::Class(std::string classCode) {
    this->classCode = classCode;
}
string Class::getclassCode() {
    return this->classCode;
}
string Student::getccode() {
    return this->ccode;
}
string Student::getuccode() {
    return this->uccode;
}
string Student::getname() const{
    return this->name;
}
string UC::getUC() const{
    return this->uCode;
}
string Student::getupcode(){
    return this->upcode;
}
pair<UC,Class> Student::createpair(UC u1, Class c1){
    return make_pair(u1, c1);
}
ostream& operator<<(std::ostream& os, const UC& uc) {
    os << uc.uCode;
    return os;
}
ostream& operator<<(std::ostream& os, const Class& c) {
    os << c.classCode;
    return os;
}


bool Student::operator<(const Student& s) const {
    return this->getname() < s.getname();
}

bool UC::operator<(const UC& uc) const {
    return this->getUC() < uc.getUC();
}
