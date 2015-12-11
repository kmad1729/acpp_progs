#include <iostream>
#include <string>
#include <vector>
#include <iterator>
#include <algorithm>

using std::cout;
using std::endl;

using std::string;

using std::vector;

using std::ostream_iterator;
using std::copy;

class BTreeNode {
    public:
        int data;
        BTreeNode *right;
        BTreeNode *left;

        BTreeNode(int d) {
            data = d;
            right = 0;
            left = 0;
        }

};

void print_pre_order(BTreeNode * n)
{
    if(n != 0) {
        cout << (n -> data) << " ";
        print_pre_order(n -> left);
        print_pre_order(n -> right);
    }
}


BTreeNode *get_min_ht_tree(const vector<int>& sorted_arr) {
    typedef vector<int>::size_type vec_sz;

    BTreeNode *result = 0;
    if(sorted_arr.size() > 0) {
        vec_sz middle = sorted_arr.size();
        result = new BTreeNode(sorted_arr[middle]);
        (result -> right) = get_min_ht_tree(vector<int>(
                    sorted_arr.begin() + middle + 1,
                    sorted_arr.end()));
        (result -> left) = get_min_ht_tree(vector<int>(
                    sorted_arr.begin(), 
                    sorted_arr.begin() + middle));
    }
    return result;
}

int main()
{
    int test_data[] = {-5,-3,-1,0,1,5,6,13,26,48,66};
    size_t test_data_len = sizeof(test_data) / sizeof(test_data[0]);

    string delim = string(20, '*') + "\n";
    vector<int> test_arr(test_data, test_data + test_data_len);
    BTreeNode *tr = get_min_ht_tree(test_arr);

    print_pre_order(tr);
    cout << delim << endl;
}
