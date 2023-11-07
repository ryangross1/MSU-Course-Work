#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

/*class Polynomial {
    private:
        vector<Term> poly;
    public:
        void read();
        void simplify();
};
*/
class Term {
    private:
        int coef;
        int exp;
    public:                     //creates Term class for each term
        Term(string);
        void print();
        void add(Term t);
        int getExp();
        bool expEqual(Term t);
};

class Polynomial {
    private: 
        vector<Term> poly;  //polynomial class reads and simplifies polynomial
    public:
        void read();
        void simplify();
};

void Polynomial::read(){
    string str;
    char op;
    while(cin >> str){ //while cin can read in a string
        cin >> op; //reads in plus(does nothing with it)
        Term one_term(str); //instantiates Term object
        poly.push_back(one_term); //adds term to vector in polynomial
    }
}

void Polynomial::simplify(){
    //combine like exp terms
    //for (int j = 0; j < i; j++){
    //    if (expEqual(Term t) == 1 {
    //        add(Term t);
      //  }
   // }
  //  print();
}
 
Term::Term(string str){
    //logic for parse string here
    if (str.size() == 3){
        coef = (int)str[0];
        exp = (int)str[2];
    }
    else if (str.size() == 2){
        if (str[0] == 'x'){
            coef = 1;
            exp = (int)str[1];  //deals with cases of x5 and 5x for example
        }
        if (str[1] == 'x'){
            coef = (int)str[0];
            exp = 1;
        }
    }
    else if (str.size() == 1){
        if (str.compare("x")){
            coef = 1;
            exp = 1;
        }                   //deals with cases of 5 and x for example
        else {
            coef = (int)str[0];
            exp = 0;
        }
    }
}

void Term::add(Term t){

}

void Term::print(){
   // cout << coef << " " << exp << " " << endl;
}

int Term::getExp(){
    return exp;
}

bool Term::expEqual(Term t){
    return false;
}

int main(void){
    Polynomial polynomial;
    
    polynomial.read();

    polynomial.simplify();
    return(0);
}
