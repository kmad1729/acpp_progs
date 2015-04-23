#include "super_include.h"

string my_concat(const vector<string>& v)
{
    string result = "";
    return accumulate(v.begin(), v.end(), result);
}

int main()
{
    vector<string> test_strings;
    test_strings.push_back("sunday");
    test_strings.push_back("Monday");
    test_strings.push_back("Tueday");
    test_strings.push_back("Wednesday");
    test_strings.push_back("Thursday");
    test_strings.push_back("Friday");
    test_strings.push_back("Saturday");

    cout << "Test_strings -->" << endl;

    ostream_iterator<string> os_iter(cout, ", ");
    cout << endl;

    copy(test_strings.begin(), test_strings.end(), os_iter);
    cout << endl;

    cout << "Resulting concatenation = " << endl;
    cout << my_concat(test_strings) << endl;

}
