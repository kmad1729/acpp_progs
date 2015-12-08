//question: given pre-order and in-order traversal vectors
//reconstruct the binary tree. Assume no repeating values.

#include <iostream>
#include <vector>
#include <string>
#include <algorithm>

using std::cout;
using std::endl;
using std::vector;
using std::string;

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

int get_pos(const vector<int>& v, int target) {
    vector<int>::const_iterator found_at = find(v.begin(), v.end(), target);
    int result = found_at - v.begin();
    result =  (result >= v.size())? -1: result;
    return result;
}

TreeNode *getBTree(const vector<int>& pre_order_traversal, 
        const vector<int>& in_order_traversal) {

    typedef vector<int>::size_type vec_sz;
    vec_sz pre_order_sz = pre_order_traversal.size();
    vec_sz in_order_sz = in_order_traversal.size();


    TreeNode *result = NULL;
    if(pre_order_sz > 0 && in_order_sz > 0) {
        int root_data = pre_order_traversal[0];
        result = new TreeNode(root_data);
        cout << "root_data = " << root_data << endl;
        cout << "pre_order_sz = " << pre_order_sz << endl;;

        if(pre_order_sz != 1) {
            vec_sz root_in_order_ind = get_pos(in_order_traversal, root_data);

            int right_most_left_sub_tree_pre_order_ind =
                get_pos(pre_order_traversal, 
                        in_order_traversal[root_in_order_ind - 1]);

            int left_most_left_sub_tree_pre_order_ind =
                get_pos(pre_order_traversal, 
                        in_order_traversal[0]);

            
            if(left_most_left_sub_tree_pre_order_ind >= 0) {
                (result -> left_child) = getBTree(
                        vector<int>(
                            pre_order_traversal.begin() + 1,
                            pre_order_traversal.begin() + 1 + left_most_left_sub_tree_pre_order_ind),
                        vector<int>(
                            in_order_traversal.begin(), 
                            in_order_traversal.begin() + root_in_order_ind));
            }

            if(right_most_left_sub_tree_pre_order_ind >= 0) {
                (result -> right_child) = getBTree(
                        vector<int>(
                            pre_order_traversal.begin() + right_most_left_sub_tree_pre_order_ind + 1,
                            pre_order_traversal.end()),
                        vector<int>(
                            in_order_traversal.begin() + root_in_order_ind + 1,
                            in_order_traversal.end()));
            }
        }

    }
    return result;

}
int main()
{
    //int pre_order[] = {23, 5, 3, -1, 19, 89, 64, 35, 112, 93};
    //int pre_order[] = {23, 5, 3};
    int pre_order[] = {3, 5, 23};

    //int in_order[] = {-1, 3, 5, 19, 23, 35, 64, 89, 93, 112};
    //int in_order[] = {3, 5, 23};
    int in_order[] = {3, 5, 23};

    size_t pre_order_size = sizeof(pre_order) / sizeof(pre_order[0]);
    size_t in_order_size = sizeof(in_order) / sizeof(in_order[0]);
    vector<int> vec_pre_order(pre_order, pre_order + pre_order_size);
    vector<int> vec_in_order(in_order, in_order + in_order_size);

    TreeNode *root = getBTree(vec_pre_order, vec_in_order);
    print_post_order(root);
    cout << endl;
}
