
#include "Menu.h"

using namespace std;

void Menu::run(){
    Data objStudent = Data();
    readStudents(objStudent);
    objStudent.addStudentsPerUc();
    objStudent.addStudentsPerClass();
    mainMenu(objStudent);
}


void Menu::mainMenu(Data &objStudent){
    char op;
    cout << "__________________________________________\n";
    cout << "|                MainMenu                |\n";
    cout << "|        Choose one of the options       |\n";
    cout << "|________________________________________|\n";
    cout << "|      1. STUDENTS:                      |\n";
    cout << "|      2. SCHEDULE:                      |\n";
    cout << "|      3. REGISTERED STUDENTS:           |\n";
    cout << "|      4. REQUEST:                       |\n";
    cout << "|      \033[30m5. SAVE AND QUIT:\033[0m                 |\n";
    cout << "|      \033[31m6. QUIT WITHOUT SAVING:\033[0m           |\n";
    cout << "|________________________________________|\n";
    cout << "Your option:";
    cin >> op;
    switch(op)
    {
        case '1':
            MenuStudents(objStudent);
            wait(objStudent);
            break;
        case '2':
            MenuSchedule(objStudent);
            wait(objStudent);
            break;
        case '3':
            resgisteredStudents(objStudent);
            wait(objStudent);
            break;
        case '4':
            request(objStudent);
            mainMenu(objStudent);
            wait(objStudent);
            break;
        case '5':
            saveStudent(objStudent);
            break;
        case '6':
            break;
        default:
            cout << "Invalid Option..." << endl;
            wait(objStudent);
            break;
    }
}

void Menu::readStudents(Data &obj){

    ifstream input("../input/students_classes.csv");
    if(!input.is_open()){
        cout << "Error: Unable to open file 2 \n";}
    string line;
    getline(input, line);

    while (getline(input, line))
    {
        istringstream in (line);
        string name_, number, uCode, classCode;
        getline(in,number,',');
        getline(in,name_,',');
        getline(in,uCode,',');
        getline(in,classCode,',');

        Student s = Student(name_, number);
        ClassAndUC c = ClassAndUC(classCode, uCode);

        obj.addAllStudents(s);
        obj.addStudentsClasses(c, s);
    }

    input.close();
}

void Menu::MenuStudents(Data &obj) {
    cout << "__________________________________________\n";
    cout << "|              StudentsMenu              |\n";
    cout << "|________________________________________|\n";
    cout << "|                                        |\n";
    cout << "|      1.All Students                    |\n";
    cout << "|      2.Search by UC                    |\n";
    cout << "|      3.Search by Class                 |\n";
    cout << "|      4.Search by Year                  |\n";
    cout << "|      5.At least n Uc's:                |\n";
    cout << "|      6.UCs with more Students:         |\n";
    cout << "|                                        |\n";
    cout << "|          \033[31mPress B to go back.\033[0m           |\n";
    cout << "|________________________________________|\n";
    cout << "Your option:";
    char c;
    cin >> c;
    switch (c){
        case '1': {
            obj.printAllStudents();
            break;
        }
        case '2': {
            string uc_;
            cout << "Insert UC:";
            cin >> uc_;
            obj.searchByUc(uc_);
            break;
        }
        case '3': {
            string class_;
            cout << "Insert Class: ";
            cin >> class_;
            string uc;
            cout << "Insert UC: ";
            cin >> uc;
            obj.searchByClass(class_, uc);
            break;
        }
        case '4': {
            char year;
            cout << "Insert year:";
            cin >> year;
            int n = 0;
            obj.searchByYear(year, n, 0);
            break;
        }case '5': {
            int o;
            cout << "Number of n Uc's:";
            cin >> o;
            obj.UCcount(obj);
            obj.nNumbers(o);
            break;
        }
        case '6':
            int n;
            cout << "Number of Uc's: ";
            cin >> n;
            obj.nUcsWithStudentsPerUc(n);
            break;
        case 'B':
            break;
        default:
            cout << "Invalid Option..." << endl;
            MenuStudents(obj);
            break;
    }
}

void Menu::MenuSchedule(Data &obj) {
    int opção = 0;
    cout << "__________________________________________\n";
    cout << "|              ScheduleMenu              |\n";
    cout << "|________________________________________|\n";
    cout << "|      1.Class Schedule                  |\n";
    cout << "|      2.Student Schedule                |\n";
    cout << "|________________________________________|\n";
    cin >> opção;
    switch (opção) {
        case 1:
            cout << "Class:";
            Classfind();
            break;
        case 2:
            cout<< "UpCode:";
            Stfind();
            break;
        case 3:
            break;
    }
}

void Menu::Classfind(){
    vector<pair<UC,Class>> classuc;
    vector<Slot> schedule;
    ifstream input("../input/classes.csv");
    if(!input.is_open()){
        cout << "Error: Unable to open file 1 \n";
    }
    string line;
    getline (input, line);
    while(getline(input, line)){
        istringstream in (line);
        string classCode, ucCode, weekday, start, duration, type;
        getline(in,classCode, ',');
        getline(in, ucCode, ',');
        getline(in, weekday, ',');
        getline(in,start,',');
        getline(in, duration, ',');
        getline(in, type, ',');
        UC u1 = UC(ucCode);
        Class c1 = Class(classCode);
        pair<UC,Class> copy = Student::createpair(u1, c1);
        classuc.push_back(copy);
        Slot slot = Slot(ucCode, classCode, weekday,start,duration,type);
        schedule.push_back(slot);
    }
    string cl;
    cin >> cl;
    Data::createschedulec(classuc, schedule, cl);
    input.close();
}

