//program to demonstrate remove_if function from stl
//removes all vowels in a string
#include <iostream>
#include <string>
#include <vector>
#include <algorithm>

using std::cout;
using std::cin;
using std::endl;

using std::string;

using std::vector;

using std::find;
using std::remove_if;

bool vowel(char c)
{
    static const string vowels = "aeiou";
    return (find(vowels.begin(), vowels.end(), c) != vowels.end());
}

int main()
{
    vector<string> v;
    v.push_back("kashyap");
    v.push_back("rumpelstiltskin");
    v.push_back("");
    v.push_back("aeiou");
    v.push_back("tryst");
    string delim = string(20, '*') + "\n";

    for(vector<string>::size_type i = 0; i != v.size();
            i++) {
        cout << "string = (" << v[i] << ") " << endl;
        cout << "after removing vowels --> (";
        string::iterator vowel_start = remove_if(v[i].begin(), v[i].end(), vowel);
        cout << string(v[i].begin(), vowel_start) << ")" << endl;
        cout << delim;
    }
}
