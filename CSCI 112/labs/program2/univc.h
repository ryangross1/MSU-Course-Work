#ifndef UnivClass_H
#define UnivClass_H
#include <iostream>
#include <fstream>
#include <algorithm>
#include <vector>
#include <istream>
#include <ostream>
using namespace std;

class UnivClass {
    private:
        string cnumber;
        string title;
        int total_seats;
        int seats_left;
        string professor;
        string date_time;
        string location;
        int credits;
    public:
        UnivClass(vector<string>);
        friend ostream &operator<<(ostream&, const UnivClass&);
        int  getTotalSeats(){return total_seats;}
        int getSeatsLeft(){return seats_left;}
        string getCnumber(){return cnumber;}
        string getTitle(){return title;}
        string getProf(){return professor;}
        string getTime(){return date_time;}
        string getLocation(){return location;}
        int getCreds(){return credits;}
        //not planning on uaing all of these necessarily
};

UnivClass::UnivClass(vector<string> vs){
    cnumber = vs[0];
    title = vs[1];
    total_seats = stoi(vs[3]);
    seats_left = stoi(vs[5]);
    professor = vs[6];
    date_time = vs[7];
    location = vs[8];
    credits = stoi(vs[9]);
}

ostream& operator<<(ostream &out, const UnivClass &uc){
    cout << uc.cnumber << " " << uc.title << " Taught by " << uc.professor << " at " << uc.date_time << " in " << uc.location << endl;
    return out;
}
#endif

