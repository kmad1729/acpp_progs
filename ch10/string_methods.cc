#include <string>
#include <cstring>
#include <cstddef>
#include <cstdlib>
#include <iostream>

using std::string;
using std::strlen;
using std::cout;
using std::endl;

size_t strlen(char *s)
{
    size_t sz = 0;
    while(*s++ != '\0')
        sz++;
    return sz;
}

int main()
{
    //initialize string literal in different ways
    
    //as an array of chars
    const char s1[] = {'H', 'e', 'l', 'l', 'o', '\0'};
    //as string literal
    char s2[] = "Hello";

    size_t string_size = sizeof(s1) / sizeof(s1[0]);
    cout << "size of s1 (" << string(s1) << ") = " << strlen(s1) << endl;

    cout << "size of s2 (" << string(s2, s2 + string_size) << ") = " 
        << strlen(s2) << endl;

}
