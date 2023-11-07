#include <iostream>
//#include <iomainip>
using namespace std;

int main (void){
    string first, last, full_name;
    int age;
    cout << "Enter first name, last name, and age: ";
    cin >> first >> last >> age;
    full_name = first + " " + last;
    cout << "Hello, " << full_name << "\n" << age << " is a wonderful age" << endl;
}

