#include "my_include.h"

template <class Bi>
void my_reverse(Bi b, Bi e)
{
    while(b < e) {
        e--;
        swap(*b++, *e);
    }
}

void reverse_analysis(string s)
{
    cout << "before reverse -->" << endl;
    cout << delim;
    cout << "\"" << s << "\"" << endl;;

    reverse(s.begin(), s.end());
    cout << delim;
    cout << "after reverse -->" << endl;
    cout << "\"" << s << "\"" << endl;;
    cout << delim;

    my_reverse(s.begin(), s.end());
    cout << "re-reverse -->" << endl;
    cout << "\"" << s << "\"" << endl;;
    cout << delim;
}

int main()
{
    string name = "SuperTerrificMan";
    reverse_analysis(name);
    cout << delim;
    reverse_analysis("");
    cout << delim;
    reverse_analysis("a");
    cout << delim;
    reverse_analysis("123");
    cout << delim;
    reverse_analysis("1234");
}
