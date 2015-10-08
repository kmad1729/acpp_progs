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
using std::istream;
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

map<string, vector<int> > xref_impl(istream& in, vector<string> find_words(const string&) = split)
{
    string line;
    map<string, vector<int> > result;
    int line_number = 0;

    while(getline(in, line)) {
        ++line_number;
        vector<string> tokens = find_words(line);
        for(vector<string>::const_iterator it = tokens.begin();
                it != tokens.end(); it++) {
            result[*it].push_back(line_number);
        }
    }
    return result;

}

int main()
{
    string line;
    string delim = string(20, '*') + '\n';

    map<string, vector<int> > m = xref_impl(cin);

    for(map<string, vector<int> >::const_iterator it = m.begin();
            it != m.end(); it++) {
        cout << "\"" << (it -> first) << "\" occurs at ";
        vector<int> occurences = (it -> second);
        copy(occurences.begin(), occurences.end(), 
                ostream_iterator<int>(cout, " "));
        cout << endl;
    }

    return 0;
}


