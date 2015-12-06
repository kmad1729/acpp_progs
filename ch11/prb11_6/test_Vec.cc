#include "Vec.h"
#include <iostream>
#include <algorithm>
#include <string>
#include <iterator>

#define ARR_LIMIT 20

using std::cout;
using std::endl;

using std::copy;

using std::string;

using std::ostream_iterator;

int main() {
    Vec<int> v;
    string delim = "\n" + string(ARR_LIMIT, '*') + "\n";

    for(int i = 0; i < ARR_LIMIT; i++) {
        v.push_back(i * 2);
    }

    cout << "v --> " << endl;
    copy(v.begin(), v.end(), ostream_iterator<int>(cout, " "));
    cout << delim;
}
