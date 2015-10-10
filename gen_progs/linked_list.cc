#include <iostream>

using std::cout;
using std::endl;

struct LL_Node {
    int data;
    struct LL_Node* next;

    LL_Node() {next = NULL;}

    LL_Node(int d) {
        data = d;
        next = NULL;
    }

};

class LinkedList {
    private:
        LL_Node *head;

    public:
        LinkedList() { head = NULL; }

        void push(int data) {
            LL_Node **headRef = &head;

            LL_Node *new_node = new LL_Node(data);

            if (head == NULL) {
                *headRef = new_node;
            } else {
                (new_node -> next) = head;
                *headRef = new_node;
            }
        }

        void print() {
            LL_Node *curr_node = head;
            while(curr_node != NULL) {
                cout << ((curr_node) -> data) << " ";
                curr_node = (curr_node -> next);
            }
        }
};


int main()
{
    LinkedList ll;
    for(int i = 0; i < 10; i++) {
        ll.push(i + 1);
    }
    ll.push(10);
    ll.print();
    cout << endl;
    ll.push(20);
    ll.print();
    cout << endl;
    ll.push(40);
    ll.print();
    cout << endl;
}
