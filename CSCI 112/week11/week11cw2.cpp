#include <iostream>
using namespace std;
#include <algorithm>

class Name {
    string name;
    int age;
    public: 
        void set_name(string);
        void set_age(int);
        string get_name(){return name;}
        int get_age(){return age;}
};

void Name::set_name(string n){
    name = n;
}

void Name::set_age(int a){
    age = a;
}

//class is Name
//vector<Name> people;

bool compare(Name p1, Name p2){
    return (p1.get_name() < p2.get_name());
}

//Person has string name and int age

//sort(people.begin(), people.end());

//sort(people.begin(), people.end(), compare);

int main(void){
    Name n1;
    Name n2;
    Name n3;
    Name n4;
    vector<Name> people;
    n1.set_name("Jane");
    n1.set_age(27);
    n2.set_name("Alan");
    n2.set_age(24);
    n3.set_name("Brian");
    n3.set_age(33);
    n4.set_name("Rachel");
    n4.set_age(29);
    people.push_back(n1);
    people.push_back(n2);
    people.push_back(n3);
    people.push_back(n4);

    sort(people.begin(), people.end(), compare);

    for (unsigned int i = 0; i < people.size(); i++){
        cout << "Name: " << people[i].get_name() << " Age: " <<  people[i].get_age() << endl;
    }
    
}
