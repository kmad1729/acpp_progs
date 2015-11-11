//arrays can be initilized with the following syntax (using "{" "}")
//standard-library containers cannot be initilized using this method
//array can be of any type, even vectors, strings. No need of only built-in types

#include <iostream>
#include <cstddef>
#include <iterator>
#include <algorithm>
#include <string>
#include <vector>

using std::cout;
using std::endl;
using std::ostream_iterator;
using std::copy;
using std::string;
using std::vector;

template <class For>
void print_vector(For b, For e)
{
    while(b != e) {
        cout << *b << " ";
        b++;
    }
    cout << endl;
}

int main()
{
    string delim = string(20, '*') + '\n';
    const int month_lengths[] = {
        31, 28, 31, 30, 31, 30,
        31, 31, 30, 31, 30, 31
    };

    const string months[] = {
        "January", "February", "March", "April", "May", "June",
        "July", "August", "September", "October", "November", "December"
    };

    size_t month_count = sizeof(month_lengths) / sizeof(month_lengths[0]);

    for(size_t i = 0; i < month_count; i++) {
        cout << months[i] << " has " << month_lengths[i] << " days." << endl;
    }
    cout << delim;

    vector<int> v1;
    v1.push_back(2);
    v1.push_back(4);
    vector<int> v2(month_lengths, month_lengths + month_count);
    vector<int> v3;
    for(int i = 0; i < 20; i++) v3.push_back(i);
    vector<int> v4(20, 20);

    const vector<int> vector_arr[] = {
        v1, v2, v3, v4
    };
    for(int i = 0; i < 4; i++) {
        print_vector(vector_arr[i].begin(), vector_arr[i].end());
    }
    cout << delim;


}
