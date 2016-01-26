//#define TEST_OUTPUT_OPER_OSTREAM_ITER
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
    char c_str1[] = "apple";
    Str s2("mango");
    Str s3(c_str1);
    cout << "checking << operator implemented with ostream_iterator" << endl;

    cout << delim << endl;
    cout << "s1 --> " << s1 << endl;
    cout << "s2 --> " << s2 << endl;
    cout << "s3 --> " << s3 << endl;

}
