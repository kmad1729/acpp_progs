#include <vector>
#include <iostream>
#include <iterator>
#include <algorithm>

using std::vector;
using std::cout;
using std::endl;
using std::ostream_iterator;
using std::copy;
using std::string;


//TODO fix this function -->
template <class T>
void print_vec(const vector<T>& v)
{
    typedef typename vector<T>::size_type vec_sz;
    ostream_iterator<T> os_iter(cout, ", ");
    copy(v.begin(), v.end(), os_iter);
    cout << endl;
}

void print_vec(const vector<string>& v)
{
    typedef vector<string>::size_type vec_sz;
    ostream_iterator<string> os_iter(cout, ", ");
    copy(v.begin(), v.end(), os_iter);
    cout << endl;
}
