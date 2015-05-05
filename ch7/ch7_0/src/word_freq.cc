#include <iostream>
#include <map>
#include <string>

using std::map;
using std::getline;
using std::string;
using std::cout;
using std::endl;
using std::cin;

int main()
{
    string word;
    map<string, int> counter;

    while(cin >> word) {
        ++counter[word];
    }

    for(map<string, int>::iterator it = counter.begin(); it != counter.end(); it++) {
        cout << (it -> first) << "\t" << (it -> second) << endl;
    }
    return 0;

}
