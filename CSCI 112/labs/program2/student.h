#ifndef Student_H
#define Student_H
#include <iostream>
using namespace std;
#include <fstream>
#include <vector>
#include <sstream>
#include <istream>
#include <ostream>
#include <algorithm>
#include "person.h"

class Student: public Person {
    private:
        int curCredits;
   public:
        Student(vector<string>);
        //Student(string);
        int getCurCredits(){return curCredits;}
        friend ostream &operator<<(ostream&, const Student&);
     };


Student::Student(vector<string> vs){
    lname = vs[0];
    fname = vs[1];
    id = vs[2];
    curCredits = stoi(vs[3]);
    creditsAvail = 21;
}

//Student::Student(string ca){
  //  creditsAvail = ca;
//}

ostream& operator<<(ostream &out, const Student &s){
    //print all attributes
    cout << "Student name: " << s.fname << " " << s.lname << "\tID: " << s.id << "\tCurrent credits: " << s.curCredits << endl;
    return out;
}
#endif



