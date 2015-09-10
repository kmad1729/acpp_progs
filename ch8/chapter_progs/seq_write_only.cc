#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#define DELIM_SIZE 20

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
    //dest supports '*dest =' and 'dest++' operators
    // iterators that support these operators are 'output iterators'
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
    string delim(DELIM_SIZE, '*');
    delim += '\n';
    for(int i = 0; i < 10; i++) v.push_back(i * 2);

    cout << "v -->" << endl;
    print_vector(v);
    cout << delim;

    cout << "after copy and paste same vector (stl copy)" << endl;
    mirror_vec(v);
    cout << "v -->" << endl;
    print_vector(v);
    cout << delim;
    cout << "after copy and paste same vector (my copy)" << endl;
    mirror_vec_with_my_copy(v);
    cout << "v -->" << endl;
    print_vector(v);
    cout << delim;

    //if we copy using v.begin() iterator without sufficient space, we get 
    //seg fault
    cout << "copy one vector to another with sufficient space" << endl;
    vector<int> v1(v.size()) ;
    copy(v.begin(), v.end(), v1.begin());
    cout << "v1 --> " << endl;
    print_vector(v1);
    cout << delim;

    //the extra space will have zeros
    cout << "copy one vector to another with extra space" << endl;
    vector<int> v2(v.size() * 2) ;
    copy(v.begin(), v.end(), v2.begin());
    cout << "v2 --> " << endl;
    print_vector(v2);
    cout << delim;

    //copy on arrays with sufficient space
    int arr1[v.size()];
    copy(v.begin(), v.end(), arr1);
    cout << "arr1 --> " << endl;
    cout << "{";
    for(vector<int>::size_type i = 0; i < v.size(); i++) {
        if (i == 0) cout << arr1[i];
        else cout << ", " << arr1[i];
    }
    cout << "}" << endl;
    cout << delim;


}
