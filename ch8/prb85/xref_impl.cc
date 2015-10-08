#include <map>
#include <vector>
#include <iostream>
#include <string>
#include <iterator>
#include <algorithm>
#include <cctype>

using std::map;
using std::vector;
using std::cout;
using std::cin;
using std::endl;
using std::string;
using std::getline;
using std::ostream_iterator;
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
    typedef string::const_iterator str_iter;
    str_iter beg = s.begin();

    while(beg != s.end()) {
        beg = find_if(beg, s.end(), is_not_space);
        str_iter e = find_if(beg, s.end(), is_space);

        if(beg != e)
            result.push_back(string(beg, e));
        beg = e;
    }
    return result;
}

template <class T>
void print_vector(const vector<T>& v)
{
    cout << "{";
    copy(v.begin(), v.end(), ostream_iterator<T>(cout, ","));
    cout << "}" << endl;
}

int main()
{
    string line;
    string delim = string(20, '*') + '\n';

    while(getline(cin, line)) {
        cout << "line --> " << endl;
        cout << line << endl << delim;
        cout << "split vector --> " << endl;
        print_vector(split(line));
        cout << endl;
    }
    return 0;
}


