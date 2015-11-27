#include <iostream>

using std::cout;
using std::endl;

int* pointer_to_static()
{
    static int x;
    return &x;
}


int main()
{
    int *x = pointer_to_static();
    int *y = pointer_to_static();
    cout << "setting *x to 42 " << endl;
    *x = 42;
    cout << "*x = " << *x << " *y = " << *y << endl;
    cout << "setting *y to 1729" << endl;
    *y = 1729;
    cout << "*x = " << *x << " *y = " << *y << endl;
    cout << "setting z to pointer_to_static" << endl;
    int *z = pointer_to_static();
    cout << "*z = " << *z << endl;

    cout << "x = " << x << endl;
    cout << "y = " << y << endl;
    cout << "z = " << z << endl;

    if (x == y) {
        cout << "memory addresses of x and y are same!" << endl;
    }
}
