#include <iostream>
#include <vector>
#include <stdexcept>
#include <algorithm>
#include <numeric>

using std::cout;
using std::endl;
using std::vector;
using std::domain_error;
using std::sort;
using std::string;
using std::accumulate;

template <class T>
T my_median(vector<T> v)
{
    typedef typename vector<T>::size_type v_sz;
    v_sz size = v.size();
    if(size == 0)
        throw domain_error("median of an empty vector!!");

    v_sz mid = size / 2;
    sort(v.begin(), v.end());

    return size % 2 == 0? (v[mid] + v[mid - 1]) / 2: v[mid];
}


template <class T>
void print_helper(vector<T> v)
{
    cout << "{";
    for(typename vector<T>::size_type i = 0; i < v.size(); i++) {
        if(i == 0)
            cout << v[i];
        else
            cout << ", " << v[i];
    }
    cout << "}";
    cout << endl;
}

template <class T>
T average(vector<T> v)
{
    if(v.size() == 0)
        throw domain_error("average of empty vector");
    T init = 0.0;
    return accumulate(v.begin(), v.end(), init) / v.size();
}

int main()
{
    vector<int> v1;
    vector<int> v2;
    vector<int> v3;
    vector<double> v4;

    for(int i = 1; i < 101; i++) {
        v1.push_back(i);
        v2.push_back(i * 2);
        v3.push_back(i * 3);
        v4.push_back(0.5 * i);
    }

    for(int i = 10; i > 0; i--) {
        v1.push_back(i);
        v2.push_back(i * 2);
        v3.push_back(i * 3);
        v4.push_back(0.5 * i);
    }
    cout << "vector --> ";
    print_helper(v1);
    cout << "median --> " << my_median(v1) << endl;
    cout << "average --> " << average(v1) << endl;
    cout << endl << string(50, '*') << endl;

    cout << "vector --> ";
    print_helper(v2);
    cout << "median --> " << my_median(v2) << endl;
    cout << "average --> " << average(v2) << endl;
    cout << endl << string(50, '*') << endl;

    cout << "vector --> ";
    print_helper(v3);
    cout << "median --> " << my_median(v3) << endl;
    cout << "average --> " << average(v3) << endl;
    cout << endl << string(50, '*') << endl;

    cout << "vector --> ";
    print_helper(v4);
    cout << "median --> " << my_median(v4) << endl;
    cout << "average --> " << average(v4) << endl;
    cout << endl << string(50, '*') << endl;
}
