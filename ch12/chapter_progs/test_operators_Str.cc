#include "Str.h"
#include "Vec.h"
#include <iostream>
#include <iterator>
#include <algorithm>
#include <string>

using std::cout;
using std::endl;
using std::cin;

using std::ostream_iterator;
using std::copy;
using std::back_inserter;
using std::string;

int main() {
    Str name;
    Str delim(20, '*');
    cout << "testing >> operator. saving name to variable \"name\"" << endl;
    cout << delim << endl;

    cout << "Please enter your name: ";
    cin >> name;
    cout << "Hello, " << name << "!" << endl;

    cout << "over-writing name varialble " << endl;
    cout << "enter your frineds name: ";
    cin >> name;
    cout << "hello to " << name << " too!" << endl;
}
