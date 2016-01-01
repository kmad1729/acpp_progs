#include "Vec.h"
#include <iostream>
#include <iterator>
#include <string>
#include <algorithm>
#include <stdexcept>

using std::cout;
using std::endl;

using std::ostream_iterator;

using std::string;

using std::copy;
using std::back_inserter;

int main()
{
    Vec<int> my_vec;
    int num_limit = 20;
    for(int i = 0; i < num_limit; i++) my_vec.push_back(i * 2);
    Vec<int> new_vec = my_vec;
    Vec<int> copy_vec;
    copy(new_vec.begin(), new_vec.end(), back_inserter(copy_vec));

    Vec<string> Ls(20, "L");

    string delim = "\n" + string(20, '*') + "\n";
    cout << "my_vec --> " << endl;
    copy(my_vec.begin(), my_vec.end(), ostream_iterator<int>(cout, ", "));
    cout << delim;

    cout << "new_vec --> " << endl;
    copy(new_vec.begin(), new_vec.end(), ostream_iterator<int>(cout, ", "));
    cout << delim;

    cout << "Ls --> " << endl;
    copy(Ls.begin(), Ls.end(), ostream_iterator<string>(cout, ", "));
    cout << delim;

    cout << "copy_vec --> " << endl;
    copy(copy_vec.begin(), copy_vec.end(), ostream_iterator<int>(cout, ", "));
    cout << delim;

    cout << "iterator using const iterator -->" << endl;
    for(Vec<int>::const_iterator i = my_vec.begin(); i != my_vec.end(); i++) {
        cout << *i << " ";
    }
    cout << delim;

}
