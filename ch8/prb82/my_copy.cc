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


vector<string> hcat(const vector<string>& left, const vector<string>& right)
{
    vector<string> result;
    typedef vector<string>::size_type size;
    size width_l = 0;
    for(size i = 0; i < left.size(); i++) {
        width_l = max(width_l, left[i].size());
    }

    size left_ind = 0, right_ind = 0;

    while(left_ind != left.size() || right_ind != right.size()) {
        string curr_row;
        
        if(left_ind != left.size()) {
            curr_row += left[left_ind++];
        }

        curr_row += string(width_l + 1 -  curr_row.size(), ' ');

        if(right_ind != right.size()) {
            curr_row += right[right_ind++];
        }
        result.push_back(curr_row);
    }

    return result;
}

int main()
{
    vector<string> left;
    vector<string> right;
    string line;

    cout << "Please enter left lines" << endl;
    while(getline(cin, line)) {
        if(line == "####") break;
        left.push_back(line);
    }

    cout << "Please enter right lines" << endl;
    while(getline(cin, line)) {
        if(line == "####") break;
        right.push_back(line);
    }
    
    cout << "left outuput --> " << endl;
    print_vector_to_out(left);

    cout << "right outuput --> " << endl;
    print_vector_to_out(right);
}
