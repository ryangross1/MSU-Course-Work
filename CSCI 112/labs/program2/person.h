#ifndef Person_H
#define Person_H
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
        int creditsAvail;
    public:
        string getFname(){return fname;}
        string getLname(){return lname;}
        string getId(){return id;}
        //int getCreditsAvail(){return creditsAvail;}
        //bool isName(){return true;}
};
#endif

