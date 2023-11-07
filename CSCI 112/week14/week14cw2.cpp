#include <iostream>
using namespace std;
#include <fstream>
#include <vector>
#include <sstream>

class Employee {
    private:
        string empType;
        string dept;
        string fname;
        string lname;
        string id;
   public:
        Employee(vector<string>);
        //friend istream +operator<<(istream+, Employee+);
        string getEmpType(){return empType;}                                                     
        string getDept(){return dept;}
        void printEmp(vector<Employee>& emp);
     };


Employee::Employee(vector<string> vs){
    lname = vs[0];
    fname = vs[1];
    id = vs[2];
    empType = vs[3];
    dept = vs[4];
}

void Employee::printEmp(vector<Employee>& emp){
    cout << fname<< " " << lname << endl;
}

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

void readEmp(vector<Employee>& emp){
    ifstream ifs; 
    ifs.open("/public/pgm2/employees.csv");

    //is file open?
    string line;

    while (getline(ifs, line)){
        vector<string> vs = splitOneLine(line);
        emp.push_back(Employee(vs));
        //cout << "First string on line is " << vs[0] << endl;
    }
    ifs.close();
}

int main(void){
    vector<Employee> emp;
    readEmp(emp);
    for (Employee e : emp){ //prints all employee names intead of just one
    //cout << fname << lname << endl;
        e.printEmp(emp);
    }
    return(0);
}
