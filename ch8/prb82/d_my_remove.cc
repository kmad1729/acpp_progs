//program to demonstrate remove function in STL
//

#include "my_include.h"

template <class For, class E>
For my_remove(For b, For e, E elem)
{
    while(b != e) {
        if(*b == elem)
            *b = *(b + 1);
        b++;
    }
    return b;
}


int main()
{
    string s;
    for(char c1 = '9'; c1 >= '0'; c1--) {
        for(char c2 = '9'; c2 >= '0'; c2--) {
            if (c1 != '0')
                s.push_back(c1);
            s.push_back(c2);
        }
    }
    cout << delim;
    cout << "The big number -->" << endl;
    cout << s << endl;
    string::size_type s1 = s.end() - s.begin();
    cout << delim;


    char char_to_remove = '9';
    
    cout << "removing all the " << char_to_remove << "s" << endl;
    cout << delim;

    string::iterator i = remove(s.begin(), s.end(), char_to_remove);
    string::size_type s2 = i - s.begin();
    cout << string(s.begin(), i) << endl;
    cout << delim;

    cout << "size of string before = " << s1 << " and after = " << s2 << endl;
    cout << delim;


    char_to_remove = '0';
    cout << "removing all the " << char_to_remove << "s" << endl;
    cout << delim;

    i = my_remove(s.begin(), i, char_to_remove);
    string::size_type s3 = i - s.begin();
    cout << string(s.begin(), i) << endl;
    cout << delim;

    cout << "size of string before = " << s2 << " and after = " << s3 << endl;
    cout << delim;
}
