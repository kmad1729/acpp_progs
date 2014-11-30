#include "my_include.h"

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

    cout << string(80, '*') << endl;;

    cout << "after horizontally concatinating both texts -->" << endl;
    cout << string(80, '*') << endl;;
    print_vector_to_out(hcat(left, right));
}
