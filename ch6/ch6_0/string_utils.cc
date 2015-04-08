#include <cctype>
#include <algorithm>
#include <vector>
#include <string>
#include <iterator>
#include <iostream>

using std::string;
using std::vector;
using std::find_if;
using std::ostream_iterator;
using std::copy;
using std::cout;
using std::endl;

bool is_space(char c)
{
    return isspace(c);
}

bool is_not_space(char c)
{
    return !isspace(c);
}

bool is_line_break(char c)
{
    return c == '\n';
}

bool is_not_line_break(char c)
{
    return c != '\n';
}

vector<string> splitlines(const string& s) 
{
    typedef string::const_iterator iter;
    vector<string> result;
    iter i = s.begin();
    while(i != s.end()) {
        //skipping the spaces and finding the first non space
        i = find_if(i, s.end(), is_not_line_break);

        // finding first space after i
        iter j = find_if(i, s.end(), is_line_break);

        // adding the word if i is not the end
        if(i != s.end()) {
            result.push_back(string(i, j));
        }

        i = j;

    }
    return result;

    
}

vector<string> split(const string& s)
{
    typedef string::const_iterator iter;
    vector<string> result;
    iter i = s.begin();
    while(i != s.end()) {
        //skipping the spaces and finding the first non space
        i = find_if(i, s.end(), is_not_space);

        // finding first space after i
        iter j = find_if(i, s.end(), is_space);

        // adding the word if i is not the end
        if(i != s.end()) {
            result.push_back(string(i, j));
        }

        i = j;

    }
    return result;
}

void print_str_vector(const std::vector<std::string>& v)
{
    ostream_iterator<string> os_iterator(cout, "#");
    copy(v.begin(), v.end(), os_iterator);
}


vector<string> vcat(const vector<string>& top,const vector<string>& bottom)
{
    vector<string> result = top;
    copy(bottom.begin(), bottom.end(), back_inserter(result));
    return result;
}
