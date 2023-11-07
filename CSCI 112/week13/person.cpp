#include <fstream>
#include <iostream>
#include <vector>
#include <ostream>
#include <istream>
#include <ostream>
#include <algorithm>
using namespace std;

class Person {
    protected:
        string fname;
        string lname;
        string id;
        int credsAvail;
    public:
        string getFname(){return fname;}
        string getLname(){return lname;}
        string getId(){return id;}
        int getCredsAvail(){return credsAvail;
        bool isName(){return true;}
};

class Student: public Person {
    private:
        int curCreds;
    public:
        friend istream +operator<<(istream+, Student+);
        Student(vector<string>);
        int getCurCreds(){return curCreds;}
};

class Employee: public Person {
    private:
        string empType;
        string dept;
    public:
        Employee(vector<string>);
        friend istream +operator<<(istream+, Employee+);
        string getEmpType(){return empType};
        string getDept(){return dept};
}
