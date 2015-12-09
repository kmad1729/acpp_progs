//question: given pre-order and in-order traversal vectors
//reconstruct the binary tree. Assume no repeating values.

#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
#include <stdexcept>
#include <iterator>

using std::cout;
using std::endl;
using std::vector;
using std::string;
using std::domain_error;
using std::ostream_iterator;
using std::copy;

struct TreeNode {
    int data;
    TreeNode *left_child;
    TreeNode *right_child;

    TreeNode(int d) {
        data = d;
        left_child = right_child = NULL;
    }

};

void print_post_order(TreeNode *t)
{
    if(t != NULL) {
        print_post_order(t -> left_child);
        print_post_order(t -> right_child);
        cout << t -> data << " ";
    }
}


TreeNode *getBTree(const vector<int>& in_order_traversal, 
        const vector<int>& pre_order_traversal) {

    typedef vector<int>::size_type vec_sz;
    typedef vector<int>::const_iterator vec_iter;

    vec_sz pre_order_sz = pre_order_traversal.size();
    vec_sz in_order_sz = in_order_traversal.size();


    TreeNode *result = NULL;
    if(pre_order_sz != in_order_sz) throw domain_error("incorrect data!");
    if(pre_order_sz == 0) return result;

    int root_data = pre_order_traversal[0];
    result = new TreeNode(root_data);

    vec_iter in_order_root_ref = find(in_order_traversal.begin(),
            in_order_traversal.end(), root_data);

    vec_sz left_tree_size = in_order_root_ref - in_order_traversal.begin();
    bool left_subtree_exists = (left_tree_size != 0);
    bool right_subtree_exists = (in_order_root_ref + 1 != in_order_traversal.end());

    
    if(left_subtree_exists) {
        vector<int> in_order_left(in_order_traversal.begin(), 
                in_order_root_ref);

        vector<int> pre_order_left(pre_order_traversal.begin() + 1, 
                pre_order_traversal.begin() + left_tree_size + 1);

        (result -> left_child) = getBTree(in_order_left, pre_order_left);
    }

    if(right_subtree_exists) {
        vector<int> in_order_right(in_order_root_ref + 1,
                in_order_traversal.end());

        vector<int> pre_order_right(pre_order_traversal.begin() + left_tree_size + 1, 
                pre_order_traversal.end());

        (result -> right_child) = getBTree(in_order_right, pre_order_right);

    }

    return result;

}

void print_analysis(const int in_order[], const int pre_order[], const int expected_post_order[], size_t pre_order_size) {
    size_t in_order_size = pre_order_size;
    size_t expected_post_order_size = pre_order_size;
    vector<int> vec_pre_order(pre_order, pre_order + pre_order_size);
    vector<int> vec_in_order(in_order, in_order + in_order_size);

    TreeNode *root = getBTree(vec_in_order, vec_pre_order);
    cout << "got --> " << endl;
    print_post_order(root);
    cout << endl;
    cout << "expected -->" << endl;
    copy(expected_post_order, expected_post_order + expected_post_order_size,
            ostream_iterator<int>(cout, " "));
    cout << endl;
}
int main()
{


    string delim = string(20, '*') + '\n';
    int in_order1[] = {13, 16,21,33,42,64,84,93,148,153};
    int pre_order1[] = {42, 16, 13, 33, 21, 93, 64, 84, 153,148};
    int expected_post_order1[] = {13,21,33,16,84,64,148,153,93,52};
    size_t expected_post_order_size1 = sizeof(expected_post_order1) / sizeof(expected_post_order1[0]);

    int in_order2[] = {148, 153};
    int pre_order2[] = {153,148};
    int expected_post_order2[] = {148, 153};
    size_t expected_post_order_size2 = sizeof(expected_post_order2) / sizeof(expected_post_order2[0]);

    int in_order3[] = {64,84};
    int pre_order3[] = {64,84};
    int expected_post_order3[] = {84,64};
    size_t expected_post_order_size3 = sizeof(expected_post_order3) / sizeof(expected_post_order3[0]);

    int in_order4[] = {148};
    int pre_order4[] = {148};
    int expected_post_order4[] = {148};
    size_t expected_post_order_size4 = sizeof(expected_post_order4) / sizeof(expected_post_order4[0]);

    print_analysis(in_order1, pre_order1, expected_post_order1, expected_post_order_size1);
    cout << delim;
    print_analysis(in_order2, pre_order2, expected_post_order2, expected_post_order_size2);
    cout << delim;
    print_analysis(in_order3, pre_order3, expected_post_order3, expected_post_order_size3);
    cout << delim;
    print_analysis(in_order4, pre_order4, expected_post_order4, expected_post_order_size4);
    cout << delim;
}
