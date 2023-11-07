#include <fstream>
#include <iostream>
using namespace std;
#include <algorithm>
#include <vector>


int main(void){
    ifstream ifs;
    vector<string> line;
    string str;

    ifs.open("/public/lab7/addresses.txt");
    if (!ifs.is_open()){
        cout << "file did not open" << endl;
        return(1);
    }
    while(ifs >> str){
        line.push_back(str);
    }
    ifs.close();

    //sort
    sort(line.begin(), line.end());
    //print using a for loop
    for(string x : line){
        cout << x << endl;
    }
}
