//program to demonstrate remove function in STL
//

#include "my_include.h"

int main()
{
    string s;
    for(char c1 = '9'; c1 >= '0'; c1--) {
        for(char c2 = '9'; c2 >= '0'; c2--) {
            s.push_back(c1);
            s.push_back(c2);
        }
    }
    cout << delim;
    cout << "The big number -->" << endl;
    cout << s << endl;
    string::size_type s1 = s.end() - s.begin();
    cout << delim;

    cout << "removing all the 9s" << endl;
    cout << delim;

    char char_to_remove = '9';
    string::const_iterator i = remove(s.begin(), s.end(), char_to_remove);
    string::size_type s2 = i - s.begin();
    cout << s << endl;
    cout << delim;

    cout << "size of string before = " << s1 << " and after = " << s2 << endl;
    cout << delim;
}
