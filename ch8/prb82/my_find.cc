#include <iostream>
#include <algorithm>
#include <string>
#include <vector>

using std::vector;
using std::string;
using std::cout;
using std::endl;

template <class In, class Elem>
In my_find(In b, In e, Elem x)
{
    while(b != e) {
        if(*b++ == x)
            return b;
    }
    return b;
}

int main()
{
    vector<string> v;
    v.push_back("metallica");
    v.push_back("coldplay");
    v.push_back("imagine_dragons");
    v.push_back("pink_floyd");
    v.push_back("beatles");

    vector<string> test_str;
    test_str.push_back("jal");
    test_str.push_back("metallica");
    test_str.push_back("pritam");

    for(vector<string>::size_type i = 0; i < test_str.size(); i++) {
        cout << "is " << test_str[i] << " in list of band? ";
        if(my_find(v.begin(), v.end(), test_str[i]) != v.end()) {
            cout << "yes";
        } else {
            cout << "no";
        }
        cout << endl;
    }
}
