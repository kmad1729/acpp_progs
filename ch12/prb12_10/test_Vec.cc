#include "Vec.h"
#include <iostream>


using std::cout;
using std::cin;
using std::endl;

int main()
{
    cout << "Testing empty vec -->" << endl;
    Vec<int> empty_vec;
    cout << "empty vec size empty_vec.size() = " << empty_vec.size() << endl;
}
