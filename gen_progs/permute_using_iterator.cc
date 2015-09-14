#include <iostream>
#include <iterator>
#include <algorithm>
#include <string>
#include <vector>

using std::cout;
using std::endl;

using std::ostream_iterator;

using std::copy;
using std::swap;

using std::string;
using std::vector;

template <class T, class Ran>
void permute(Ran start, Ran b, Ran e)
{
    if(b == e){
        for(Ran x = start; x != e; x++)
            cout << *x << " " ;
        cout << endl;
    } else {
        for(Ran i = b; i < e; i++) {
            swap(*b, *i);
            permute<T>(start, b + 1, e);
            swap(*b, *i);
        }
    }
}

int main()
{
    vector<string> v;
    v.push_back("abc");
    v.push_back("ab");
    v.push_back("a");
    string delim = string(20, '*') + '\n';
    
    cout << delim;
    for(vector<string>::size_type i = 0; i < v.size(); i++) {
        cout << "permutaion of " << v[i] << " --> " << endl;
        permute<string>(v[i].begin(), v[i].begin(), v[i].end());
        cout << delim;
    }

    vector<int> v_ints;
    v_ints.push_back(1);
    v_ints.push_back(2);
    v_ints.push_back(3);
    cout << "permutaion of {";
    copy(v_ints.begin(), v_ints.end(), ostream_iterator<int>(cout, " "));
    cout << "} -->" << endl;
    permute<int>(v_ints.begin(), v_ints.begin(), v_ints.end());
    cout << delim;
}
