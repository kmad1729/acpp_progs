//program to demo remove_copy function from stl

#include "my_include.h"

template <class For, class Out, class Elem>
Out my_remove_copy(For b, For e, Out result, Elem target)
{
    while(b != e) {
        if(*b == target) {
            *result++ = *b;
        }
        b++;
    }
    return result;
}

int main()
{
    //building the long string of numbers
    string s;
    for(char c1 = '9'; c1 >= '0'; c1--) {
        for(char c2 = '9'; c2 >= '0'; c2--) {
            if(c1 != '0')
                s.push_back(c1);
            s.push_back(c2);
        }
    }

    cout << delim;
    cout << "input long string of numbers -->" << endl;
    cout << s << endl;
    cout << delim;

    char c = '2';
    string s_without_2;
    remove_copy(s.begin(), s.end(), back_inserter(s_without_2), c);

    cout << delim;
    cout << "s without " << c << "s stl" << endl;
    cout << s_without_2 << endl;
    cout << delim;

    c = '2';
    string s_without_0;
    remove_copy(s.begin(), s.end(), back_inserter(s_without_0), c);

    cout << delim;
    cout << "s without " << c << "s my_remove_copy" << endl;
    cout << s_without_0 << endl;
    cout << delim;


    return 0;
}
