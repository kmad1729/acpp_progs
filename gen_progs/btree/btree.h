#ifndef Guard_btree_h
#define Guard_btree_h

#include <cstdlib>
#include <climits>
#include <algorithm>
#include <stdexcept>
#include <iostream>
#include <iterator>
#include <vector>

struct Node {
    public:
        int data;
        Node* left;
        Node* right;

        Node(int d) {
            data = d;
            left = right = NULL;
        }
};

Node* new_node(int data)
{
    return new Node(data);
}

Node* build123()
{
    Node* result = new_node(2);
    (result -> left) = new_node(1);
    (result -> right) = new_node(3);
    return result;
}

//insert data into a given B.S.T node
Node* insert(Node *n, int data)
{
    if(n == NULL) {
        return new Node(data);
    } else {
        if (data <= (n -> data))
            (n -> left) = insert((n -> left), data);
        else
            (n -> right) = insert((n -> right), data);
        return n;
    }
}

//lookup data in a B.S.T node. Return true if found
bool lookup(Node* n, int target)
{
    if(n == NULL) return false;
    else {
        if((n -> data) == target)
            return true;
        else if (target < (n -> data))
            return lookup((n -> left), target);
        else
            return lookup((n -> right), target);
    }
}

//return the size of a binary tree. Return 0 if empty
int size(Node* n)
{
    if(n == NULL) return 0;
    else return (1 + size(n -> left) + size(n -> right));
}

//maxDepth number of nodes in the longest path from node down to the farthest leaf
int maxDepth(Node* n)
{
    if(n == NULL) return 0;
    else return 1 + std::max(maxDepth(n -> left), maxDepth(n -> right));
}

//minValue: return minimum value in a B.S.T from a NON-EMPTY tree 
int minValue(Node* n)
{
    if(n == NULL)
        throw std::domain_error("expecting a NON-EMPTY tree!");
    while( (n -> left) != NULL)
        n = (n -> left);
    return (n -> data);
}

//maxValue: return maximum value in a B.S.T from a NON-EMPTY tree
int maxValue(Node *n)
{
    if(n == NULL)
        throw std::domain_error("expecting a NON-EMPTY tree!");
    if((n -> right) != NULL)
        return maxValue((n -> right));
    else
        return (n -> data);
}

//printTree: print in-order traversal of a tree
void printTree(Node* n)
{
    if(n != NULL) {
        std::cout << (n -> data) << " ";
        printTree((n -> left));
        printTree((n -> right));
    }
}

//printPostOrder: print post-order traversal of the binary tree
void printPostOrder(Node *n)
{
    if(n != NULL) {
        printPostOrder((n -> left));
        printPostOrder((n -> right));
        std::cout << (n -> data) << " ";
    }
}

//hasPathSum: return true if a root-to-leaf path sum exists in the tree
bool hasPathSum(Node *n, int target_sum)
{
    if(n == NULL)
        return (target_sum == 0);
    else {
        int new_tgt_sum = target_sum - (n -> data);
        if ((n -> left) == NULL) {
            if((n -> right) == NULL) {
                //n is a leaf
                return (new_tgt_sum == 0);
            } else {
                //n has only right sub tree
                return hasPathSum((n -> right), new_tgt_sum);
            }
        } else {
            if((n -> right) == NULL) {
                // n has only left sub tree
                return hasPathSum((n -> left), new_tgt_sum);
            } else {
                //n has both sub trees
                return hasPathSum((n -> left), new_tgt_sum) ||
                    hasPathSum((n -> right), new_tgt_sum);
            }
        }
        return hasPathSum((n -> left), new_tgt_sum) ||
            hasPathSum((n -> right), new_tgt_sum);
    }
}

//printPathsRecur: helper function to keep track of all the nodes visited
void printPathsRecur(Node* n, int path[], int path_len)
{
    if(n == NULL) {
        std::cout << "path --> ";
        std::copy(path, path + path_len, 
                std::ostream_iterator<int>(std::cout, " "));
        std::cout << std::endl;
    } else {
        path[path_len++] = (n -> data);
        if((n -> left) == NULL) {
            if((n -> right) == NULL) {
                //encountered a leaf
                std::cout << "path --> ";
                std::copy(path, path + path_len, 
                        std::ostream_iterator<int>(std::cout, " "));
                std::cout << std::endl;
            } else {
                //only righ sub-tree exists
                printPathsRecur((n -> right), path, path_len);
            }
        } else {
            if((n -> right) == NULL) {
                //only left sub-tree exists
                printPathsRecur((n -> left), path, path_len);
            } else {
                //both sub-trees exist
                printPathsRecur((n -> right), path, path_len);
                printPathsRecur((n -> left), path, path_len);
            }
        }
    }
}

//printPaths: print all the root-to-leaf paths
void printPaths(Node* n)
{
    int max_array_size_needed = maxDepth(n);
    printPathsRecur(n, new int[max_array_size_needed], 0);
}

