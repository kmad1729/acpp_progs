#include <iostream>

using std::cout;
using std::endl;


int main()
{
    int x = 42;
    int *p = &x;

    cout << "x = " << x << endl;
    *p += 1;
    cout << "x = " << x << endl;
}
