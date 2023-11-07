#include <fstream>
#include <iostream>
#include <algorithm>
#include <vector>
#include <istream>
#include <ostream>
using namespace std;

class Address {
    private:
        int octets[4];
        //string addstr;        init class data attributes
        char netclass;
        string temp;
    public:
        friend istream &operator>>(istream&, Address&);
        friend ostream &operator<<(ostream&, const Address&); //declare methods
        char getClass() const {return netclass;}
        int getFirstOctet() const {return octets[0];}
};

istream &operator>>(istream& in, Address& ad){
    //read in string
    //break string apart
    //string temp;
    in >> ad.temp;  //temp gets instream& in
    int pos1 = ad.temp.find(".");
    ad.octets[0] = stoi(ad.temp.substr(0, pos1));
    int pos2 = ad.temp.find(".", pos1+1);
    ad.octets[1] = stoi(ad.temp.substr(pos1+1, pos2 - pos1)); //parseing string b "."
    int pos3 = ad.temp.find(".", pos2+1);                       //pos sets position of each octet
    ad.octets[2] = stoi(ad.temp.substr(pos2+1, pos3 - pos2));
    ad.octets[3] = stoi(ad.temp.substr(pos3+1, 3));
    //write if else statements for determing class push
    //set netclass
    if (ad.octets[0] <= 127){       //not sure why, but am aware of extra networks being read into each class that do not match the logic described here`
        //classA.push_back(in);
        ad.netclass = 'a';
    }
    else if (ad.octets[0] >= 128 && ad.octets[0] <= 191){   //determines which network class based on value of first octet
        //classB.push_back(in);
        ad.netclass = 'b';
    }
    else if (ad.octets[0] >= 192 && ad.octets[0] <= 223){
        //classC.push_back(in);
        ad.netclass = 'c';
    }
    else {

    }
    return in;
}

ostream &operator<<(ostream& out, const Address& ad){
    //uses netclass to print correct class
    int pos1 = ad.temp.find(".");
    int pos2 = ad.temp.find(".", pos1+1);   //need positions again to parse string for prints
    int pos3 = ad.temp.find(".", pos2+1);   //temp is string being operated on

    switch(ad.netclass){ //switch on network class which class to print
        case 'a':
            //cout << "Class A has " << classA.size() << " network addresses:" << endl;
            cout << "Network: " << ad.temp.substr(0, pos1) << "\t\tHost: " << ad.temp.substr(pos1+1, 11) << endl;
            break;
        case 'b':
            //cout << "Class B has " << classB.size() << " network addresses:" << endl;
            cout << "Network: " << ad.temp.substr(0, pos2) << "\t\tHost: " << ad.temp.substr(pos2+1, 7) << endl; //parseing string by pos
            break;
        case 'c':
            //cout << "Class C has " << classC.size() << " network addresses:" << endl;
            cout << "Network: " << ad.temp.substr(0, pos3) << "\t\tHost: " << ad.temp.substr(pos3+1, 3) << endl; 
            break;
    }
    return out;
}

bool compare(Address a1, Address a2){
    return (a1.getFirstOctet() < a2.getFirstOctet()); //comapare for sort
}

int main (void){
    ifstream ifs; //make ifstream
    vector<Address> classA;
    vector<Address> classB; //make class vectors
    vector<Address> classC;
    
    

    ifs.open("/public/lab7/addresses.txt"); //opening file
    if (!ifs.is_open()){
        cout << "file did not open" << endl; //throw
        return(1);
    }
    Address a;
    while(ifs >> a){
        //if a.getClass()
        char nc = a.getClass();
        switch(nc){         //switch on network class
            case 'a':
                classA.push_back(a);
                break;
            case 'b':
                classB.push_back(a); //push address on respective vector
                break;
            case 'c':
                classC.push_back(a);
                break;
        }
    }

    sort(classA.begin(), classA.end(), compare);
    sort(classB.begin(), classB.end(), compare); //sort 
    sort(classC.begin(), classC.end(), compare);
    cout << "Class A has " << classA.size() << " network addresses:" << endl;
    for (unsigned int i = 0; i < classA.size(); i++){                           //prints 
        cout << classA[i];
    }
    cout << "\n";
    cout << "Class B has " << classB.size() << " network addresses:" << endl;
    for (unsigned int i = 0; i < classB.size(); i++){
        cout << classB[i];
    }
    cout << "\n";
    cout << "Class C has " << classC.size() << " network addresses:" << endl;
    for (unsigned int i = 0; i < classC.size(); i++){
        cout << classC[i];
    }
}
