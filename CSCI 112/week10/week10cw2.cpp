#include <stdexcept>
using namespace std;
#include <cmath>
#include <iostream>

void error(string s) {
    throw runtime_error("ERROR: " + s);
}

int main(int argc, char** argv){
    if (argc != 2){
        error("Wrong number of arguements");
        return(1);
    }
    int x = atoi(argv[1]);
    
    x = x * 2;

    cout << "Doubled number is: " << x << endl;
    return(0);
 }

