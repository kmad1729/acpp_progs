#include <iostream>
#include <string>
#include <vector>
#include <algorithm>

using std::endl;
using std::cout;

using std::string;

using std::vector;

using std::reverse;

int main()
{
    vector<string> words;
    words.push_back("toolbelt");
    words.push_back("window");
    words.push_back("abcd");
    words.push_back("abc");

    for(vector<string>::size_type i = 0; i < words.size(); i++) {
        cout << "word = " << words[i];
        reverse(words[i].begin(), words[i].end());
        cout << " reversed = " << words[i] << endl;
    }

}
