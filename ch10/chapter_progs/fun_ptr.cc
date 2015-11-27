#include <iostream>
#include <cstddef>
#include <algorithm>
#include <vector>

using std::cout;
using std::vector;
using std::find_if;
using std::endl;


template <class In, class Pred>
In my_find_if(In begin, In end, Pred f)
{
    while(begin != end && !f(*begin)) {
        ++begin;
    }
    return begin;
}

bool is_negative(int i)
{
    return i < 0;
}


template <class In, class Tgt>
In my_find(In begin, In end, Tgt t)
{
    while(begin != end && *begin != t) {
        ++begin;
    }
    return begin;
}

void print_vec(const vector<int>& v)
{
    cout << "[";
    for(vector<int>::const_iterator i = v.begin(); i != v.end(); i++) {
        if(i == v.begin()) cout << *i;
        else cout << ", " << *i;
    }
    cout << "]" << endl;
}

int main()
{
    int a[] = {0,12,4,3,4, 32, -1, 3, 2};

    size_t arr_len = sizeof(a) / sizeof(a[0]);

    cout << "Size of the array = " << arr_len << endl;
    vector<int> v(a, a + arr_len);
    print_vec(v);

    vector<int>::const_iterator i = find_if(v.begin(), v.end(), is_negative);
    vector<int>::const_iterator j = my_find_if(v.begin(), v.end(), is_negative);

    cout << "stl First negative found at index -- " << i - v.begin() << endl;
    cout << "myl First negative found at index -- " << j - v.begin() << endl;
    
    int target = 332;

    vector<int>::const_iterator k1 = find(v.begin(), v.end(), target);
    vector<int>::const_iterator k2 = my_find(v.begin(), v.end(), target);
    cout << target << " found(stl) at index -- " << k1 - v.begin() << endl;
    cout << target << " found(myl) at index -- " << k2 - v.begin() << endl;

}
