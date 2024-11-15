#include "Data.h"
#include <utility>

void Data:: addAllStudents(Student student) {
    this->allStudents.insert(student);
    this->student.push_back(student);
}

void Data::addRequest(std:: string r){
    this->requestsmade.push(r);
}


void Data:: printRequest(){
    while (!requestsmade.empty()) {
        std:: string frontElement = requestsmade.front();
        std::cout << frontElement << " " << std::endl;

        requestsmade.pop();
    }


}
void Data:: printAllStudents(){

    for (auto x: allStudents){

        std:: cout << x.getname() << " " << x.getupcode() << std:: endl;
    }
}

void Data:: addStudentsClasses(ClassAndUC const classes, Student student)
{
    this->studentClasses.insert(std::pair<ClassAndUC, Student> (classes, student));
}

void Data:: addStudentsPerUc(){
    for(auto x: studentClasses){
        std::string temp = x.first.getUcCode();

        mStudentsPerUC.insert(std::pair <UC, int>(temp, ucOccupation(temp)));
    }
}
void Data:: addStudentsPerClass(){
    for(auto x : studentClasses)
    {
        mStudentsPerClass.insert(std::pair<ClassAndUC, int>(x.first , classOccupation(x.first.getClassCode())));
    }

}

void Data:: searchByUc(std::string UC){
    int found = 0;
    for(auto x: studentClasses)
    {
        if(x.first.getUcCode() == UC){
            std:: cout << x.second.getname() << std:: endl;
            found = 1;
        }
    }
    if (found == 0)
        std::cout << "Not Found" << std::endl;
}
void Data:: searchByClass(std::string class_, std::string uc){
    int found = 0;
    for(auto x: studentClasses)
    {
        if(x.first.getClassCode() == class_ and x.first.getUcCode() == uc){
            std:: cout << x.second.getname() << std:: endl;
            found = 1;
        }
    }
    if(found == 0)
        std::cout << "Not Found" << std::endl;
}
void Data::UCcount(Data &obj){
    int u = 0,p = 0,max = 0;
    for(auto x : student){
        u++;
        if(x != student[0]){
        if(x.getname() != student[u-2].getname()){
            std::pair<Student, int> studentPair1 = std::make_pair(x, p);
            p = 0;
            count.push_back(studentPair1);
        }
        p++;
        if(max < p){
            max = p;
        }
        }
    }

}
void Data::nNumbers(int o){
    int sum = 0;
    for(auto x : count){
        if(x.second >= o){
            sum++;
        }
    }
    std::cout << sum<< std::endl;
}
bool Student::operator!=(Student s){
    if(this->getname() != s.getname()){
        return true;
    }
    return false;
}

void Data::searchByYear(char year, int &n, int flag){
    std :: set<std::string> studentsyear;
    int found =0;
    for(auto x: studentClasses)
    {
        std::string class_  = x.first.getClassCode();
        if(class_[0] == year)
        {
            studentsyear.insert(x.second.getname());
            found = 1;
        }
    }
    if(flag == 0){
        for(auto x : studentsyear)
            std:: cout << x << std:: endl;
    }
    else
        n = studentsyear.size();
    if(found == 0)
        std::cout << "Not Found" << std::endl;
}

int Data:: ucOccupation(std::string uc){
    int count = 0;
    for (auto x: studentClasses){
        if (x.first.getUcCode() == uc)
            count++;
    }
    return count;
}

int Data:: classOccupation(std::string class_){
    int count = 0;
    std::set<std::string> s;
    for (auto x: studentClasses){
        if (x.first.getClassCode() == class_)
            s.insert(x.second.getupcode());
    }
    return s.size();

}

int Data::yearOccupation(char year){
    int n = 0;
    searchByYear(year, n, 1);
    return n;
}

