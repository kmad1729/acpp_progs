#include <iostream>
#include <algorithm>
#include <vector>
#include <iterator>

using std::cout;
using std::endl;
using std::copy;
using std::vector;
using std::ostream_iterator;

void print_int_vec(const vector<int>& v)
{
    ostream_iterator<int> os_iter (cout, ",");
    copy(v.begin(), v.end(), os_iter);
    cout << endl;
}

int main()
{
    vector<int> u(10,100);
    cout << "vector u --> " << endl;
    print_int_vec(u);

    vector<int> v;
    cout << "vector v --> " << endl;
    print_int_vec(v);

    // The following code should not do anything
    // WRONG!!! : The following code produces segfault!
    copy(u.begin(), u.end(), v.begin());

    cout << "vector v after copy--> " << endl;
    print_int_vec(v);
}

