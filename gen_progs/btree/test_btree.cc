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

    Node* emptyTree = NULL;
    cout << "size of emptyTree = " << size(emptyTree) << endl;
    cout << "size of current tree = " << size(root);
    cout << delim;

    Node* badBST = NULL;
    cout << "creating a bad binary search tree (Very linear)" << endl;
    for(int i = -20; i < 21; i++)
        badBST = insert(badBST, i);
    cout << "size of badBST = " << size(badBST) << endl;
    cout << "maxDepth of badBST (expected 41) = " << maxDepth(badBST) << endl;

    cout << "maxDepth of current Tree (expected 3) = " << maxDepth(root) << endl;
    cout << "maxDepth of emptyTree (expected 0) = " << maxDepth(emptyTree);

    cout << delim;
}
