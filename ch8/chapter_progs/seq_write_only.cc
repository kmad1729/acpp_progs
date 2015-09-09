#include <iostream>
#include <string>
#include <vector>
#include <algorithm>

using std::cin;
using std::cout;
using std::endl;
using std::string;
using std::vector;

using std::copy;
using std::back_inserter;

void print_vector(const vector<int>& v)
{
    cout << "{";
    for(vector<int>::size_type i = 0; i < v.size(); i++) {
        if(i == 0) cout << v[i];
        else cout << ", " << v[i];
    }
    cout << "}" << endl;
}

template <class In, class Out>
Out my_copy(In beg, In end, Out dest)
{
    while(beg != end) {
        *dest++ = *beg++;
    }
    return dest;
}

//copy and paste the vector to itself
template <class T>
void mirror_vec(vector<T>& v)
{
    copy(v.begin(), v.end(), back_inserter(v));
}

template <class T>
void mirror_vec_with_my_copy(vector<T>& v)
{
    my_copy(v.begin(), v.end(), back_inserter(v));
}

int main()
{
    vector<int> v;
    for(int i = 0; i < 10; i++) v.push_back(i * 2);
    cout << "v -->" << endl;
    print_vector(v);
    cout << "after copy and paste same vector (stl copy)" << endl;
    mirror_vec(v);
    cout << "v -->" << endl;
    print_vector(v);
    cout << "after copy and paste same vector (my copy)" << endl;
    mirror_vec_with_my_copy(v);
    cout << "v -->" << endl;
    print_vector(v);
}
