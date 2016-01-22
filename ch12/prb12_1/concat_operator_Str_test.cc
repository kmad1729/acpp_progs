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
    //char c_str1[] = "apple";
    Str s2("mango");

    cout << "s1 --> " << s1 << endl;
    cout << "s2 --> " << s2 << endl;
    cout << delim << endl;
    cout << "testing += operator" << endl;
    s1 += s2;
    cout << "s1 --> " << s1 << endl;
    cout << "s2 --> " << s2 << endl;
    cout << delim << endl;

    cout << "testing + operator" << endl;
    Str s3 = s1 + s2 ;//+ c_str1;
    cout << "s3 = s1 + s2 + c_str1 " << endl;
    cout << "s3 --> (" << s3 << ")" << endl;
    cout << "s1 --> " << s1 << endl;
    //s1 = "foo";
    cout << delim << endl;

}
