#include <iostream>
#include <iterator>
#include <vector>
#include <string>
#include <algorithm>

using std::cout;
using std::endl;
using std::ostream_iterator;
using std::vector;
using std::string;
using std::swap;
using std::reverse;
using std::copy;
//implement the swap function used in reverse function
//

//implementation of reverse function from stl
template <class Bi>
void my_reverse(Bi first, Bi last)
{
    while(first != last) {
        --last;
        if(first != last)
            swap(*first++, *last);
    }
}


//rotate a vector at point i
//e.g rotate 1,2,3,4,5,6 
//at 0 gives 1,2,3,4,5,6
//at 1 gives 2,3,4,5,6,1
//at 2 gives 3,4,5,6,1,2
//at 3 gives 4,5,6,1,2,3
//at 5 gives 6,1,2,3,4,5
//at 6 gives 1,2,3,4,5,6
//at 8 gives 1,2,3,4,5,6
template <class T>
void rotate_vector(vector<T>& v, int i)
{
    if( i > 0 && i < v.size()) {
        reverse(v.begin(), v.begin() + i);
        reverse(v.begin() + i, v.end());
        reverse(v.begin(), v.end());
    }
}

int main()
{
    vector<int> v;
    for(int i = 1; i < 9; i++) v.push_back(i);
    string delim = '\n' + string(20, '*') + '\n';
    cout << "vector -->" << endl;
    copy(v.begin(), v.end(), ostream_iterator<int>(cout, " "));
    cout << delim;


    for(int j = 0; j < 10; j++) {
        vector<int> v1(v.begin(), v.end());
        cout << "vector rotated at " << j << " --> " << endl;
        rotate_vector(v1, j);
        copy(v1.begin(), v1.end(), ostream_iterator<int>(cout, " "));

        cout << delim;
    }
}
