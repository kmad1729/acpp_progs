/*generated random sentences using the given grammar
 */

#include "acpp_utils.h"
#include <iostream>
#include <vector>
#include <string>
#include <map>
#include <cstdlib>
#include <stdexcept>
#include <time.h>

using std::cin;
using std::cout;
using std::endl;
using std::istream;

using std::vector;

using std::string;

using std::map;

using std::rand;

using std::domain_error;


typedef vector<string> Rule;
typedef vector<Rule> Rule_collection;
typedef map<string, Rule_collection> Grammar;


int nrand(int n)
{
    if(n <= 0 || n > RAND_MAX)
        throw domain_error("nrand value is out of range");


    const int bucket_count = RAND_MAX / n;
    int r;
    do {
        srand(time(0));
        int rand_num = rand();
        cout << "Bc " << bucket_count << " rand_num = " << rand_num << endl;
        r = rand_num / bucket_count;
    } while(r >= n);
    cout << n << endl;
    return r;
}

Grammar read_grammar(istream& in)
{
    string line;
    Grammar ret;
    while(getline(in, line)) {
        vector<string> words = split(line);
        if(!words.empty()) {
            ret[words[0]].push_back(Rule(words.begin() + 1, words.end()));
        }
    }
    return ret;
}

bool is_bracketed(const string& s)
{
    return s.size() != 0 && s[0] == '<' && s[s.size() - 1] == '>';
}

void gen_sentence_aux(const Grammar& g, const string& word, vector<string>& ret)
{
    if(!is_bracketed(word)) {
        ret.push_back(word);
    } else {
        Grammar::const_iterator it = g.find(word);
        if(it == g.end())
            throw domain_error("could not find the correct rule");

        const Rule_collection& rc = it -> second;

        const Rule& r = rc[nrand(rc.size())];
        
        for(Rule::const_iterator i = r.begin(); i != r.end(); i++) {
            gen_sentence_aux(g, *i, ret);
        }
    }
}

vector<string> gen_sentence(const Grammar& g)
{
    vector<string> ret;
    gen_sentence_aux(g, "<sentence>", ret);
    return ret;
}

int main()
{
    Grammar g = read_grammar(cin);

    vector<string> sentence = gen_sentence(g);
    for(vector<string>::size_type i = 0; i < sentence.size(); i++) {
        if(i == 0) {
            cout << sentence[i];
        } else {
            cout << " " << sentence[i];
        }
    }
    cout << endl;
}




