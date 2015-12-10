#include <iostream>
#include <stack>
#include <vector>
#include <iterator>
#include <algorithm>
#include <string>

using std::cout;
using std::endl;
using std::stack;
using std::vector;
using std::ostream_iterator;
using std::copy;
using std::string;

bool path_exists(vector<vector<int> > graph, int start_node, int end_node)
{
    stack<int> s;
    s.push(start_node);
    vector<bool> visited(graph.size(), false);

    while(s.empty() == false) {
        int curr_node = s.top();
        s.pop();
        if(curr_node == end_node)
            return true;
        if(visited[curr_node]) continue;
        visited[curr_node] = true;

        for(int i = 0; i < graph.size(); i++) {
            if(graph[curr_node][i] != -1) {
                if(!visited[i]) s.push(i);
            }
        }
    }
    return false;
}

int main()
{
    int graph_dim = 9;
    vector<vector<int> > test_graph;
    for(int i = 0; i < graph_dim; i++) {
        vector<int> tmp_vec(graph_dim, -1);
        test_graph.push_back(vector<int>(graph_dim, -1));
    }

    int rows_with_ones[] = {0, 0, 0,    1, 1,   2,  3,3,3,  5,    6,  7,  8};
    int cols_with_ones[] = {2, 3, 5,    0, 5,   7,  5,7,8,  8,    1,  0,  0};
    cout << "hahah" << endl;
    int row_sz = sizeof(rows_with_ones) / sizeof(rows_with_ones[0]);
    for(int i = 0; i < row_sz; i++) {
        test_graph[rows_with_ones[i]][cols_with_ones[i]] = 1;
    }

    string delim = string(20, '*') + "\n";
    for(int r = 0; r < graph_dim; r++) {
        for(int c = 0; c < graph_dim; c++){
            cout << test_graph[r][c] << " ";
        }
        cout << endl;
    }
    cout << delim;

    int t1 = 0;
    int t2 = 8;
    cout << "path between " << t1 << " and " << t1 << " exists? " <<
        path_exists(test_graph, t1, t1) << endl;;
    cout << delim;
    cout << "path between " << t1 << " and " << t2 << " exists? " <<
        path_exists(test_graph, t1, t2) << endl;;
    cout << delim;

    t1 = 1;
    t2 = 6;
    cout << "path between " << t1 << " and " << t2 << " exists? " <<
        path_exists(test_graph, t1, t2) << endl;;
    cout << delim;

}
