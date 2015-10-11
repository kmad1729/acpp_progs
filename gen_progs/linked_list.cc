#include <iostream>
#include <string>

using std::cout;
using std::endl;
using std::string;

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
        int size_ll;

    public:
        int size() const {return size_ll;}
        LinkedList(): size_ll(0) { head = NULL; }

        void push(int data) {
            LL_Node **headRef = &head;

            LL_Node *new_node = new LL_Node(data);

            if (head == NULL) {
                *headRef = new_node;
            } else {
                (new_node -> next) = head;
                *headRef = new_node;
            }
            size_ll++;
        }

        void print() {
            LL_Node *curr_node = head;
            while(curr_node != NULL) {
                cout << ((curr_node) -> data) << " ";
                curr_node = (curr_node -> next);
            }
        }


        int length() {
            int result = 0;

            for(LL_Node *curr_node = head; curr_node != NULL;
                    curr_node = (curr_node -> next))
                result++;
            return result;
        }

};


int main()
{
    LinkedList ll;

    string delim = '\n' + string(20, '*') + '\n';

    cout << "size of ll before = " << ll.length() << endl;
    for(int i = 0; i < 10; i++) {
        ll.push(i + 1);
    }
    ll.print();
    cout << delim;

    cout << "size of ll before = " << ll.length() << endl;
    ll.push(10);
    ll.print();
    cout << delim;

    cout << "size of ll before = " << ll.length() << endl;
    ll.push(20);
    ll.print();
    cout << delim;

    cout << "size of ll before = " << ll.length() << endl;
    ll.push(40);
    ll.print();
    cout << delim;

    cout << "ll.length() = \t" << ll.length() << endl;
    cout << "size_ll = \t" << ll.size();
    cout << delim;
}
