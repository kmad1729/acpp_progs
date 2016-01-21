#include "Str.h"
#include <iostream>
#include <vector>
#include <cstdlib>
#include <cstring>

using std::cout;
using std::cin;
using std::endl;
using std::vector;

int main()
{
    Str empty;

    cout << "empty str --> (" << empty << ")" << endl;
    Str delim(20, '*');
    cout << "delim str --> (" << delim << ")" << endl;
    cout << "size of delim = " << delim.size() << endl;

    cout << delim << endl;

    cout << "testing iterators constructor " << endl;
    char vowels[] = {'a', 'e', 'i', 'o', 'u'};
    vector<char> vowel_vec(vowels, vowels + 5);

    Str vowel_str(vowel_vec.begin(), vowel_vec.end());

    cout << "vowel_str --> " << vowel_str << endl;

    cout << delim << endl;

    cout << "testing >> operator" << endl;
    Str name;
    cout << "please enter your name: ";
    cin >> name;
    cout << "Hello, (" << name << ")!" << endl;
    cout << delim << endl;

    cout << "testing data() function " << endl;
    Str s1 = "Test String..";
    char s1_cstr[] = "Test String..";
    cout << "s1 = (" << s1 << ")" << endl;
    cout << "s1_cstr = (" << s1_cstr << ")" << endl;
    if(std::strlen(s1_cstr) == s1.size()) {
        cout << "s1_cstr and s1 have the same length" << endl;
        if(std::memcmp(s1_cstr, s1.data(), s1.size()) == 0)
            cout << "s1_cstr and s1 have the same data" << endl;
    }

    cout << delim << endl;

    cout << "testing c_str() function" << endl;
    Str s2 = "12 fds aa *&^# @@\"";
    char* s2_cstr = new char[s2.size() + 1];
    std::strcpy(s2_cstr, s2.c_str());
    cout << "s2_cstr --> " << s2_cstr << endl;
    delete[] s2_cstr;
    cout << delim << endl;

    cout << "testing copy() function ";
    char *name_cstr_copy = new char[1000];
    Str::size_type num_char_copies = name.copy(name_cstr_copy, 1000);
    name_cstr_copy[num_char_copies] = '\0';
    cout << "cstr copy of name after copy function --> (" <<
        name_cstr_copy << ")" << endl;

    cout << "Number of characters copied = " << num_char_copies << endl;
    cout << delim << endl;
    delete[] name_cstr_copy;
    
}
