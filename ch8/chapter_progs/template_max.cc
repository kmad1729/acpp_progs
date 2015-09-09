#include <iostream>
#include <string>
#include <algorithm>
#include <map>
#include <vector>

using std::cout;
using std::endl;

using std::string;
using std::max;
using std::map;
using std::vector;

template <class T>
T my_max(const T& left, const T& right)
{
    return left > right? left:right;
}


int main()
{
    vector<string> words;
    words.push_back("Batman");
    words.push_back("Superman");
    words.push_back("Spiderman");
    words.push_back("Birdman");
    words.push_back("Wolverine");
    words.push_back("Rumpelstiltskin");

    map<string, int> word_to_len_map;
    //The following instantiation won't work for using with max function
    //int max_len = 0;
    vector<string>::size_type max_len = 0;
    vector<string>::size_type my_max_len = 0;
    string max_word;
    for(vector<string>::size_type i = 0; i < words.size(); i++) {
        word_to_len_map[words[i]]  = words[i].size();
        max_len = max(max_len, words[i].size());
        my_max_len = my_max(my_max_len, words[i].size());
        if(max_len == words[i].size())
            max_word = words[i];
    }


    cout << "words --> " << endl;
    cout << "{";
    for(vector<string>::size_type i = 0; i < words.size(); i++) {
        if(i == 0)
            cout << words[i];
        else 
            cout << ", " << words[i];
    }
    cout << "}" << endl;
    cout << "max word (" << max_word << ") of length = " << max_len << " my max = " << my_max_len << endl;
}
