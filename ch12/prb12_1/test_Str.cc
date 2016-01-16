#include "Str.h"
#include <iostream>
#include <vector>

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
}
