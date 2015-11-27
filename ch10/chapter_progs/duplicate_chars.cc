//program to demo creating an array of objects

#include <iostream>
#include <algorithm>
#include <cstring>
#include <cstddef>

using std::cout;
using std::endl;
using std::copy;

char* duplicate_chars(const char *p)
{
    size_t length = strlen(p) + 1;
    char *result = new char[length];
    copy(p, p + length, result);
    return result;
}


int main()
{
    char initial_string[] = "cpp is awesome";
    cout << "initial_string = " << initial_string << endl;
    char *duplicate_string = duplicate_chars(initial_string);
    cout << "duplicate_string = " << duplicate_string << endl;

    cout << "addr of initial_string = " << (void *) initial_string << endl;
    cout << "addr of duplicate_string = " << (void *) duplicate_string << endl;


}
