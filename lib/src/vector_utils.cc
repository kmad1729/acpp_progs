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


template <typename T>
void print_vec(const std::vector<T>& v)
{
    typedef typename vector<T>::size_type vec_sz;
    for(vec_sz i = 0; i != v.size(); i++) {
        if (i == 0) cout << v[i];
        else cout << ", " << v[i];
    }
    std::cout << std::endl;
}

template void print_vec(const vector<string>&);
template void print_vec(const vector<int>&);
template void print_vec(const vector<double>&);

