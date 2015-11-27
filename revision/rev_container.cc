#include <algorithm>
#include <iostream>
#include <vector>
#include <iterator>

using std::swap;
using std::copy;
using std::cout;
using std::endl;
using std::vector;
using std::ostream_iterator;

template <class T>
void print_vec(const vector<T>& v)
{
    copy(v.begin(), v.end(), ostream_iterator<T>(cout, " "));
    cout << endl;
}

template <class Bi>
void my_reverse(Bi beg, Bi end)
{
    if(beg != end) {
        --end;
        while(beg < end) {
            swap(*beg++, *end);
            end--;
        }
    }
}

int main(int argc, char** argv)
{
    cout << "reversing the arguments -->" << endl;
    for(int i = 1; i < argc; i++) {
        cout << "reverse of " << argv[i] << " = ";
        my_reverse(argv[i], argv[i] + strlen(argv[i]));
        cout << argv[i] << endl;
    }
}
