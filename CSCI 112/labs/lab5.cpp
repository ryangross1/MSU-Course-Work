#include <iostream>
using namespace std;
#include <vector>
#include <cmath>
#include <stdexcept>

void error(string s){ //error func
    throw runtime_error("ERROR: " + s);
}

vector<string> makeVector(vector<string> &numbers){ //assigns vector values to string names of nums
    numbers.push_back("one");
    numbers.push_back("two");
    numbers.push_back("three");
    numbers.push_back("four");
    numbers.push_back("five");
    numbers.push_back("six");
    numbers.push_back("seven");
    numbers.push_back("eight");
    numbers.push_back("nine");
    
    return numbers;
}

void print(vector<string> &numbers, string in){
    if (in.size() == 1){
        if (in.compare("1") == 0){
            cout << numbers[0];
        }
        if (in.compare("2") == 0){
            cout << numbers[1];
        }
        if (in.compare("3") == 0){      //compares in with desired num string
            cout << numbers[2];             //prolly could have just used switch here too
        }
        if (in.compare("4") == 0){
            cout << numbers[3]; //prints correct num name
        }
        if (in.compare("5") == 0){
            cout << numbers[4];
        }
        if (in.compare("6") == 0){
            cout << numbers[5];
        }
        if (in.compare("7") == 0){
            cout << numbers[6];
        }
        if (in.compare("8") == 0){
            cout << numbers[7];
        }
        if (in.compare("9") == 0){
            cout << numbers[8];
        }
    }
    
    if (in.size() == 2){    //ultra meathead bruteforce         prolly could have split this up into separate functions for ones, tens, hundreds, and thousands
        switch(in[0]){      //if size of in is 2, go through tens switch statement for printing
            case '1':
                error("Second from last digit cannot be one");
                break;
            case '2':
                cout << " twenty ";
                break;
            case '3':
                cout << " thirty ";
                break;
            case '4':
                cout << " forty ";
                break;
            case '5':
                cout << " fifty ";
                break;
            case '6':
                cout << " sixty ";
                break;
            case '7':
                cout << " seventy ";
                break;
            case '8':
                cout << " eighty ";
                break;
            case '9':
                cout << " ninety ";
                break;
            case '0':
                break;
        }
        switch(in[1]){
            case '1':
                cout << numbers[0];
                break;
            case '2':
                cout << numbers[1];
                break;
            case '3':
                cout << numbers[2];
                break;
            case '4':
                cout << numbers[3];
                break;
            case '5':
                cout << numbers[4];
                break;
            case '6':
                cout << numbers[5];
                break;
            case '7':
                cout << numbers[6];
                break;
            case '8':
                cout << numbers[7];
                break;
            case '9':
                cout << numbers[8];
                break;
            case '0':
                break;
        }
    }

    if (in.size() == 3){ //if length of in is 3, hence hundreds
        switch(in[0]){
            case '1':
                cout << numbers[0] << " hundred ";
                break;
            case '2':
                cout << numbers[1] << " hundred ";
                break;
            case '3':
                cout << numbers[2] << " hundred ";
                break;
            case '4':
                cout << numbers[3] << " hundred ";
                break;
            case '5':
                cout << numbers[4] << " hundred ";
                break;
            case '6':
                cout << numbers[5] << " hundred ";
                break;
            case '7':
                cout << numbers[6] << " hundred ";
                break;
            case '8':
                cout << numbers[7] << " hundred ";
                break;
            case '9':
                cout << numbers[8] << " hundred ";
                break;
            case '0':
                break;
        }
        switch(in[1]){
            case '0':
                break;
            case '1':
                error("Second from last digit cannot be one");
                break;
            case '2':
                cout << "twenty ";
                break;
            case '3':
                cout << "thirty ";
                break;
            case '4':
                cout << "forty ";
                break;
            case '5':
                cout << "fifty ";
                break;
            case '6':
                cout << "sixty ";
                break;
            case '7':
                cout << "seventy ";
                break;
            case '8':
                cout << "eighty ";
                break;
            case '9':
                cout << "ninety ";
                break;
        }
        switch(in[2]){
            case '0':
                break;
            case '1':
                cout << numbers[0];
                break;
            case '2':
                cout << numbers[1];
                break;
            case '3':
                cout << numbers[2];
                break;
            case '4':
                cout << numbers[3];
                break;
            case '5':
                cout << numbers[4];
                break;
            case '6':
                cout << numbers[5];
                break;
            case '7':
                cout << numbers[6];
                break;
            case '8':
                cout << numbers[7];
                break;
            case '9':
                cout << numbers[8];
                break;
        }
    }
    if (in.size() == 4){ //if length of in is 4, hence thousands 
        switch(in[0]){
            case '1':
                cout << numbers[0] << " thousand ";
                break;
            case '2':
                cout << numbers[1] << " thousand ";
                break;
            case '3':
                cout << numbers[2] << " thousand ";
                break;
            case '4':
                cout << numbers[3] << " thousand ";
                break;
            case '5':
                cout << numbers[4] << " thousand ";
                break;
            case '6':
                cout << numbers[5] << " thousand ";
                break;
            case '7':
                cout << numbers[6] << " thousand ";
                break;
            case '8':
                cout << numbers[7] << " thousand ";
                break;
            case '9':
                cout << numbers[8] << " thousand ";
                break;
            case '0':
                break;
        }
        switch(in[1]){
            case '1':
                cout << numbers[0] << " hundred ";
                break;
            case '2':
                cout << numbers[1] << " hundred ";
                break;
            case '3':
                cout << numbers[2] << " hundred ";
                break;
            case '4':
                cout << numbers[3] << " hundred ";
                break;
            case '5':
                cout << numbers[4] << " hundred ";
                break;
            case '6':
                cout << numbers[5] << " hundred ";
                break;
            case '7':
                cout << numbers[6] << " hundred ";
                break;
            case '8':
                cout << numbers[7] << " hundred ";
                break;
            case '9':
                cout << numbers[8] << " hundred ";
                break;
            case '0':
                break;
        }
        switch(in[2]){
            case '0':
                break;
            case '1':
                error("Second from last digit cannot be one");
                break;
            case '2':
                cout << "twenty ";
                break;
            case '3':
                cout << "thirty ";
                break;
            case '4':
                cout << "forty ";
                break;
            case '5':
                cout << "fifty ";
                break;
            case '6':
                cout << "sixty ";
                break;
            case '7':
                cout << "seventy ";
                break;
            case '8':
                cout << "eighty ";
                break;
            case '9':
                cout << "ninety ";
                break;
        }
        switch(in[3]){
            case '0':
                break;
            case '1':
                cout << numbers[0];
                break;
            case '2':
                cout << numbers[1];
                break;
            case '3':
                cout << numbers[2];
                break;
            case '4':
                cout << numbers[3];
                break;
            case '5':
                cout << numbers[4];
                break;
            case '6':
                cout << numbers[5];
                break;
            case '7':
                cout << numbers[6];
                break;
            case '8':
                cout << numbers[7];
                break;
            case '9':
                cout << numbers[8];
                break;
        }
    }
}

int main(int argc, char** argv){
    if (argc != 2){
        error("Wrong number of arguements");    //only takes one arguement other than executing the file
        return(1);
    }

    string in(argv[1]);     //takes in var in as a string

    vector<string> numbers; //init vector
    makeVector(numbers);    //calls function to assign vector values
    cout << "Number " << in << " is written as "; //print form
    print(numbers, in); //prints vector with correct nums
    cout << "\n";
    
    return(0);

    //TO DO
    //find length of command line arg
    //deconstrusct command line arg
    //make print format
    //print vector in main
}
