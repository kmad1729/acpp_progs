#include <iostream>
#include <stack>
#include <iterator>
#include <string>
#include <algorithm>
#include <stdexcept>

using std::cout;
using std::endl;

using std::stack;

using std::ostream_iterator;
using std::string;

using std::copy;
using std::logic_error;

template <class T>
class MyQueue {
    private:
        stack<T> s1;
        stack<T> s2;

    public:
        void enqueue(const T& data) {
            s1.push(data);
        }

        bool empty() const {
            return (s1.empty() && s2.empty());
        }

        T& dequeue() {
            if(empty()) {throw logic_error("cannot deque empty queue");}
            if(s2.empty()) {
                while(!s1.empty()) {
                    T& top_s1 = s1.top();
                    s1.pop();
                    s2.push(top_s1);
                }
            }
            T& result = s2.top();
            s2.pop();
            return result;
        }
};

int main()
{
    MyQueue<string> test_queue;
    string names[] = {"peter", "clark", "bruce", "thor", "tony", "kent", "lois"};
    size_t name_count = sizeof(names) / sizeof(names[0]);

    int curr_index = 0;

    cout << "enqueueing " << names[curr_index] << endl;
    test_queue.enqueue(names[curr_index++]);

    cout << "enqueueing " << names[curr_index] << endl;
    test_queue.enqueue(names[curr_index++]);

    cout << "enqueueing " << names[curr_index] << endl;
    test_queue.enqueue(names[curr_index++]);

    cout << "enqueueing " << names[curr_index] << endl;
    test_queue.enqueue(names[curr_index++]);

    cout << "DEQUEUED " << test_queue.dequeue() << endl;
    cout << "DEQUEUED " << test_queue.dequeue() << endl;
    cout << "DEQUEUED " << test_queue.dequeue() << endl;

    cout << "enqueueing " << names[curr_index] << endl;
    test_queue.enqueue(names[curr_index++]);

    while(curr_index < name_count) {
        cout << "enqueueing " << names[curr_index] << endl;
        test_queue.enqueue(names[curr_index++]);
    }

    while(!test_queue.empty()) {
        cout << "DEQUEUED " << test_queue.dequeue() << endl;
    }

}
