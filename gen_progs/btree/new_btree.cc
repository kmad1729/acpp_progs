#include "btree.h"

#include <iostream>
#include <algorithm>
#include <iterator>
#include <string>
#include <stdexcept>
#include <vector>

using std::endl;
using std::cout;

using std::copy;

using std::ostream_iterator;

using std::string;

using std::domain_error;

using std::vector;

int main()
{
    string delim = "\n" + string(20, '*') + "\n";

    Node* curr_tree = NULL;
    curr_tree = insert(curr_tree, 18);
    curr_tree = insert(curr_tree, 2);
    curr_tree = insert(curr_tree, 68);
    curr_tree = insert(curr_tree, -4);
    curr_tree = insert(curr_tree, 15);
    curr_tree = insert(curr_tree, 44);
    curr_tree = insert(curr_tree, -6);
    curr_tree = insert(curr_tree, 0);
    curr_tree = insert(curr_tree, 1);
    curr_tree = insert(curr_tree, 13);
    curr_tree = insert(curr_tree, 14);
    curr_tree = insert(curr_tree, 36);
    curr_tree = insert(curr_tree, 93);
    curr_tree = insert(curr_tree, 76);
    curr_tree = insert(curr_tree, 24);
    curr_tree = insert(curr_tree, 24);

    cout << "in-order traversalf of curr_tree expected \n" <<
        "-6 -4 0 1 2 13 14 15 18 24 24 36 44 68 76 93 got -->" << endl;
    printTree(curr_tree);
    cout << delim;

    int data_to_delete = 18;
    curr_tree = deleteNode(curr_tree, data_to_delete);
    cout << "in-order traversal after deleting " << data_to_delete << " expected \n" <<
        "-6 -4 0 1 2 13 14 15 24 24 36 44 68 76 93 got -->" << endl;
    printTree(curr_tree);
    cout << endl;

    data_to_delete = 24;
    curr_tree = deleteNode(curr_tree, data_to_delete);
    cout << "in-order traversal after deleting " << data_to_delete << " expected \n" <<
        "-6 -4 0 1 2 13 14 15 24 36 44 68 76 93 got -->" << endl;
    printTree(curr_tree);
    cout << endl;

    data_to_delete = 3;
    curr_tree = deleteNode(curr_tree, data_to_delete);
    cout << "in-order traversal after deleting " << data_to_delete << " expected \n" <<
        "-6 -4 0 1 2 13 14 15 24 36 44 68 76 93 got -->" << endl;
    printTree(curr_tree);
    cout << endl;

    data_to_delete = 13;
    curr_tree = deleteNode(curr_tree, data_to_delete);
    cout << "in-order traversal after deleting " << data_to_delete << " expected \n" <<
        "-6 -4 0 1 2 14 15 24 36 44 68 76 93 got -->" << endl;
    printTree(curr_tree);
    cout << endl;

    data_to_delete = 76;
    curr_tree = deleteNode(curr_tree, data_to_delete);
    cout << "in-order traversal after deleting " << data_to_delete << " expected \n" <<
        "-6 -4 0 1 2 14 15 24 36 44 68 93 got -->" << endl;
    printTree(curr_tree);
    cout << endl;



    cout << delim;

}
