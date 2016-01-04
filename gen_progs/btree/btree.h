#ifndef Guard_btree_h
#define Guard_btree_h

#include <cstdlib>
#include <algorithm>
#include <stdexcept>
#include <iostream>
#include <iterator>

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

#endif
