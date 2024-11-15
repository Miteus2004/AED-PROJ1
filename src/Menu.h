#ifndef UNTITLED_MENU_H
#define UNTITLED_MENU_H

#include <iostream>
#include <set>
#include <string>
#include <fstream>
#include <sstream>
#include "Student.h"
#include "Slot.h"
#include "Schedule.h"
#include <list>
#include <limits>
#include "Data.h"

using namespace std;
class Menu {
public:
    void mainMenu(Data &objStudent);
    void run();
    void MenuUC();
    void MenuStudents(Data &obj);
    void readStudents(Data &obj);
    bool compareClassAndUC(const std::pair<ClassAndUC, Student>& a, const std::pair<ClassAndUC, Student>& b);
    void MenuSchedule(Data &obj);
    void Classfind();
    void Stfind();
    void readUC();
    void saveStudent(Data &obj);
    void UCcount();
    void resgisteredStudents(Data &obj);
    void request(Data &obj);
    void wait(Data &objStudent);
    vector<Slot>schedule;
    vector<pair<UC,Class>> classuc;
    vector<Student> student;
    set<UC> ucs;
    //vector<Slot>schedule;
    list<UC> ucs1;

};


#endif //UNTITLED_MENU_H
