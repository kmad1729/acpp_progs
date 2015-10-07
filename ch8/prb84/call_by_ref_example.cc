//program to check behaviour of iterators in function

#include <vector>
#include <iterator>
#include <iostream>
#include <string>
#include <iomanip>

using std::vector;
using std::ostream_iterator;
using std::cout;
using std::endl;
using std::string;


template <class ForwardIterator >
void double_vector(ForwardIterator first, ForwardIterator last)
{
    while(first != last)
        *first++ *= 2;
}

int main()
{
    vector<int> v;
    for(int i = 0; i < 20; i++) v.push_back(i);

    cout << "vector v --> " << endl;
    copy(v.begin(), v.end(), ostream_iterator<int>(cout, " "));
    cout << endl;

    double_vector(v.begin(), v.end());
    cout << "vector v after double --> " << endl;
    copy(v.begin(), v.end(), ostream_iterator<int>(cout, " "));
    cout << endl;
    return 0;
}


