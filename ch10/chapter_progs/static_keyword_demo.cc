#include <iostream>

using std::cout;
using std::endl;

int func1()
{
    static int i = 0;
    return i++;
}

int main()
{
    cout << "i = " << func1() << endl;
    cout << "i = " << func1() << endl;
    cout << "i = " << func1() << endl;
    cout << "i = " << func1() << endl;
    return 0;
}
