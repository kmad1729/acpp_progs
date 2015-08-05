#include <iostream>
#include <string>
#include <vector>
#include <map>
#include <algorithm>

using std::cout;
using std::endl;
using std::cin;

using std::string;

using std::vector;

using std::map;

using std::max;

int main()
{
    map<string, int> counters;
    string s;
    string::size_type max_word_len = 0;
    while(cin >> s) {
        ++counters[s];
        max_word_len = max(max_word_len, s.size());
    }

    map<int, vector<string> > sorted_counter;
    for(map<string, int>::const_iterator it = counters.begin(); it != counters.end(); it++){
        sorted_counter[it -> second].push_back(it -> first);
    }

    for(map<int, vector<string> >::const_iterator it = sorted_counter.begin(); it != sorted_counter.end(); it++){
        vector<string> words = it -> second;

        for(vector<string>::const_iterator i = words.begin(); i != words.end(); i++) {
            cout << *i << string(max_word_len + 1 - i->size(), ' ') << it -> first << endl;
        }
    }
    return 0;
}
