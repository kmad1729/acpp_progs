#include <string>
#include <iostream>
#include <vector>
#include <cctype>

using std::string;

using std::cout;
using std::cin;
using std::endl;

using std::vector;

using std::isspace;

vector<string> split(const string& s)
{
    vector<string> ret;
    typedef string::size_type str_sz;
    str_sz i = 0;

    while(i != s.size()) {
        //ignoring the leading blanks
        while(i != s.size() && isspace(s[i])) {
            i++;
        }

        //found the first non space and non-last index
        str_sz j = i;
        while(j != s.size() && !isspace(s[j])) {
            j++;
        }

        if(i != j) {
            ret.push_back(s.substr(i, j - i));
        }

        i = j;
    }
    return ret;
}

int main()
{
    vector<string> test_strings;
    test_strings.push_back("    abcd");
    test_strings.push_back("");
    test_strings.push_back("abcd ad  adaf ddd");
    test_strings.push_back("            ");
    test_strings.push_back("    dfa    ");
    test_strings.push_back("dfa     ");

    for(vector<string>::size_type i = 0; i != test_strings.size(); i++) {
        cout << "number of strings in (" << test_strings[i] << ") = " << \
            split(test_strings[i]).size() << endl;
    }
    return 0;
}