void Data::nUcsWithStudentsPerUc(int n){
    std::vector<std::pair<UC, int>> studentsPerUC(mStudentsPerUC.begin(), mStudentsPerUC.end());
    std::sort(studentsPerUC.begin(), studentsPerUC.end(), [](const auto& a, const auto& b) {
        return a.second > b.second;
    });
    for (int i = 0; i < n && i < studentsPerUC.size(); i++) {
        std::cout << "UC : " << studentsPerUC[i].first << ", has " << studentsPerUC[i].second << " students" <<std::endl;
    }

}
void Data:: studentsPerClasses(std:: string Class){
    std::vector<std::pair<ClassAndUC, int>> studentPerClass(mStudentsPerClass.begin(), mStudentsPerClass.end());
    std::sort(studentsPerUC.begin(), studentsPerUC.end(), [](const auto& a, const auto& b) {
        return a.second > b.second;
    });
    for (int i = 0; i < i < studentsPerUC.size(); i++) {
        std::cout << "UC : " << studentsPerUC[i].first << ", has " << studentsPerUC[i].second << " students" <<std::endl;
    }
}
void Data::createschedulec(std::vector<std::pair<UC, Class>> classuc, std::vector<Slot> schedule, std::string cl){
    std::vector<Schedule> schedulef;
    for(auto x: classuc){
        if(x.second.getclassCode() == cl) {
            for (auto y: schedule) {
                if (y.getccode() == cl) {
                    Schedule sch = Schedule(y.getuccode(), y.getweekday(), y.getstart(), y.getduration(), y.gettype());
                    schedulef.push_back(sch);
                }
            }
            break;
        }
    }
    for(auto x : schedulef){
        std::cout<< x.getuccode() << " " << x.getweekday() << " " << x.getstart() << " " << x.getduration() << " " << x.gettype() << std::endl;
    }

}
void Data::createschedules(std::vector<Student> classucst, std::vector<Slot> schedule, std::string st){
    std::vector<Schedule> schedulef;
    for(auto x: classucst){
        if(x.getupcode() == st) {
            for (auto y: schedule) {
                if (y.getccode() == x.getccode() && y.getuccode() == x.getuccode()) {
                    Schedule sch = Schedule(x.getuccode(), y.getweekday(), y.getstart(), y.getduration(), y.gettype());
                    schedulef.push_back(sch);
                }
            }
        }
    }
    for(auto x : schedulef){
        std::cout<< x.getuccode() << " " << x.getweekday() << " " << x.getstart() << " " << x.getduration() << " " << x.gettype() << std::endl;
    }
}

int Data:: ucsPerStudent(std::string studentCode){
    int count = 0;
    for(auto x: studentClasses){
        if(x.second.getupcode() == studentCode)
            count++;
    }
    return count;
}

void Data::requestAddUc(std::string studentCode ,std::string new_uc ) {
    int ucs = ucsPerStudent(studentCode);
    std::string studentName;
    for(auto x: allStudents){
        if(studentCode == x.getupcode())
            studentName = x.getname();
    }

    for (auto x: studentClasses) {
        if (x.second.getupcode() == studentCode and x.first.getUcCode() == new_uc) {
            std::cout << "Request Denied: Student already enrolled in this UC" << std::endl;
            return;
        }
    }
    bool studentExists = 0;
    for (auto x: allStudents) {
        if (x.getupcode() == studentCode)
            studentExists = 1;
    }
    if (!studentExists)
        std::cout << "Request Denied: Student not found" << std::endl;

    if (ucs >= 7) {
        std::cout << "Request Denied: Student already enrolled in 7 UC's" << std::endl;
        return;
    }
    int spaceInClass = 0;
    std::list<ClassAndUC> availableClasses;
    //student can only be enrolled to class if there are less than 30 students in that class
    for (auto x: mStudentsPerClass) {
        if (x.first.getUcCode() == new_uc and x.second < 30) {
            availableClasses.push_back(x.first);
            spaceInClass++;
        }
    }
    if (spaceInClass == 0) {
        std::cout << "Request Denied: No Class with vacancies " << std::endl;
        return;
    }
    std:: cout << availableClasses.front().getClassCode() << std::endl;
    Student S = Student(studentName, studentCode);
    addStudentsClasses(availableClasses.front(), S);
    std:: cout << "Request accepted" << std:: endl;

    for (auto &x : studentsPerUC){
        if(x.first.getUC() == new_uc){
            x.second++;
            break;
        }
    }
    for (auto &x : mStudentsPerUC){
        if(x.first.getUC() == new_uc){
            x.second++;
            break;
        }
    }
}




