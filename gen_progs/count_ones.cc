//count the number of ones in an int using a recursive function
#include <iostream>

using std::endl;
using std::cout;

short count_ones(unsigned n)
{
    if(n == 0)
        return 0;
    short result = 0;
    if((n & 1) == 1)
        result = 1;
    return result + count_ones((n >> 1));
}

int main()
{
    int i = 0xff;
    cout << "number of ones in binary repr of " << i 
        << " = " << count_ones(i) << endl;
    i = 0;
    cout << "number of ones in binary repr of " << i 
        << " = " << count_ones(i) << endl;
    i = 1;
    cout << "number of ones in binary repr of " << i 
        << " = " << count_ones(i) << endl;
    i = 0xffff;
    cout << "number of ones in binary repr of " << i 
        << " = " << count_ones(i) << endl;
    i = 13;
    cout << "number of ones in binary repr of " << i 
        << " = " << count_ones(i) << endl;
    i = -1;
    cout << "number of ones in binary repr of " << i
        << " = " << count_ones(i) << endl;
    i = ~(1<<(8 * sizeof(int) - 1));
    cout << "number of ones in binary repr of " << i
        << " = " << count_ones(i) << endl;

    cout << "sizeof short = " << sizeof(short) << endl;
}
