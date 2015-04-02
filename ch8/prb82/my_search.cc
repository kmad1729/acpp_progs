#include "my_include.h"

template <class In>
In my_search(In outer_beg, In outer_end, In inner_beg, In inner_end)
{
    for(In i = outer_beg; i <= outer_end - (inner_end - inner_beg); i++) {
        In j;
        for(j = inner_beg; j != inner_end; j++) {
            if(i[j - inner_beg] != *j) break;
        }
        if(j == inner_end) return i;
    }

    return outer_end;
}

int get_count_of_word(const string& sentence, const string& word)
{
    //return the number of occurences of word in the sentence
    int result = 0;
    string::const_iterator i = my_search(sentence.begin(), sentence.end(), word.begin(), word.end());

    while(i != sentence.end()) {
        if((
            i == sentence.begin() || isspace(i[-1])) 
            && (isspace(i[word.size()]) || (i + word.size() == sentence.end())
        )) {
            result++;
            cout << "found at index " << i - sentence.begin() << endl;
        }
        i = my_search(i + word.size(), sentence.end(), word.begin(), word.end());
    }
    return result;
}

int main()
{
    string word = "the";
    string line;
    cout << "please enter the input line -->" << endl;
    getline(cin, line);

    int result = get_count_of_word(line, word);
    cout << "count of the word \"" << word << "\" in the sentence = " << result << endl;
}
