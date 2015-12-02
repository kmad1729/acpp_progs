//merging vector of vectors
//

#include <queue>
#include <vector>
#include <iostream>
#include <functional>
#include <utility>
#include <algorithm>
#include <iterator>

using std::priority_queue;
using std::vector;
using std::cout;
using std::endl;
using std::cin;
using std::greater;
using std::pair;
using std::copy;
using std::ostream_iterator;

typedef pair<int, int> int_pair;

class my_int_pair_comparison {
    public:
        bool operator() (const int_pair& lhs, const int_pair&rhs) {
            return lhs.first > rhs.first;
        }
};


vector<int> merge_vecs(vector<vector<int> >inp)
{
    vector<int> result;
    priority_queue<int_pair, vector<int_pair>, my_int_pair_comparison> 
                                                                staging_heap;

    int elem_counts[inp.size()];
    int elem_ptrs[inp.size()];

    //initializing the heap
    for(int i = 0; i < inp.size(); i++) {
        vector<int> curr_arr = inp[i];
        elem_counts[i] = curr_arr.size();
        elem_ptrs[i] = 0;
        if(elem_ptrs[i] < elem_counts[i])
            staging_heap.push(int_pair(
                        curr_arr[elem_ptrs[i]], i));
    }

    while(staging_heap.empty() == false) {
        int_pair curr_pair = staging_heap.top();
        staging_heap.pop();

        result.push_back(curr_pair.first);
        int arr_picked = curr_pair.second;
        elem_ptrs[arr_picked]++;
        if(elem_ptrs[arr_picked] < elem_counts[arr_picked])
            staging_heap.push(int_pair(
                    inp[arr_picked][elem_ptrs[arr_picked]], arr_picked));
    }
    return result;
}

int main()
{
    int arr0[] = {0, 1, 3, 6};
    int arr1[] = {-1, 2, 4, 7};
    int arr2[] = {6, 12, 63, 720};
    int arr3[] = {-2};
    int arr4[] = {3, 4};
    int arr5[] = {377, 1024, 3344};
    int arr6[] = {};

    vector<vector<int> > inp;
    inp.push_back(vector<int>(arr0, arr0 + (sizeof(arr0) / sizeof(arr0[0]))));
    inp.push_back(vector<int>(arr1, arr1 + (sizeof(arr1) / sizeof(arr1[0]))));
    inp.push_back(vector<int>(arr2, arr2 + (sizeof(arr2) / sizeof(arr2[0]))));
    inp.push_back(vector<int>(arr3, arr3 + (sizeof(arr3) / sizeof(arr3[0]))));
    inp.push_back(vector<int>(arr4, arr4 + (sizeof(arr4) / sizeof(arr4[0]))));
    inp.push_back(vector<int>(arr5, arr5 + (sizeof(arr5) / sizeof(arr5[0]))));
    inp.push_back(vector<int>(arr6, arr6 + (sizeof(arr6) / sizeof(arr6[0]))));

    vector<int> result = merge_vecs(inp);

    copy(result.begin(), result.end(), ostream_iterator<int>(cout, " "));
    cout << endl;


}
