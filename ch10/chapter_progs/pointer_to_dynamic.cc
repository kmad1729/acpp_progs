#include <iostream>

using std::cout;
using std::endl;

int* pointer_to_dynamic()
{
    return new int(0);
}


int main()
{
    int *x = pointer_to_dynamic();
    int *y = pointer_to_dynamic();
    *x = 42;
    *y = 66;
    cout << "*x = " << x << endl;
    cout << "x is a pointer to int. x = " << x << endl;
    cout << "*y = " << y << endl;
    cout << "y is a pointer to int. y = " << y << endl;

    if(x != y) {
        cout << "memory addresses of x and y are different!" << endl;
    }
}
