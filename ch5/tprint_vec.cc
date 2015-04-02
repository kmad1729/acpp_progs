#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
#include <cctype>
#include <iterator>

using std::cout;
using std::endl;
using std::vector;
using std::string;
using std::copy;
using std::find_if;
using std::isspace;

bool is_space(char c)
{
    return isspace(c);
}

bool is_not_space(char c)
{
    return !isspace(c);
}

vector<string> split(const string& s)
{
    vector<string> result;
    typedef string::const_iterator iter;
    for(iter i = s.begin(); i != s.end(); i++) {
        i = find_if(i ,s.end(), is_not_space);
        iter e = find_if(i, s.end(), is_space);

        if(i != e) 
            result.push_back(string(i, e));

        i = e;
    }
    return result;
}

void print_string_vec(const vector<string>& v, char* delim)
{
    std::ostream_iterator<string> os_it(cout, delim);
    copy(v.begin(), v.end(), os_it);
}

int main()
{
    string s = "            I don't get the downvotes, I did exactly this a year ago in undergrad but much more expanded and in several languages. I'd be very surprised if it's not standard   adfadfa ";
    cout << "input string --->" << endl;
    cout << "(" << s << ")" << endl;
    cout << "after split -->" << endl;
    vector<string> splitted_vec = split(s);
    char str_lit[] = "***";
    print_string_vec(split(s), str_lit);
    cout << endl;
    return 0;
}

