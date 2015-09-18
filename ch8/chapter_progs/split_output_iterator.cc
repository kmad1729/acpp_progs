//another verstion fo split function which works with output
//iterators

#include <iostream>
#include <string>
#include <iterator>
#include <algorithm>
#include <cctype>

using std::cin;
using std::cout;
using std::endl;

using std::string;

using std::ostream_iterator;

using std::find_if;

using std::isspace;

bool space(char t)
{
    return isspace(t);
}

bool not_space(char t)
{
    return !isspace(t);
}

template <class Out>
void split(const string& s, Out os)
{
    typedef string::const_iterator iter;
    iter i = s.begin();
    while(i != s.end()) {
        i = find_if(i, s.end(), not_space);
        iter j = find_if(i, s.end(), space);

        if(i != s.end())
            *os++ = string(i, j);
        i = j;
    }
}

int main()
{
    string line;
    cout << "please enter lines of words -->" << endl;
    while(getline(cin, line)) {
        cout << "split words -->" << endl;
        cout << "{";
        split(line, ostream_iterator<string>(cout, ", "));
        cout << "}" << endl;
    }

}
