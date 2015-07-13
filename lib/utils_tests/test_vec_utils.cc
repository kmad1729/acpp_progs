#include "acpp_utils.h"
#include <iostream>
#include <string>
#include <vector>

using std::vector;
using std::string;
using std::cout;

int main()
{
    vector<double> vec_i;
    for(int i = 0; i < 20; i++) vec_i.push_back(i << 1);
    print_vec(vec_i);
    vector<string> v = split("ab cd ef gh");
    cout << v[0];
    print_vec(v);
}

