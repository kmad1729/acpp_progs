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

    cout << "inserting 5 into the tree. It should be added to root -> right -> right" << endl;
    root = insert(root, 5);
    cout << "(root -> right -> right) = " <<
        (((root -> right) -> right) -> data);
    cout << delim;

    int lookup_int = 1;
    cout << lookup_int << " present in btree? " << lookup(root, lookup_int);
    cout << delim;

    lookup_int = -100;
    cout << lookup_int << " present in btree? " << lookup(root, lookup_int);
    cout << delim;

    lookup_int = 5;
    cout << lookup_int << " present in btree? " << lookup(root, lookup_int);
    cout << delim;
}
