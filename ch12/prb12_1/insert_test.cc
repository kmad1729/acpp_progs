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
    Str single_char_str("f");
    cout << "single_char_str --> (" << single_char_str << ")" << endl;
    cout << delim << endl;
    Str s1("as");
    cout << "testing insert function" << endl;

    cout << "s1 --> (" << s1 << ")" << endl;
    char cstr_to_insert[] = "pplie";
    size_t cstr_size = sizeof(cstr_to_insert);
    cout << "inserting (" << cstr_to_insert << ") at s1.begin() + 1" << endl;

    s1.insert(s1.begin() + 1, cstr_to_insert, cstr_to_insert + cstr_size);

    cout << "s1 --> (" << s1 << ")" << endl;

    cout << delim << endl;

    Str insert_str("this ");
    cout << "inserting (" << insert_str << ") at s1.begin()" << endl;
    s1.insert(s1.begin(), insert_str.begin(), insert_str.end());
    cout << "s1 --> (" << s1 << ")" << endl;

    cout << delim << endl;

    insert_str = "And also ";
    cout << "inserting (" << insert_str << ") at s1.begin()" << endl;
    s1.insert(s1.begin(), insert_str.begin(), insert_str.end());
    cout << "s1 --> (" << s1 << ")" << endl;

    cout << delim << endl;

    insert_str = " to all objects";
    cout << "inserting (" << insert_str << ") at s1.begin()" << endl;
    s1.insert(s1.end(), insert_str.begin(), insert_str.end());
    cout << "s1 --> (" << s1 << ")" << endl;

    cout << delim << endl;

}
