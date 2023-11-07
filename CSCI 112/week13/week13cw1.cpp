#include <iostream>
using namespace std;

class Animal {
    protected:
        int speed;
    public:
        Animal(){cout << "I am an animal" << endl;}
        int getSpeed(){return speed;}        
};

class Cat: public Animal {
    public:
        Cat(){
            cout << "I am a cat" << endl;
            speed = 30;
        }
        
};

class Dog: public Animal {
    public:
        Dog(){
            cout << "I am a dog" << endl;
            speed = 20;
        }
};

class Giraffe: public Animal {
    public:
        Giraffe(){
            cout << "I am a giraffe" << endl;
            speed = 37;
        }
};

int main(void){
    //Animal a;
    Cat c;
    Dog d;
    Giraffe g;

    cout << "Dog runs at " << d.getSpeed() << "MPH" << endl;
    cout << "Cat runs at " << c.getSpeed() << "MPH" << endl;
    cout << "Giraffe runs at " << g.getSpeed() << "MPH" << endl;
    return(0);
}
