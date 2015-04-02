#include "my_include.h"

template <class In, class Rev>
bool my_equal(In b, In e, Rev f)
{
    while(b != e) {
        if(*b++ != *f++) {
            return false;
        }
    }
    return true;
}

bool isPalindrome(const string& s)
{
    return my_equal(s.begin(), s.end(), s.rbegin());
}

int main()
{
    vector<string> words;
    words.push_back("palindrome");
    words.push_back("madam");
    words.push_back("frooti");
    words.push_back("abcdedcba");

    for(vector<string>::size_type i = 0; i < words.size(); i++) {
        cout << "Is \"" << words[i] << "\" a palindrome? ";
        if(isPalindrome(words[i])) {
            cout << "yes ";
        } else {
            cout << "no ";
        }
        cout << endl;
    }
    
}
