//program to demonstrate input and output iterator categories
#include <iostream>
#include <iterator>
#include <algorithm>
#include <vector>

using std::cout;
using std::cin;
using std::endl;

using std::istream_iterator;
using std::ostream_iterator;
using std::back_inserter;

using std::copy;

using std::vector;

int main()
{
    cout << "type a list of numbers and EOF at the end" << endl;
    vector<int> v;
    copy(istream_iterator<int>(cin), istream_iterator<int>(), back_inserter(v));

    cout << "all the numbers times 2 -->" << endl;

    for(vector<int>::iterator i = v.begin(); i != v.end(); i++) {
        *i = (*i * 2);
    }

    copy(v.begin(), v.end(), ostream_iterator<int>(cout, " "));
    cout << endl;

}
