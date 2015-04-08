#include <iostream>
#include <vector>
#include <iterator>
#include <algorithm>
#include <string>


using std::cout;
using std::endl;
using std::ostream_iterator;
using std::copy;
using std::vector;
using std::ostream;
using std::string;

//template <class T>
void print_vector(const vector<string>& v, ostream& os)
{
    ostream_iterator<string> os_iter(os, "###");
    copy(v.begin(), v.end(), os_iter);
    cout << endl;
}

