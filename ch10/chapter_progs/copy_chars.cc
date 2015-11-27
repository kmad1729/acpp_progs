#include <iostream>
#include <cstddef>
#include <string>
#include <algorithm>
#include <string.h>

using std::copy;
using std::cout;
using std::endl;
using std::string;

char *copy_chars(const char *s)
{
    size_t length = strlen(s) + 1;
    char *result =  new char[length];

    copy(s, s + length, result);
    return result;
}


int main()
{
    string s = "code forces no   signal service profiles ";
    cout << "input string = " << s << endl;

    char *copied_s = copy_chars(s.c_str());
    cout << "copied string = " << copied_s << endl;
}
