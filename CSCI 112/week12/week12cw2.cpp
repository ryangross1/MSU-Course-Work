#include <iostream>
using namespace std;
#include <algorithm>


enum class Gender {man, woman, nonbinary};

class Person{
    private:
        string name;
        int age;
        Gender gen;
    public:
        Person() {name = "none"; age = 0;}
        Person(string n, int a) {name = n; age = a;}
        string get_name() {return name;}
        int get_age(){return age;}
        void set_name(string n){name = n;}
        void set_age(int a){age = a;}
        string get_gender();
        friend istream& operator>>(istream& input, Person &p){
            int gender;
            input >> p.name >> p.age >> gender;
            p.gen = (Gender)gender;
            return input;
        }
};

string Person::get_gender(){
    vector<string> types {"man", "woman", "nonbinary"};
    return types[(int)gen];  
}

int main(void){
    Person p;
    cin >> p;  
    cout << "Name: " << p.get_name() << " Gender: "<< p.get_gender();
    cout << " Age: " << p.get_age() << endl;
}
