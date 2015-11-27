//Rewrite the median function so that we can call it with either
//a vector or a built-in array. The function should allow containers
//of any arithmetic type
//

#include <iostream>
#include <vector>
#include <cstddef>
#include <stdexcept>
#include <algorithm>
#include <iterator>
#define ARR_SIZE 20

using std::vector;
using std::cout;
using std::endl;
using std::sort;
using std::ostream_iterator;
using std::domain_error;

//function to find the median of a container
template <class T>
T median(T* beg, size_t inp_size)
{
    if (inp_size == 0)
        throw domain_error("median of an empty container cannot be found!");

    vector<T> temp(beg, beg + inp_size);
    size_t mid = inp_size / 2;
    sort(temp.begin(), temp.end());
    return inp_size % 2 == 0 ? (temp[mid - 1] + temp[mid]) / 2 : temp[mid];
}

template<class T>
void print_container(T* beg, size_t inp_size)
{
    copy(beg, beg + inp_size, ostream_iterator<T>(cout, " "));
    cout << endl;
}

int main()
{
    int nums_arr[ARR_SIZE];
    vector<int> nums_vec;

    int elem;
    for(int i = 0; i < ARR_SIZE; i++) {
        if (i < ARR_SIZE / 2) elem = i * 2;
        else elem = i - 1;
        nums_arr[i] = elem;
        nums_vec.push_back(elem);
    }

    cout << "nums_vec --> " << endl;
    print_container(&nums_vec[0], nums_vec.size());
    cout << "nums_arr --> " << endl;
    print_container(nums_arr, ARR_SIZE);

    cout << "median of vector = " << median(&nums_vec[0], nums_vec.size()) << endl;
    cout << "median of arr = " << median(nums_arr, ARR_SIZE) << endl;

}
