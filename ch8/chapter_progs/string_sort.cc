#include <iostream>
#include <string>
#include <vector>

using std::endl;
using std::cout;

using std::string;

using std::vector;

int main()
{
    vector<string> words;
    words.push_back("toolbelt");
    words.push_back("window");
    words.push_back("abcd");

    for(vector<string>::size_type i = 0; i < words.size(); i++) {
        cout << "word = " << words[i];
        sort(words[i].begin(), words[i].end());
        cout << " sorted = "  << words[i] << endl;
    }
}
