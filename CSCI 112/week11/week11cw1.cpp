#include <iostream>
using namespace std;

class Name {
    string name;
    int age;
    public:
        void set_name(string);
        string get_name(){return name;}
        void set_age(int);
        int get_age(){return age;}
};

void Name::set_name(string n){
    name = n;
}

void Name::set_age(int a){
    age = a;
}

int main(void){
    Name nam;
    nam.set_name("Ryan");
    nam.set_age(19);
    cout << "Name: " << nam.get_name() << " Age: " << nam.get_age() << endl;
}
