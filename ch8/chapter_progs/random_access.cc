//program to demonstrate random access iterators using binary_search
//

#include <iostream>
#include <vector>
#include <cstdlib>
#include <ctime>
#include <algorithm>
#include <unistd.h>
#define MAX 100


using std::cout;
using std::endl;
using std::vector;
using std::rand;
using std::srand;
using std::time;
using std::generate;
using std::binary_search;
//check whether a number exists in a vector of strings

//get a random number if maximum size n
int get_rand()
{
    return rand() % MAX;
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

    vector<int> tgts;
    tgts.push_back(23);
    tgts.push_back(52);
    tgts.push_back(42);
    tgts.push_back(2);
    for(vector<int>::size_type i = 0; i < tgts.size(); i++) {
        if(binary_search(v.begin(), v.end(), tgts[i])) {
            cout << tgts[i] << " was found in the vector" << endl;
        } else {
            cout << tgts[i] << " was not found in the vector" << endl;
        }
    }
    return 0;
}
