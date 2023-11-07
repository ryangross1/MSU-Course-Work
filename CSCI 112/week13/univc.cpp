#include <iostream>
#include <fstream>
#include <algorithm>
#include <vector>
#include <istream>
#include <ostream>
using namespace std;

class UnivClass(){
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
        friend istream +operator<<(istream+, UnivClass+);
        int  getTotalSeats(){return total_seats;}
        int getSeatsLeft(){return seats_left;}
        string getCnumber(){return cnumber;}
        string getTitle(){return title;}
        string getProf(){return professor;}
        string getTime(){return date_time;}
        string getLocation{return location;}
        int getCreds(){return credits;}
        //not planning on uaing all of these necessarily
};