//mirror: change the tree so that the roles of left and right nodes are swapped
//          at every node
void mirror(Node* n)
{
    if(n != NULL) {
        Node* tmp = (n -> left);
        (n -> left) = (n -> right);
        (n -> right) = tmp;
        mirror((n -> left));
        mirror((n -> right));
    }
}

//double: change the tree so that each node has its duplicate node added as its 
//left child
void doubleTree(Node* n)
{
    if(n != NULL) {
        doubleTree((n -> left));
        doubleTree((n -> right));

        Node* tmpNode = new_node((n -> data));
        (tmpNode -> left) = (n -> left);
        (n -> left) = tmpNode;

    }
}

//copyTree: copy a tree to have same values at each node
Node* copyTree(Node* n)
{
    if(n != NULL) {
        Node *result = new_node((n -> data));
        (result -> left) = copyTree((n -> left));
        (result -> right) = copyTree((n -> right));
        return result;
    }
    return NULL;
}

//sameTree: return true if a and b are structurally same trees with same values
//  at each node
bool sameTree(Node* a, Node* b)
{
    if(a == NULL) return (b == NULL);
    if(b == NULL) return (a == NULL);
    if((a -> data) != (b -> data))
        return false;
    return sameTree((a -> left), (b -> left)) &&
        sameTree((a -> right), (b -> right));
}

//countTrees: get the number of unique BINARY SEARCH TREE 
//structures for a given number of elements.
int countTrees(int numElements)
{
    if(numElements <= 0)
        return 1;
    else {
        int result = 0;

        //counting the number of configurations with each element
        //as a root
        for(int root = 1; root <= numElements; root++) {
            int left = countTrees(root - 1);
            int right = countTrees(numElements - root);

            result += (left * right);
        }
        return result;
    }
}

//get_BTree: construct a binary tree using pre-order and in-order traversals
Node* get_BTree(const std::vector<int>& pre_order,
        const std::vector<int>& in_order)
{
    using std::vector;
    typedef vector<int>::size_type vec_sz;

    if (pre_order.size() != in_order.size()) {
        throw std::domain_error("input error. pre_order and in_order traversals don't have same sizes");
    }
    vec_sz sz = pre_order.size();
    if(sz != 0) {
        int root_data = pre_order[0];
        Node* root_node = new_node(root_data);
        vector<int>::const_iterator io_root_ref = 
            std::find(in_order.begin(), in_order.end(), root_data);

        vector<int> left_subtree_io(in_order.begin(), io_root_ref);
        vector<int> righ_subtree_io(io_root_ref + 1, in_order.end());

        vec_sz left_subtree_size = left_subtree_io.size();
        vector<int> left_subtree_pre_o(pre_order.begin() + 1,
                pre_order.begin() + 1 + left_subtree_size);
        vector<int> right_subtree_pre_o(pre_order.begin() + 1 + left_subtree_size,
                pre_order.end());

        (root_node -> left) = get_BTree(left_subtree_pre_o, left_subtree_io);
        (root_node -> right) = get_BTree(right_subtree_pre_o, righ_subtree_io);

        return root_node;
    } else {
        return NULL;
    }
}

//isBST_v1: return true if the given b tree is a B.S.T.
//makes use of maxValue and minValue functions
bool isBST_v1(Node *n)
{
    if(n == NULL)
        return true;
    else {
        if((n -> left) != NULL) {
            if(maxValue(n -> left) > (n -> data))
                return false;
        }
        if((n -> right) != NULL) {
            if(minValue(n -> right) <= (n -> data))
                return false;
        }

        return(isBST_v1(n -> left) && isBST_v1(n -> right));
    }
}

bool isBSTRecur(Node* n, int min, int max)
{
    if(n == NULL)
        return true;
    else {
        if( (n -> data) < min ||
                (n -> data) > max)
            return false;
        return isBSTRecur((n -> left), min, (n -> data)) &&
            isBSTRecur((n -> right), (n -> data) + 1, max);
    }
}

//isBST_v2: return true if the given b tree is a B.S.T
//makes use of helper isBSTRecur function
bool isBST_v2(Node* n)
{
    return isBSTRecur(n, INT_MIN, INT_MAX);
}

//maxPathUtil: utility function to fine maximum path sum
//res stores the maximum sum possible at a given node
//function returns the maximum sum passing through the given node
int maxPathUtil(Node* n, int& res)
{
    if(n == NULL)
        return 0;

    int l = maxPathUtil((n -> left), res);
    int r = maxPathUtil((n -> right), res);

    //get the maximum sum passing through the node
    int max_at_node = std::max(std::max(l, r) + (n -> data), (n -> data));

    //get the maximum sum for a path with current node at root
    int max_top = std::max(max_at_node, l + r + (n -> data));

    //store the above result
    res = std::max(res, max_top);

    //return the maximum sum passing through the node
    return max_at_node;
}

//maxPathSum: return the maximum sum for all the path in a binary tree
int maxPathSum(Node *n)
{
    int res = INT_MIN;
    maxPathUtil(n, res);
    return res;
}

#endif
