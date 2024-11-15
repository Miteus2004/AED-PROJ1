#include "ClassandUc.h"

ClassAndUC:: ClassAndUC(std::string classCode, std::string ucCode){
    this->classCode = classCode;
    this->ucCode = ucCode;
}

std::string ClassAndUC:: getClassCode() const
{
    return this->classCode;
}
std::string ClassAndUC:: getUcCode() const
{
    return this->ucCode;
}

bool ClassAndUC::operator<(const ClassAndUC& c) const {
    return this->getUcCode() > c.getUcCode();
}

