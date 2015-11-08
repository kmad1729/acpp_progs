//program to permute a given sequence
//

#include <iostream>
#include <algorithm>
#include <string>

using std::endl;
using std::cout;

template <class Ran>
void permute(Ran start_index, Ran b, Ran e)
{
}

int main()
{
    string s = "abc";
    cout << "permutation of (" << s << ") -->" << endl;
    permute(s.begin(), s.begin(), s.end());
}
