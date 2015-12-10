#include <iostream>
#include <vector>
#include <string>
#include <iterator>
#include <algorithm>

using std::cout;
using std::endl;

using std::vector;
using std::string;

using std::ostream_iterator;

using std::copy;

template <class T>
int rotated_arr_search(const vector<T>& arr, const T& target)
{
    typedef typename vector<T>::const_iterator vec_iter;

    vec_iter back_ptr = arr.begin();
    vec_iter front_ptr = back_ptr + 1;
    vec_iter rotation_point = back_ptr;

    while(front_ptr != arr.end()) {
        if(*front_ptr < *back_ptr) {
            rotation_point = front_ptr;
            break;
        }
        back_ptr = front_ptr++;
    }


    vec_iter beg_ptr;
    vec_iter end_ptr;
    if(target <= arr.end()[-1]) {
        beg_ptr = rotation_point;
        end_ptr = arr.end();
    } else {
        beg_ptr = arr.begin();
        end_ptr = rotation_point;
    }


    while(beg_ptr < end_ptr) {
        vec_iter mid = beg_ptr + (end_ptr - beg_ptr) / 2;
        if(target < *mid)
            end_ptr = mid;
        else if(target > *mid)
            beg_ptr = mid + 1;
        else {
            return mid - arr.begin();
        }
    }

    return -1;
}

void print_analysis(const vector<int>& v, const int target)
{
    cout << "vector --> " << endl;
    copy(v.begin(), v.end(), ostream_iterator<int>(cout, " "));
    cout << endl;
    cout << "found target " << target << " at " <<
        rotated_arr_search(v, target) << endl;
}

int main()
{
    int arr1[] = {5, 6, 23, 42, 42, -1, 0, 3};
    size_t arr1_sz = sizeof(arr1) / sizeof(arr1[0]);
    string delim = string(20, '*') + "\n";

    vector<int> v1(arr1, arr1 + arr1_sz);
    print_analysis(v1, 5);
    cout << delim;
    print_analysis(v1, 42);
    cout << delim;
    print_analysis(v1, 3);
    cout << delim;
    print_analysis(v1, -1);
    cout << delim;
    print_analysis(v1, 43);
    cout << delim;
    print_analysis(v1, -10);
    cout << delim;

    vector<int> v2(arr1, arr1 + 5);
    print_analysis(v2, 42);
    cout << delim;

    vector<int> v3(arr1 + 3, arr1 + 5);
    print_analysis(v3, 42);
    cout << delim;

    
}
