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

    cout << "over-writing name variable " << endl;
    cout << "enter your frineds name: ";
    cin >> name;
    cout << "hello to " << name << " too!" << endl;


    cout << delim << endl;

    cout << "Please enter a long string with spaces for one more test. " <<
        "I will print out each word in a new line: ";

    Str tmp;
    Vec<Str> v;
    while(cin >> tmp)
        v.push_back(tmp);

    cout << endl;
    for(Str::size_type i = 0; i < v.size(); i++)
        cout << v[i] << endl;

    cout << delim << endl;
}
