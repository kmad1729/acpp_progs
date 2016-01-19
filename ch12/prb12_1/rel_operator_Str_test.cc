#include "Str.h"
#include <iostream>
#include <string>

using std::cout;
using std::cin;
using std::endl;

using std::string;

int main()
{
    Str delim(20, '*');
    Str s1("apple");
    char* c_str1 = "apple";
    Str s2("mango");

    cout << "s1 = (" << s1 << ")" << endl;
    cout << "s2 = (" << s2 << ")" << endl;
    cout << delim << endl;

    cout << "testing == rel operator" << endl;
    if(s1 == s2) 
        cout << s1 << " == " << s2 << "? " << "true";
    else
        cout << s1 << " == " << s2 << "? " << "false";

    if(s1 == s1) 
        cout << s1 << " == " << s1 << "? " << "true";
    else
        cout << s1 << " == " << s1 << "? " << "false";

    cout << delim << endl;
}