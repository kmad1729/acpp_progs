#include "acpp_utils.h"
#include <iostream>
#include <vector>
#include <string>

using std::cout;
using std::endl;

using std::vector;

using std::string;

int main()
{
    string s = "   this is a real       bad string    \n\n no it is not! but it is  ";
    vector<string> v = split(s);
    for(vector<string>::const_iterator i = v.begin(); i != v.end(); i++) {
        cout << *i << endl;
    }
}
