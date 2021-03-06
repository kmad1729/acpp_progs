#include <iostream>
#include <iterator>
#include <vector>
#include <string>
#include <algorithm>

using std::cout;
using std::endl;
using std::ostream_iterator;
using std::vector;
using std::string;
using std::swap;
using std::reverse;
using std::copy;
//implement the swap function used in reverse function
//

template <class Elem>
void my_swap(Elem& x, Elem& y)
{
    Elem tmp = x;
    cout << "tmp " << tmp << " x = " << x << " y = " << y << endl;
    x = y;
    cout << "tmp " << tmp << " x = " << x << " y = " << y << endl;
    y = tmp;
    cout << "tmp " << tmp << " x = " << x << " y = " << y << endl;
}

//implementation of reverse function from stl
template <class Bi>
void my_reverse(Bi first, Bi last)
{
    while(first < last) {
        --last;
        if(first != last) {
            my_swap(*first++, *last);
        }
    }
}


int main()
{
    vector<int> v;
    for(int i = 1; i < 9; i++) v.push_back(i);
    string delim = '\n' + string(20, '*') + '\n';
    cout << "vector -->" << endl;
    copy(v.begin(), v.end(), ostream_iterator<int>(cout, " "));
    cout << delim;

    my_reverse(v.begin(), v.end());

    cout << "reversed vector -->" << endl;
    copy(v.begin(), v.end(), ostream_iterator<int>(cout, " "));
    cout << delim;

}
