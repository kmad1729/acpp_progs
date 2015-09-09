#include<iostream>
#include <map>
#define N_MAX 10

using namespace std;

void bad_fun(int& x) {
    x = 5;
}

void map_changer(map<int, int>& m)
{
    for(map<int, int>::iterator it = m.begin(); it != m.end(); it++) {
        m[it -> first] = it -> first;
    }
}

int main()
{
    int a = 100;
    cout << "before a = " << a << endl;
    bad_fun(a);
    cout << "after a = " << a << endl;
    map<int, int> test_map;
    for(int i = 0; i < N_MAX; i++) {
        test_map[i] = i * 2;
    }

    cout << endl << string(50, '*') << endl;
    cout << "before --> " << endl;
    for(map<int, int>::const_iterator it = test_map.begin(); it != test_map.end(); it++) {
        cout << it -> first << " --> " << it -> second << endl;
    }
    map_changer(test_map);
    cout << "after --> " << endl;
    for(map<int, int>::const_iterator it = test_map.begin(); it != test_map.end(); it++) {
        cout << it -> first << " --> " << it -> second << endl;
    }

}
