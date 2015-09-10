//program to demonstrate sequential read-only iterators. 
//Use case: STL find function

#include <iostream>
#include <vector>
#include <string>
#include <algorithm>


using std::cout;
using std::endl;
using std::vector;
using std::string;
using std::find;


int main()
{
    vector<string> names;
    vector<string> tgts;
    typedef vector<string>::const_iterator iter;

    names.push_back("batman");
    names.push_back("superman");
    names.push_back("spiderman");
    names.push_back("wolverine");
    names.push_back("flash");
    names.push_back("birdman");
    names.push_back("captain_america");
    names.push_back("ironman");
    names.push_back("thor");

    tgts.push_back("flash");
    tgts.push_back("crowman");
    tgts.push_back("antman");
    tgts.push_back("ironman");
    tgts.push_back("thor");

    for(iter it = tgts.begin(); it != tgts.end(); it++) {
        cout << "looking for " << *it;
        if(find(names.begin(), names.end(), *it) != names.end()) {
            cout << ": Found!! :)";
        } else {
            cout << ": couldn't find :(";
        }
        cout << endl;
    }

}
