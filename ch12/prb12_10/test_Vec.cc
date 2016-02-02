#include "Vec.h"
#include <iostream>
#include <iterator>
#include <algorithm>


using std::cout;
using std::cin;
using std::endl;
using std::copy;
using std::ostream_iterator;

int main()
{
    cout << "Testing empty vec -->" << endl;
    Vec<int> empty_vec;
    cout << "empty vec size empty_vec.size() = " << empty_vec.size() << endl;

    Vec<int> five_ones(5, 1);
    cout << "vec five ones --> " << endl;
    cout << "("; 
    copy(five_ones.begin(), five_ones.end(), ostream_iterator<int>(cout, ","));
    cout << ")" << endl;
}
