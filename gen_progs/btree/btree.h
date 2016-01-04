#ifndef Guard_btree_h
#define Guard_btree_h

#include <cstdlib>

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


#endif
