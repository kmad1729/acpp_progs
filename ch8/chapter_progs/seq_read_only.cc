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


void print_vector(const vector<int>& v)
{
    cout << "{";
    for(vector<int>::size_type i = 0; i < v.size(); i++) {
        if(i == 0) cout << v[i];
        else cout << ", " << v[i];
    }
    cout << "}" << endl;
}


int main()
{
    vector<int> v;
    for(int i = 0; i < 10; i++) v.push_back(i * 2);
    cout << "v -->" << endl;
    print_vector(v);
}
