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

vector<string> splitlines(const string& s)
{
    
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
    ostream_iterator<string> os_iterator(cout, " ");
    copy(v.begin(), v.end(), os_iterator);
    cout << endl;
}