void Data::requestAddClass(std::string studentCode ,std::string new_class, std::string new_uc ) {
    int ucs = ucsPerStudent(studentCode);
    std::string studentName;
    for (auto x: allStudents) {
        if (studentCode == x.getupcode())
            studentName = x.getname();
    }

    for (auto x: studentClasses) {
        if (x.second.getupcode() == studentCode and x.first.getUcCode() == new_uc) {
            std::cout << "Request Denied: Student already enrolled in this another Class of this UC" << std::endl;
            return;
        }
    }
    bool studentExists = 0;
    for (auto x: allStudents) {
        if (x.getupcode() == studentCode)
            studentExists = 1;
    }
    if (!studentExists)
        std::cout << "Request Denied: Student not found" << std::endl;

    int spaceInClass = 0;
    /*std::list<ClassAndUC> availableClasses;
    //student can only be enrolled to class if there are less than 30 students in that class
    for (auto x: mStudentsPerClass) {
        if (x.first.getUcCode() == new_uc and x.second < 30) {
            availableClasses.push_back(x.first);
            spaceInClass++;
        }
    }*/
    for (auto x: mStudentsPerClass) {
        if (x.first.getUcCode() == new_uc and x.first.getClassCode() == new_class and x.second < 30) {
            spaceInClass++;
        }
        if (spaceInClass == 0) {
            std::cout << "Request Denied: Class without vacancies " << std::endl;
            return;
        }
        //std:: cout << availableClasses.front().getClassCode() << std::endl;
        Student S = Student(studentName, studentCode);
        ClassAndUC C = ClassAndUC(new_class, new_uc);
        addStudentsClasses(C, S);
        std::cout << "Request accepted" << std::endl;

        for (auto &x: studentsPerUC) {
            if (x.first.getUC() == new_uc) {
                x.second++;
                break;
            }
        }
        for (auto &x: mStudentsPerUC) {
            if (x.first.getUC() == new_uc) {
                x.second++;
                break;
            }
        }
    }
}




void Data::requestRemoveClass(std::string studentCode, std::string uc, std::string classCode) {
    std::string upcode, name;
    std::string classcode, uccode;
    for (auto x: studentClasses) {
        if (x.first.getUcCode() == uc and x.first.getClassCode() == classCode and
            x.second.getupcode() == studentCode) {
            classcode = x.first.getClassCode();
            uccode = x.first.getUcCode();
            upcode = x.second.getupcode();
            name = x.second.getname();
        }
    }
    ClassAndUC keyToRemove = ClassAndUC(classcode, uccode);
    Student S = Student(name, upcode);
    auto range = studentClasses.equal_range(keyToRemove);
    for (auto it = range.first; it != range.second; ++it) {
        if (it->second.getccode() == S.getccode()) {
            studentClasses.erase(it);

            break;
        }
    }
    for (auto &x: studentPerClass) {
        if (x.first.getClassCode() == classCode, x.first.getUcCode() == uc) {
            x.second--;
            break;
        }
    }
    for (auto &x: mStudentsPerClass) {
        if (x.first.getUcCode() == uc and x.first.getClassCode() == classCode) {
            x.second--;
            break;
        }
    }
    for (auto &x: studentsPerUC) {
        if (x.first.getUC() == uc) {
            x.second--;
            break;
        }
    }
    for (auto &x: mStudentsPerUC) {
        if (x.first.getUC() == uc) {
            x.second--;
            break;
        }
    }
}



void Data::requestRemoveUc(std::string studentCode, std::string uc) {
    std::string upcode, name;
    std::string classcode, uccode;
    for (auto x: studentClasses) {
        if (x.first.getUcCode() == uc and x.second.getupcode() == studentCode) {
            classcode = x.first.getClassCode();
            uccode = x.first.getUcCode();
            upcode = x.second.getupcode();
            name = x.second.getname();
        }
    }
    ClassAndUC keyToRemove = ClassAndUC(classcode, uccode);
    Student S = Student(name, upcode);
    auto range = studentClasses.equal_range(keyToRemove);
    for (auto it = range.first; it != range.second; ++it) {
        if (it->second.getccode() == S.getccode()) {
            studentClasses.erase(it);

            break;
        }
    }
    for (auto &x: studentsPerUC) {
        if (x.first.getUC() == uc) {
            x.second--;
            break;
        }
    }
    for (auto &x: mStudentsPerUC) {
        if (x.first.getUC() == uc) {
            x.second--;
            break;
        }
    }
    for (auto &x: studentPerClass) {
        if (x.first.getUcCode() == uc) {
            x.second++;
            break;
        }
    }
    for (auto &x: mStudentsPerClass) {
        if (x.first.getUcCode() == uc) {
            x.second++;
            break;
        }
    }
}
