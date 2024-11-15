#ifndef UNTITLED_CLASSANDUC_H
#define UNTITLED_CLASSANDUC_H

#include <iostream>
#include <string>


class ClassAndUC{
public:
    std::string classCode;
    std::string ucCode;
    ClassAndUC(std::string classCode, std::string ucCode);
    std::string getUcCode() const;
    std::string getClassCode() const;
    bool operator<(const ClassAndUC& c) const;

};



#endif //UNTITLED_CLASSANDUC_H
