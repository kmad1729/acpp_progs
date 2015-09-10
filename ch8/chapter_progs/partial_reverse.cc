//program to demonstrate bidirectional iterators using library reverse function
//only paritally revesing from half of the string

#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#define DELIM 20

using std::cout;
using std::endl;

using std::string;
using std::vector;
using std::reverse;
using std::swap;


template <class Bi>
void my_reverse(Bi beg, Bi end)
{
    while(beg < end) {
        --end;
        swap(*beg++, *end);
    }
}

int main()
{
    vector<string> inp;
    inp.push_back("");
    inp.push_back("12321");
    inp.push_back("batman");
    inp.push_back("12345");
    inp.push_back("123");
    inp.push_back("rumpelstilt skin haha");
    string delim = string(DELIM, '*') + '\n';


    for(vector<string>::size_type i = 0; i < inp.size(); i++) {
        cout << "string = (" << inp[i] << ")";
        reverse(inp[i].begin() + 
                (inp[i].end() - inp[i].begin()) / 2, inp[i].end());
        cout << " reverse = (" << inp[i]  << ")"<< endl;
        my_reverse(inp[i].begin() + 
                (inp[i].end() - inp[i].begin()) / 2, inp[i].end());
        cout << " my reverse = (" << inp[i]  << ")"<< endl;
        cout << delim;
    }
}
