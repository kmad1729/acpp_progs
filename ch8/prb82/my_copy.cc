#include "my_include.h"

template <class InputIterator, class Output>
Output my_copy(InputIterator start, InputIterator end, Output result)
{
    while(start != end) {
        *result = *start;
        result++;
        start++;
    }
    return result;
}

bool is_not_space(char c)
{
    return !isspace(c);
}

bool is_space(char c)
{
    return !is_not_space(c);
}

vector<string> split(const string& s)
{
    vector<string> result;
    typedef string::const_iterator iter;
    iter b = s.begin();
    while(b != s.end()) {
        b = find_if(b, s.end(), is_not_space);
        iter after = find_if(b, s.end(), is_space);

        if(b != after)
            result.push_back(string(b, after));

        b = after;
    }
    return result;
}


