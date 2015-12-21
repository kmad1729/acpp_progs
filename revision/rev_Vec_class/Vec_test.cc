#include "Vec.h"
#include <iostream>
#include <iterator>
#include <string>
#include <algorithm>

using std::cout;
using std::endl;

using std::ostream_iterator;

using std::string;

using std::copy;

int main()
{
    Vec<int> my_vec;
    int num_limit = 20;
    for(int i = 0; i < num_limit; i++) my_vec.push_back(i * 2);
    Vec<int> new_vec = my_vec;

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

}
