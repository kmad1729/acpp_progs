#include <algorithm>
#include <iostream>
#include <vector>
#include <iterator>
#include <string>

using std::cin;
using std::cout;
using std::endl;
using std::swap;
using std::vector;
using std::ostream_iterator;
using std::string;
using std::copy;

template <class Ran>
Ran partition(Ran start, Ran last)
{
    Ran i = start;
    Ran j = start;
    Ran pivot = last - 1;
    while(i < last - 1) {
        if(*i < *pivot) {
            swap(*i, *j);
            j++;
        }
        i++;
    }

    swap(*pivot, *j);
    return j + 1;
}

template <class Ran>
void quick_sort(Ran b, Ran e)
{
    if(e - b > 1) {
        Ran p = partition(b, e);
        quick_sort(b, p - 1);
        quick_sort(p, e);
    }
}

int main()
{
    int inp_arr[] = {-1, -23, 4, 34, -34, 84, 100, 3, 0, 2, 5, 34, 83, 32, 4, 1};
    size_t arr_size = sizeof(inp_arr) / sizeof(inp_arr[0]);
    string delim(20,'*');
    cout << "inp_arr --> " << endl;
    copy(inp_arr, inp_arr + arr_size, ostream_iterator<int>(cout, " "));
    cout << endl;

    quick_sort(inp_arr, inp_arr + arr_size);
    cout << "after sort --> " << endl;
    copy(inp_arr, inp_arr + arr_size, ostream_iterator<int>(cout, " "));
    cout << endl;
    cout << delim << endl;

    vector<int> v;
    v.push_back(42);
    cout << "inp vector --> " << endl;
    copy(inp_arr, inp_arr + arr_size, ostream_iterator<int>(cout, " "));
    cout << endl;

    quick_sort(inp_arr, inp_arr + arr_size);
    cout << "after sort --> " << endl;
    copy(inp_arr, inp_arr + arr_size, ostream_iterator<int>(cout, " "));
    cout << endl;
    cout << delim << endl;
}
