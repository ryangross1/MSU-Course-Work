#include <iostream>
using namespace std;
#include <fstream>
#include <vector>
#include <sstream>

vector<string> splitOneLine(string line){
    //create an istringstream from line
    vector<string> words;
    stringstream ss(line);

    while (ss.good()){
        string substr;
        getline(ss, substr, ',');
        words.push_back(substr);
    }
    return words;
}

void readUnivC(){
    ifstream ifs {"/public/pgm2/classes.csv"};

    //is file open?
    string line;

    while (getline(ifs, line)){
        vector<string> vs = splitOneLine(line);
        cout << "First string on line is " << vs[0] << endl;
    }
    ifs.close();
}

int main(void){
    vector<string> classes;
    readUnivC();
    return(0);
}
