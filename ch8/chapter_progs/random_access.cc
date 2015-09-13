//program to demonstrate random access iterators using binary_search
//

#include <iostream>
#include <vector>
#include <cstdlib>
#include <ctime>
#include <algorithm>
#include <unistd.h>
#include <string>
#define MAX 100


using std::cout;
using std::endl;
using std::vector;
using std::rand;
using std::srand;
using std::time;
using std::generate;
using std::string;
using std::binary_search;
//check whether a number exists in a vector of strings

//get a random number if maximum size n
int get_rand()
{
    return rand() % MAX;
}


template <class In, class X>
bool my_binary_seach(In beg, In end, X tgt)
{
    while(beg < end) {
        In mid = beg + (end - beg) / 2;
        if(tgt < *mid) 
            end = mid;
        else if (tgt > *mid)
            beg = mid + 1;
        else 
            return true;
    }
    return false;
}

//generate a randome vector of given size
vector<int> gen_random_vec(int sz)
{
    vector<int> ret(sz);
    srand(time(NULL));
    generate(ret.begin(), ret.end(), get_rand);
    return ret;
}

int main()
{
    vector<int> v = gen_random_vec(10);
    sort(v.begin(), v.end());
    cout << "{";
    for(vector<int>::size_type i = 0; i < v.size(); i++) {
        if(i == 0) cout << v[i];
        else cout << ", " << v[i];
    }
    cout << "}" << endl;
    string delim = string(20, '*') + "\n";

    vector<int> tgts;
    tgts.push_back(23);
    tgts.push_back(52);
    tgts.push_back(42);
    tgts.push_back(2);
    cout << delim;
    cout << "with stl binary search -->" << endl;
    for(vector<int>::size_type i = 0; i < tgts.size(); i++) {
        if(binary_search(v.begin(), v.end(), tgts[i])) {
            cout << tgts[i] << " was found in the vector" << endl;
        } else {
            cout << tgts[i] << " was not found in the vector" << endl;
        }
    }
    cout << delim;

    cout << "with my binary search -->" << endl;
    for(vector<int>::size_type i = 0; i < tgts.size(); i++) {
        if(my_binary_seach(v.begin(), v.end(), tgts[i])) {
            cout << tgts[i] << " was found in the vector" << endl;
        } else {
            cout << tgts[i] << " was not found in the vector" << endl;
        }
    }
    cout << delim;

    return 0;
}
