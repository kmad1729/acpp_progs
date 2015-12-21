#include "Str.h"
#include "Vec.h"
#include <iostream>
#include <iterator>
#include <algorithm>

using std::cout;
using std::endl;
using std::ostream_iterator;
using std::copy;
using std::back_inserter;

int main()
{
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


    //Str new_char(new_chars.begin(), new_chars.end());

    cout << "new char -->" << endl;
    copy(new_chars.begin(), new_chars.end(), ostream_iterator<char>(cout, " "));
    cout << endl;

    cout << "new ints -->" << endl;
    copy(ints.begin(), ints.end(), ostream_iterator<int>(cout, " "));
    cout << endl;
    //cout << new_char << endl;

}
