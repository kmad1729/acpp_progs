#include "btree.h"

#include <iostream>
#include <algorithm>
#include <iterator>
#include <string>
#include <stdexcept>

using std::endl;
using std::cout;

using std::copy;

using std::ostream_iterator;

using std::string;

using std::domain_error;

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

    Node* singleNodeTree = NULL;
    singleNodeTree = insert(singleNodeTree, 42);

    Node* badBST_left_linear = NULL;
    for(int i = 10; i >= -10; i--)
        badBST_left_linear = insert(badBST_left_linear, i);

    cout << "min value in singleNodeTree (expected 42) = " << minValue(singleNodeTree) << endl;
    cout << "max value in singleNodeTree (expected 42) = " << maxValue(singleNodeTree) << endl;

    cout << "min value in badBST_left_linear (expected -10) = " << minValue(badBST_left_linear) << endl;
    cout << "max value in badBST_left_linear (expected 10) = " << maxValue(badBST_left_linear) << endl;
    cout << endl;

    cout << "min value in badBST right liner (expected -20) = " << minValue(badBST) << endl;
    cout << "max value in badBST right liner (expected 20) = " << maxValue(badBST) << endl;
    cout << endl;

    cout << "min value in current tree (expected 1) = " << minValue(root) << endl;
    cout << "max value in current tree (expected 5) = " << maxValue(root) << endl;
    cout << endl;

    cout << "trying to find minimum value from an empty tree" << endl;
    try {
        cout << "min value in emptyTree = (expected exception) = " << endl <<
            "\t" << minValue(emptyTree);
    } catch (domain_error e) {
        cout << e.what() << endl;
    }

    cout << "trying to find maximum value from an empty tree" << endl;
    try {
        cout << "max value in emptyTree = (expected exception) = " << endl << 
            "\t" << maxValue(emptyTree);
    } catch (domain_error e) {
        cout << e.what();
    }
    cout << delim;


}
