#include "Str.h"
#include "Vec.h"
#include <iostream>
#include <iterator>
#include <algorithm>
#include <string>

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
    cout << "delim -->" << endl;
    //cout << delim << endl;

    Vec<char> new_chars;
    Vec<int> ints;
    for(int i = 0; i < 20; i++) {
        if(i % 2 == 0) {
            new_chars.push_back('1');
            ints.push_back(i);
        } 
        else {
            new_chars.push_back('2');
            ints.push_back(i);
        }
    }


    cout << "creating Str using Input iterator constructor -->" << endl;
    Str new_char(new_chars.begin(), new_chars.end());

    cout << "creating Str using const char* constructor -->" << endl;
    string s1 = "Hello";
    Str s2(s1.c_str());

    cout << "creating Str using initialization operator which in-turn uses" <<
        " const char* constructor" << endl;
    Str s3 = "Hello";
    //cout << "s3 --> (" << s3 << ")" << endl;

    cout << "assining Str to another const char*. It uses const char*" << 
        " constructor a user-defined conversion" << endl;
    s3 = "World";


    cout << "new char -->" << endl;
    copy(new_chars.begin(), new_chars.end(), ostream_iterator<char>(cout, " "));
    cout << endl;

    cout << "new ints -->" << endl;
    copy(ints.begin(), ints.end(), ostream_iterator<int>(cout, " "));
    cout << endl;
    //cout << new_char << endl;

}
