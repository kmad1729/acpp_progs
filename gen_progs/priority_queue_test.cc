#include <iostream>
#include <queue>
#include <utility>
#include <vector>

using std::cin;
using std::cout;
using std::priority_queue;
using std::pair;
using std::endl;
using std::greater;
using std::vector;

int main()
{
    typedef pair<int, int> int_pair;
    priority_queue<int_pair, vector<int_pair>, greater<int_pair> >pq;
    pq.push(pair<int, int>(5, 10));
    pq.push(pair<int, int>(5, 10));
    pq.push(pair<int, int>(1, 2));
    pq.push(pair<int, int>(2, 4));
    pq.push(pair<int, int>(10, 20));

    while(!pq.empty()) {
        pair<int, int> curr_pair = pq.top();
        cout << "curr pair first = " << curr_pair.first <<
            " second = " << curr_pair.second << endl;
        pq.pop();
    }
}
