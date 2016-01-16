#include "Str.h"
#include "Vec.h"
#include <iostream>
#include <iterator>
#include <algorithm>
#include <string>
#include <cstring>

using std::cout;
using std::endl;
using std::ostream_iterator;
using std::copy;
using std::back_inserter;
using std::string;

int main()
{
    cout << "create Str using replicate constructor" << endl;
    Str delim(20, '*');

    Str s1 = "This is a simple Str string";

    cout << "s1 --> (" << s1 << ")" << endl;

    cout << "testing c_str function -->" << endl;
    cout << "size of s1 = " << s1.size() << endl;
    char *cstr = new char[delim.size() + 1];
    std::strcpy(cstr, s1.c_str());

    cout << "cstr of s1 --> (" << cstr << ")" << endl;

    cout << "size of s1 = " << s1.size() << endl;

    cout << delim << endl;

    string s = "hello";
    cout << *s.begin() << endl;
    cout << *(s.end() - 1) << endl;
    s.push_back('a');
    cout << s << endl;

}
