#include <iostream>
#include <string>
#include <iterator>
#include <algorithm>

#include "Vec.h"

using std::cout;
using std::endl;
using std::string;
using std::ostream_iterator;
using std::copy;


int main()
{
    Vec<int> v;
    Vec<int> vi(100, 5);

    cout << "vi --> " << endl;
    copy(vi.begin(), vi.end(), ostream_iterator<int>(cout, " "));
    cout << endl;

    Vec<string> vs(4, "haha ");
    copy(vs.begin(), vs.end(), ostream_iterator<string>(cout, " "));
    cout << endl;
}
