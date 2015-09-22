//program to demonstrate accumulate function in stl <numeric> header
//also implementing the same function here as my_accumulate
//

#include "my_include.h"


int main()
{
    vector<int> v;
    vector<int> v_squares;
    int from = 0;
    int to = 101;
    for(int i = from; i < to; i++) v.push_back(i);
    for(int i = from; i < to; i++) v_squares.push_back(i * i);
    //adding numbers from 0 to 100
    int total_ = accumulate(v.begin(), v.end(), 0);
    int total_squares_ = accumulate(v_squares.begin(), v_squares.end(), 0);
    cout << "sum of numbers from " << from << " to " << to << " = " << total_ << endl;
    cout << "sum of squares of numbers from " << from << " to " << to << " = " << total_squares_ << endl;
}


