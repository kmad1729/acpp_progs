#include <iostream>
#include <string>
#include <vector>

using std::vector;
using std::string;
using std::cout; 
using std::cin;
using std::endl;

vector<string> split(const string& inp_string) {
    vector<string> ret;
    typedef string::const_iterator str_iter;
    for(str_iter iter = inp_string.begin(); iter != inp_string.end(); iter++) {
        str_iter end = find_if(iter, inp_string.end(), isspace);
        if(end != inp_string.end()) {
            ret.push_back(string(iter,end));
        }
        iter = end;
    }
    return ret;
}

void print_str_vector(const vector<string>& inp_vec) {
    cout << "{ ";
    for(vector<string>::size_type s = 0; s != inp_vec.size(); s++) {
        cout << inp_vec[s] << ","; 
    }
    cout << " }" << endl;
}

int main() {
    string test_str = "apple vlan input and final positions sequence that val returns";
    print_str_vector(split(test_str));
    return 0;
}
