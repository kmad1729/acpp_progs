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

    cout << "printing inorder traversal of emptyTree -->" << endl << "(";
    printTree(emptyTree);
    cout << ")" << endl;

    cout << "printing inorder traversal of singleNodeTree -->" << endl << "(";
    printTree(singleNodeTree);
    cout << ")" << endl;

    cout << "printing inorder traversal of badBST -->" << endl << "(";
    printTree(badBST);
    cout << ")" << endl;

    cout << "printing inorder traversal of badBST_left_linear -->" << endl << "(";
    printTree(badBST_left_linear);
    cout << ")" << endl;

    cout << "printing inorder traversal of current tree -->" << endl << "(";
    printTree(root);
    cout << ")" << delim;

    cout << "printing post order traversal of emptyTree -->" << endl << "(";
    printPostOrder(emptyTree);
    cout << ")" << endl;

    cout << "printing post order traversal of singleNodeTree -->" << endl << "(";
    printPostOrder(singleNodeTree);
    cout << ")" << endl;

    cout << "printing post order traversal of badBST -->" << endl << "(";
    printPostOrder(badBST);
    cout << ")" << endl;

    cout << "printing post order traversal of badBST_left_linear -->" << endl << "(";
    printPostOrder(badBST_left_linear);
    cout << ")" << endl;

    cout << "printing post order traversal of current tree -->" << endl << "(";
    printPostOrder(root);
    cout << ")" << delim;

    Node* neg_tree = NULL;
    neg_tree = insert(neg_tree, -6);
    neg_tree = insert(neg_tree, -6);
    neg_tree = insert(neg_tree, -42);
    neg_tree = insert(neg_tree, -41);
    neg_tree = insert(neg_tree, -108);
    neg_tree = insert(neg_tree, 0);
    neg_tree = insert(neg_tree, 0);

    cout << "in order traversal of neg_tree --> " << endl << "(";
    printTree(neg_tree);
    cout << ")" << endl;

    cout << "post order traversal of neg_tree --> " << endl << "(";
    printPostOrder(neg_tree);
    cout << ")" << endl;

    int target_sum = -6;
    cout << "neg_tree has path sum " << target_sum << " (expected 1) ? " <<
        hasPathSum(neg_tree, target_sum) << endl;

    target_sum = -12;
    cout << "neg_tree has path sum " << target_sum << " (expected 0) ? " <<
        hasPathSum(neg_tree, target_sum) << endl;

    target_sum = -102;
    cout << "neg_tree has path sum " << target_sum << " (expected 0) ? " <<
        hasPathSum(neg_tree, target_sum) << endl;

    target_sum = -162;
    cout << "neg_tree has path sum " << target_sum << " (expected 1) ? " <<
        hasPathSum(neg_tree, target_sum) << endl;

    target_sum = -95;
    cout << "neg_tree has path sum " << target_sum << " (expected 1) ? " <<
        hasPathSum(neg_tree, target_sum) << endl;

    target_sum = 42;
    cout << "singleNodeTree has path sum " << target_sum << " (expected 1) ? " <<
        hasPathSum(singleNodeTree, target_sum) << endl;

    target_sum = 0;
    cout << "singleNodeTree has path sum " << target_sum << " (expected 0) ? " <<
        hasPathSum(singleNodeTree, target_sum) << endl;

    target_sum = 0;
    cout << "emptyTree has path sum " << target_sum << " (expected 1) ? " <<
        hasPathSum(emptyTree, target_sum) << endl;

    target_sum = 3;
    cout << "current tree has path sum " << target_sum << " (expected 1) ? " <<
        hasPathSum(root, target_sum) << endl;

    target_sum = 2;
    cout << "current tree has path sum " << target_sum << " (expected 0) ? " <<
        hasPathSum(root, target_sum) << endl;

    target_sum = 10;
    cout << "current tree has path sum " << target_sum << " (expected 1) ? " <<
        hasPathSum(root, target_sum) << endl;

    target_sum = 3;
    cout << "current tree has path sum " << target_sum << " (expected 0) ? " <<
        hasPathSum(root, target_sum) << endl;

    target_sum = 5;
    cout << "current tree has path sum " << target_sum << " (expected 0) ? " <<
        hasPathSum(root, target_sum) << endl;

    target_sum = 0;
    cout << "badBST tree has path sum " << target_sum << " (expected 1) ? " <<
        hasPathSum(badBST, target_sum) << endl;

    target_sum = 0;
    cout << "badBST_left_linear tree has path sum " << target_sum << " (expected 1) ? " <<
        hasPathSum(badBST_left_linear, target_sum) << endl;


    target_sum = 20;
    cout << "badBST_left_linear tree has path sum " << target_sum << " (expected 0) ? " <<
        hasPathSum(badBST_left_linear, target_sum) << endl;

    cout << delim;

    cout << "root-to-leaf paths in current tree --> " << endl;
    printPaths(root);
    cout << endl;

    cout << "root-to-leaf paths in singleNodeTree tree --> " << endl;
    printPaths(singleNodeTree);
    cout << endl;

    cout << "root-to-leaf paths in emptyTree tree --> " << endl;
    printPaths(emptyTree);
    cout << endl;

    cout << "root-to-leaf paths in badBST tree --> " << endl;
    printPaths(badBST);
    cout << endl;

    cout << "root-to-leaf paths in badBST_left_linear tree --> " << endl;
    printPaths(badBST_left_linear);
    cout << endl;

    cout << "root-to-leaf paths in neg_tree tree --> " << endl;
    printPaths(neg_tree);

    cout << delim;

    mirror(root);
    cout << "in-order traversal of current tree after mirror -->" << endl;
    printTree(root);
    cout << endl;
    cout << "post-order traversal of current tree after mirror -->" << endl;
    printPostOrder(root);
    cout << endl;
    mirror(root);
    cout << endl;

    mirror(neg_tree);
    cout << "in-order traversal of neg_tree tree after mirror -->" << endl;
    printTree(neg_tree);
    cout << endl;
    cout << "post-order traversal of neg_tree tree after mirror -->" << endl;
    printPostOrder(neg_tree);
    cout << endl;
    mirror(neg_tree);
    cout << endl;

    cout << delim;

    doubleTree(root);
    cout << "in-order traversal of current tree after doubleTree -->" << endl;
    printTree(root);
    cout << endl;
    cout << "post-order traversal of current tree after doubleTree -->" << endl;
    printPostOrder(root);
    cout << endl;

    doubleTree(neg_tree);
    cout << "in-order traversal of neg_tree tree after doubleTree -->" << endl;
    printTree(neg_tree);
    cout << endl;
    cout << "post-order traversal of neg_tree tree after doubleTree -->" << endl;
    printPostOrder(neg_tree);
    cout << endl;

    cout << delim;
    
    Node* copy_root = copyTree(root);
    cout << "in-order traversal of current tree and copy tree-->" << endl;
    printTree(root);
    cout << endl;
    printTree(copy_root);
    cout << endl;

    cout << "post-order traversal of current tree and copy tree -->" << endl;
    printPostOrder(root);
    cout << endl;
    printPostOrder(copy_root);
    cout << endl;

    cout << endl;

    Node* copy_neg_tree = copyTree(neg_tree);
    cout << "in-order traversal of neg_tree tree and copy neg_tree-->" << endl;
    printTree(neg_tree);
    cout << endl;
    printTree(copy_neg_tree);
    cout << endl;

    cout << "post-order traversal of neg_tree tree and copy neg_tree -->" << endl;
    printPostOrder(neg_tree);
    cout << endl;
    printPostOrder(copy_neg_tree);
    cout << endl;

    cout << delim;

    Node *copy_emptyTree = NULL;
    cout << "emptyTree mirror of emptyTree (expected 1)? " << sameTree(emptyTree, emptyTree) << endl;
    cout << "emptyTree mirror of copy_emptyTree (expected 1)? " << sameTree(emptyTree, copy_emptyTree) << endl;

    cout << "neg_tree mirror of copy_neg_tree (expected 1)? " << sameTree(neg_tree, copy_neg_tree) << endl;


    cout << "current tree mirror of neg_tree (expected 0)? " << sameTree(root, neg_tree) << endl;

    cout << "current tree mirror of copy_current_tree (expected 1)? " << sameTree(root, copy_root) << endl;

    cout << "current tree mirror of emptyTree (expected 0)? " << sameTree(root, emptyTree) << endl;

    cout << delim;
}
