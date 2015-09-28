//program to demonstrate remove function in STL
//

#include "my_include.h"

template <class For, class E>
For my_remove(For b, For e, E elem)
{
    For result = b;
    while(b != e) {
        if( (*b) != elem) {
            *result = *b;
            result++;
        }
        b++;
    }
    return result;
}


void remove_analyze(string s, char char_to_remove_using_stl_remove, char char_to_remove_using_my_remove)
{
    cout << delim;
    cout << "The big number -->" << endl;
    cout << s << endl;
    string::size_type s1 = s.end() - s.begin();
    cout << delim;


    
    cout << "removing all the " << char_to_remove_using_stl_remove << "s" << endl;
    cout << delim;

    string::iterator i = remove(s.begin(), s.end(), char_to_remove_using_stl_remove);
    string::size_type s2 = i - s.begin();
    cout << string(s.begin(), i) << endl;
    cout << delim;

    cout << "size of string before = " << s1 << " and after = " << s2 << endl;
    cout << delim;


    cout << "removing all the " << char_to_remove_using_my_remove << "s" << endl;
    cout << delim;

    i = my_remove(s.begin(), i, char_to_remove_using_my_remove);
    string::size_type s3 = i - s.begin();
    cout << string(s.begin(), i) << endl;
    cout << delim;

    cout << "size of string before = " << s2 << " and after = " << s3 << endl;
    cout << delim;
}


int main()
{
    string s;
    for(char c2 = '9'; c2 >= '0'; c2--) {
        if(c2 > '5') 
            s.push_back('9');
        else if (c2 < '3') 
            s.push_back('0');
        else
            s.push_back(c2);
    }

    remove_analyze(s, '9', '0');
    reverse(s.begin(), s.end());
    remove_analyze(s, '9', '0');
}
