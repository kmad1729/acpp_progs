#include "Str.h"
#include <iostream>

using std::cout;
using std::cin;
using std::endl;

int main()
{
    Str empty;

    cout << "empty str --> (" << empty << ")" << endl;
    Str delim(20, '*');
    cout << "delim str --> (" << delim << ")" << endl;
    cout << "size of delim = " << delim.size() << endl;
}
