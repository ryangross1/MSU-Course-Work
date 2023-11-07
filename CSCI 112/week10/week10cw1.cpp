#include <iostream>
using namespace std;
#include <vector>

int main (void) {
    vector<double> nums;

    double temp;

    cout<< "Enter numbers (one per line) and enter 0 when done\n";

    while (cin >> temp) {
        if (temp == 0){
            break;
        }
        nums.push_back(temp);
    }
    double sum = 0.0;
    for (unsigned int i = 0; i < nums.size(); i++){
        sum += nums[i];
    }

    cout << "Average is " << sum/nums.size() << "\n";
    return(0);
}