void Menu::Stfind() {
    vector<Student> classucst;
    ifstream input("../input/students_classes.csv");
    if(!input.is_open()){
        cout << "Error: Unable to open file 2 \n";}
    string line;
    getline(input, line);

    while (getline(input, line))
    {
        istringstream in (line);
        string name_, number, uCode, cCode;

        getline(in,number,',');
        getline(in,name_,',');
        getline(in,uCode,',');
        getline(in,cCode,',');

        Student copy = Student(uCode, cCode, number);
        classucst.push_back(copy);

    }
    vector<Slot> schedule;
    ifstream input2("../input/classes.csv");
    if(!input2.is_open()){
        cout << "Error: Unable to open file 1 \n";
    }
    string line2;
    getline (input2, line2);
    while(getline(input2, line2)){
        istringstream in (line2);
        string classCode, ucCode, weekday, start, duration, type;
        getline(in,classCode, ',');
        getline(in, ucCode, ',');
        getline(in, weekday, ',');
        getline(in,start,',');
        getline(in, duration, ',');
        getline(in, type, ',');

        Slot slot = Slot(ucCode, classCode, weekday,start,duration,type);
        schedule.push_back(slot);
    }
    string st;
    cin >> st;
    Data::createschedules(classucst, schedule, st);

    input.close();
    input2.close();
}

void Menu::resgisteredStudents(Data &obj) {

    cout << "__________________________________________\n";
    cout << "|          Registered Students           |\n";
    cout << "|________________________________________|\n";
    cout << "|                                        |\n";
    cout << "|      1.Search by UC                    |\n";
    cout << "|      2.Search by Class                 |\n";
    cout << "|      3.Search by Year                  |\n";
    cout << "|          \033[31mPress B to go back.\033[0m           |\n";
    cout << "|________________________________________|\n";
    cout << "Your option:";

    char option;
    cin >> option;
    switch(option){
        case '1':
        {
            cout << "Insert UC: ";
            string uc;
            cin >> uc;
            cout << obj.ucOccupation(uc) << std::endl;
            break;
        }
        case '2':
        {
            cout << "Insert Class: ";
            string class_;
            cin >> class_;
            cout << obj.classOccupation(class_) << std::endl;
            break;
        }
        case '3':
        {
            cout << "Insert Year: ";
            char year;
            cin >> year;
            cout << obj.yearOccupation(year) << std::endl;
            break;
        }
        case 'B':
            break;
        default:
            cout << "Invalid Option..." << endl;
            resgisteredStudents(obj);
            break;
    }
}

void Menu:: request(Data &obj) {

    cout << "__________________________________________\n";
    cout << "|          Student Requests              |\n";
    cout << "|________________________________________|\n";
    cout << "|                                        |\n";
    cout << "|      1.Add UC                          |\n";
    cout << "|      2.Add Class                       |\n";
    cout << "|      3.Remove UC                       |\n";
    cout << "|      4.Remove Class                    |\n";
    cout << "|      5.SWitch UC                       |\n";
    cout << "|      6.SWitch Class                    |\n";
    cout << "|      7.See all Requests                |\n";
    cout << "|          \033[31mPress B to go back.\033[0m           |\n";
    cout << "|________________________________________|\n";
    cout << "Your option:";
    char option;
    cin >> option;
    switch (option) {
        case '1': {
            string ucode, new_uc;
            cout << "Student Code: " << endl;
            cin >> ucode;
            cout << "UC to add: " << endl;
            cin >> new_uc;
            wait(obj);
            break;
        }
        case '2': {
            string ucode, new_uc, class_;
            cout << "Student Code: " << endl;
            cin >> ucode;
            cout << "UC:" << endl;
            cin >> new_uc;
            cout << "Class to add: " << endl;
            cin >> class_;
            obj.addRequest("Student " + ucode + " resquested registration in class  " + class_);
            obj.requestAddClass(ucode, class_, new_uc);
            wait(obj);
            break;
        }
        case '3': {
            string studentcode, uc;
            cout << "Student Code: " << endl;
            cin >> studentcode;
            cout << "UC to remove: " << endl;
            cin >> uc;
            obj.addRequest("Student " + studentcode + " resquested removal of UC " + uc);
            obj.requestRemoveUc(studentcode, uc);
            wait(obj);
            break;
        }
        case '4': {
            string studentcode, uc, classCode;
            cout << "Student Code: " << endl;
            cin >> studentcode;
            cout << "UC: " << endl;
            cin >> uc;
            cout << "Class to remove: " << endl;
            cin >> classCode;
            obj.addRequest("Student " + studentcode + " resquested removal of Class " + classCode + " from UC " + uc);
            obj.requestRemoveClass(studentcode, uc, classCode);
            wait(obj);
            break;
        }
        case '7': {
            obj.printRequest();
            wait(obj);
            break;
        }
        case 'B':
            mainMenu(obj);
            break;

        default: {
            cout << "Invalid Option..." << endl;
            request(obj);
            break;
        }

    }
}
void Menu::saveStudent(Data &obj){
                ofstream output("../input/students_classes.csv");
                output.clear();
                output << "StudentCode,StudentName,UcCode,ClassCode\n";
                for(auto x : obj.studentClasses){
                    output << x.second.getupcode() << ","<< x.second.getname()<<  "," << x.first.getUcCode() << ","<< x.first.getClassCode()<< endl;
                }
                output.close();
    }

void Menu::wait(Data &objStudent) {
        string o;
    cout << "Press ENTER to continue...";
    cin.get(); // Aguarda a entrada de uma tecla
    cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
    mainMenu(objStudent);
}

