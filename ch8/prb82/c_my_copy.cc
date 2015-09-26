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

vector<string> vcat(const vector<string>& top, const vector<string>& bottom) 
{
    vector<string> result(top.begin(), top.end());
    my_copy(bottom.begin(), bottom.end(), back_inserter(result));
    return result;
}

int main()
{
    //parsing the input
    cout << "enter the top and bottom lines seperated by #" << endl;
    string line;
    vector<string> top,bottom;

    while(getline(cin, line)) {
        if (line[0] == '#') {
            break;
        }
        top.push_back(line);
    }

    while(getline(cin, line)) {
        bottom.push_back(line);
    }

    cout << "top lines --> " << endl;
    print_vector_to_out(top);
    cout << "bottom lines --> " << endl;
    print_vector_to_out(bottom);

    cout << string(40, '*') << endl;
    cout << "after copying -->" << endl;
    cout << string(40, '*') << endl;

    print_vector_to_out(vcat(top, bottom));

}




