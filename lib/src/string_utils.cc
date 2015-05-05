#include <iostream>
#include <vector>
#include <string>
#include <cctype>
#include <algorithm>


using std::string;
using std::vector;
using std::cout;
using std::isspace;
using std::find_if;


bool is_space(char c)
{
    return isspace(c);
}

bool is_not_space(char c)
{
    return !isspace(c);
}

vector<string> split (const string& s)
{
    vector<string> result;
    typedef string::const_iterator iter;
    iter beg = s.begin();
    while(beg != s.end()) {
        //omitting the first spaces
        beg = find_if(beg, s.end(), is_not_space);
        iter e = find_if(beg, s.end(), is_space);

        //copying string beg to e
        if(beg != e) 
            result.push_back(string(beg, e));
        beg = e;
    }
    return result;
}
