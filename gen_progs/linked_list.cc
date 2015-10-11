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
                //*headRef = new_node;
                head = new_node;
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

        void append_node(int data) {

            LL_Node *last_node = head;

            LL_Node *new_node = new LL_Node(data);

            if(last_node == NULL)
                head = new_node;
            else {
                while((last_node -> next) != NULL) {
                    last_node = (last_node -> next);
                }

                (last_node -> next) = new_node;
            }

        }

};


int main()
{
    LinkedList ll;

    string delim = '\n' + string(20, '*') + '\n';
    
    /*
    int new_node_append = 43;
    cout << "appending node " << new_node_append << endl;
    ll.append_node(new_node_append);
    ll.print();
    cout << delim;

    new_node_append = 45;
    cout << "appending node " << new_node_append << endl;
    ll.append_node(new_node_append);
    ll.print();
    */

    cout << delim;
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

    int node_to_append = 42;
    cout << "list before --> " << endl;
    ll.print();
    cout << endl << "appending node " << node_to_append << endl;
    ll.append_node(node_to_append);
    cout << "list after --> " << endl;
    ll.print();

    cout << delim;

    node_to_append = 54;
    cout << "list before --> " << endl;
    ll.print();
    cout << endl << "appending node " << node_to_append << endl;
    ll.append_node(node_to_append);
    cout << "list after --> " << endl;
    ll.print();
    cout << delim;
}
