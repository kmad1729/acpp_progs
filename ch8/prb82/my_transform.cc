//program to demo transform function in c++ stl
//it also includes an implementation of transform

#include "my_include.h"

int triple(int i)
{
    return 3 * i;
}

int main()
{
    vector<int> v_ints;
    for(int i = 1; i < 101; i++) v_ints.push_back(i);
    cout << "v_ints --> " << endl;
    print_vector_to_out(v_ints);

    cout << delim;

    vector<int> v_ints_tripled;
    cout << "v_ints_tripled using stl transform" << endl;
    transform(v_ints.begin(), v_ints.end(), back_inserter(v_ints_tripled), triple);
    print_vector_to_out(v_ints_tripled);
    cout << delim;
    
}


