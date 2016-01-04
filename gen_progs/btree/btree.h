#ifndef Guard_btree_h
#define Guard_btree_h

#include <cstdlib>
#include <algorithm>
#include <stdexcept>
#include <iostream>

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
#endif
