#include <iostream>
#include <vector>
#include <string>
#include <cctype>
#include <algorithm>

using std::string;
using std::find_if;
using std::find;
using std::cout;
using std::endl;
using std::vector;

typedef string::const_iterator const_iterator;

bool not_url_char(char c)
{
    static const string url_char = "-._~:/?#[]@!$&'()*+,;=";
    return !isalnum(c) && (find(url_char.begin(), url_char.end(), c) == url_char.end());
}


const_iterator url_end(const_iterator b, const_iterator e)
{
    return find_if(b, e, not_url_char);
}

const_iterator url_beg(const_iterator b, const_iterator e)
{
    static const string url_sep = "://";
    const_iterator i = b;
    while((i = search(i, e, url_sep.begin(), url_sep.end())) != e) {
        const_iterator beg = i;

        if(beg != b && beg + url_sep.size() != e) {
            while(beg != b && isalpha(beg[-1])) {
                beg--;
            }

            if(beg != i && !not_url_char(i[url_sep.size()])) {
                return beg;
            }
        }

        i += url_sep.size();
    }
    return e;
}

vector<string> url_helper(const string& s)
{
    vector<string> ret;
    const_iterator b = s.begin();
    while(b != s.end()) {
        b = url_beg(b, s.end());
        const_iterator e = url_end(b, s.end());
        if(b != s.end()) {
            ret.push_back(string(b, e));
        }
        b = e;
    }
    return ret;
}


int main()
{
    string test_str1 = "://bar.com/add 233://barfooenterprice http://www.google.com h://foobar.com 1://33 abc:// ://";
    vector<string> urls_in_string = url_helper(test_str1);
    for(vector<string>::size_type i = 0; i < urls_in_string.size(); i++) {
        cout << urls_in_string[i] << endl;
    }
    return 0;
}
