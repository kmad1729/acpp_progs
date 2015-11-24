#include <iostream>
#include <string>

using std::cout;
using std::endl;
using std::string;

class LL_Node {
    public:
        int data;
        LL_Node *next;
        LL_Node(int d) {
            data = d;
            next = NULL;
        }
};


class LinkedList {
    private:
        LL_Node *head;
        int size_ll; 
    public:
        LinkedList(): size_ll(0) {
            head = NULL;
        }

        void push(int data) {
            LL_Node *new_node = new LL_Node(data);
            if(head == NULL)
                head = new_node;
            else {
                (new_node -> next) = head;
                head = new_node;
            }
            size_ll++;
        }

        void print() {
            LL_Node *curr_node = head;
            while(curr_node != NULL) {
                cout << (curr_node -> data) << " ";
                curr_node = (curr_node -> next);
            }
            cout << endl;
        }
};


int main()
{
    LinkedList l;
    cout << "printing the linked list" << endl;
    l.print();

    cout << "printing the linked list" << endl;
    l.push(1);
    l.push(32);
    l.push(54);
    l.push(-23);
    l.print();
    l.push(3423);
    l.print();
}
