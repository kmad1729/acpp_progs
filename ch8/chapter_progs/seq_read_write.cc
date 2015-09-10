//program to demonstrate sequential read-write operations using replace function
// the program replaces string spaces with '#'
//

#include <iostream>
#include <string>
#include <algorithm>
#define DELIM 20


using std::cout;
using std::endl;

using std::string;
using std::replace;


template <class For, class X>
void my_replace(For beg, For end, const X& x, const X& y)
{
    while(beg != end) {
        if(*beg == x) 
            *beg = y;
        beg++;
    }
}

void str_space_replace(string& s)
{
    replace(s.begin(), s.end(), ' ', '#');
}

void str_space_my_replace(string& s)
{
    my_replace(s.begin(), s.end(), ' ', '#');
}

int main()
{
    string delim = string(DELIM, '*') + '\n';
    string inp_str = "this is a    string     with   many    spaces     ";

    cout << "input string  -->" << endl;
    cout << "(" << inp_str << ")" << endl;
    cout << delim;

    cout << "after space replace --> " << endl;
    str_space_replace(inp_str);
    cout << "(" << inp_str << ")" << endl;
    cout << delim;

    inp_str = "this is a    string     with   many    spaces       ";

    cout << "input string  -->" << endl;
    cout << "(" << inp_str << ")" << endl;
    cout << delim;

    cout << "after space my replace --> " << endl;
    str_space_my_replace(inp_str);
    cout << "(" << inp_str << ")" << endl;
    cout << delim;
}
