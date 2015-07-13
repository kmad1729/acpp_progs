#include "acpp_utils.h"
#include <iostream>
#include <vector>
#include <string>
#include <algorithm>

using std::cout;
using std::endl;

using std::vector;

using std::string;

using std::sort;

int main()
{
    string s = "   this is a real       bad string    \n\n no it is not! but it is  ";
    vector<string> v = split(s);
    sort(v.begin(), v.end());
    print_vec(v);
}
