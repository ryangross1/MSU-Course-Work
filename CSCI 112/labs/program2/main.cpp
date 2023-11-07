#include <iostream>
#include <sstream>
#include <fstream>
#include <vector>
#include <stdexcept>
#include <cstring>
using namespace std;
#include "employee.h"
#include "student.h"
#include "univc.h"

vector<string> splitOneLine(string);

void readUnivC(vector<UnivClass>& ucl){
    //read from UnivClass
    ifstream ifs;
    ifs.open("/public/pgm2/classes.csv");
    string line;
    while (getline(ifs, line)){
        vector<string> vs = splitOneLine(line);
        ucl.push_back(UnivClass(vs));
    }
    ifs.close();
}

void readStu(vector<Student>& stu){
    //read from student class
    ifstream ifs;
    ifs.open("/public/pgm2/students.csv");
    string line;
    while (getline(ifs, line)){
        vector<string> vs = splitOneLine(line);
        stu.push_back(Student(vs));
    }
    ifs.close();
}

void readEmp(vector<Employee>& emp){
    //read from employee class
    ifstream ifs;
    ifs.open("/public/pgm2/employees.csv");
    string line;
    while (getline(ifs, line)){
        vector<string> vs = splitOneLine(line);
        emp.push_back(Employee(vs));
    }
    ifs.close();
}

vector<string> splitOneLine(string line){
    vector<string> words;
    stringstream ss(line);
    while (ss.good()){
        string substr;
        getline(ss, substr, ',');
        words.push_back(substr);
    }
    return words;
}

void findPrintName(vector<Student> stu, vector<Employee> emp, string fn, string ln){
    //returns how many credits a person can take creditsAvail
    //int creditsAvail;
    for (unsigned int i = 0; i < stu.size(); i++){
        if ((fn == stu[i].getFname()) && (ln == stu[i].getLname())){
            cout << stu[i] << endl;
            //creditsAvail = 21;
            //Student(creditsAvail);
            //return creditsAvail;
        }
    }
    for (unsigned int i = 0; i < emp.size(); i++){
        if ((fn == emp[i].getFname()) && (ln == emp[i].getLname())){
            //if (empType == "PT"){
              //  creditsAvail = 3;
                //Employee(creditsAvail);
            //}
            //if (empType == "FT"){
              //  creditsAvail = 7;
                //Employee(creditsAvail);
            //}
            cout << emp[i] << endl;
            //return creditsAvail;
        }
    }
}

void printClassSchedule(vector<UnivClass>& ucl, vector<string> in){
    //prints student/employee class schedule
    //int total_credits = 0;
    cout << "Is registered for: " << endl;
    for (unsigned int i = 0; i < ucl.size(); i++){
        for (unsigned int j = 0; j < in.size(); i++){
            if (in[j] == ucl[i].getCnumber()){
                cout << ucl[i] << endl;
            }
        }
    }
}

int main(void){
    //calls all helper functions to make output
    vector<Employee> emp;
    readEmp(emp);
    vector<Student> stu;
    readStu(stu);
    vector<UnivClass> ucl;
    readUnivC(ucl);
    vector<string> classin;
    string fn;
    string ln;
    string temp;

    cout << "Enter first and last name: ";
    cin >> fn >> ln;
    findPrintName(stu, emp, fn, ln);
    
    cout << "Enter classes to take - one line with spaces between: " << endl;
    while (cin >> temp){
        classin.push_back(temp);
    }
    //printClassSchedule(ucl, classin);

    //for (unsigned int i = 0; i < emp.size(); i++){
      //  cout << emp[i];
    //}
    //for (unsigned int i = 0; i < stu.size(); i++){
      //  cout << stu[i];
    //}
    //for (unsigned int i = 0; i < ucl.size(); i++){
     //   cout << ucl[i];
    //}
    return(0);
}
