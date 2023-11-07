#ifndef Employee_H
#define Employee_H
#include <iostream>
using namespace std;
#include <fstream>
#include <vector>
#include <sstream>
#include <istream>
#include <ostream>
#include <cstring>
#include "person.h"

class Employee: public Person {
    private:
        string empType;
        string dept;
        //string fname;
        //string lname;
        //string id;
   public:
        Employee(vector<string>);
        //Employee(string);
        string getEmpType(){return empType;}                                                     
        string getDept(){return dept;}
        //void printEmp(vector<Employee>& emp);
        friend ostream &operator<<(ostream&, const Employee&);
     };


Employee::Employee(vector<string> vs){
    lname = vs[0];
    fname = vs[1];
    id = vs[2];
    empType = vs[3];
    dept = vs[4];
    if (empType == "PT"){
        creditsAvail = 3;
    }
    if (empType == "FT"){
        creditsAvail = 7;    
    }
}

//Employee::Employee(string ca){
  //  creditsAvail = ca;
//}

ostream& operator<<(ostream &out, const Employee &e){
    //print all attributes
    cout << "Employee name: " << e.fname << " " << e.lname << "\tID: " << e.id << "\tType: " << e.empType << "\tWorks in: " << e.dept << endl;
    return out;
}
#endif
//void Employee::printEmp(vector<Employee>& emp){
  //  cout << fname<< " " << lname << endl;
//}


