#include "btree.h"

#include <iostream>
#include <algorithm>
#include <iterator>
#include <string>

using std::endl;
using std::cout;

using std::copy;

using std::ostream_iterator;

using std::string;

int main()
{
    string delim = "\n" + string(20, '*') + "\n";

    Node* root = build123();

    cout << "root val = " << (root -> data);
    cout << delim;
    cout << "root left = " << ((root -> left) -> data);
    cout << delim;
    cout << "root right = " << ((root -> right) -> data);
    cout << delim;
}
