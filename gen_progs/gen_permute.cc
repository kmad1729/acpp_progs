//program to permute a given sequence
//

#include <iostream>
#include <algorithm>
#include <string>

using std::endl;
using std::cout;
using std::string;
using std::swap;

template <class Ran>
void permute(Ran b, Ran e, Ran start_index)
{
    if (start_index == e) {
        for(Ran i = b; i != e; i++) {
            cout << *i;
        }
        cout << endl;
    } else {
        for(Ran i = start_index; i != e; i++) {
            swap(*i, *start_index);
            permute(b, e, start_index + 1);
            swap(*i, *start_index);
        }
    }

}

int main()
{
    string s = "abc";
    cout << "permutation of (" << s << ") -->" << endl;
    permute(s.begin(), s.end(), s.begin());
}
