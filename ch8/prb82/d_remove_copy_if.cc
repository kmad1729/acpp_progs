//program to demonstrate remove_copy_if function in stl

#include "my_include.h"

bool is_5_multiple (int i)
{
    return (i % 5 == 0);
}


int main()
{
    vector<int> v;
    for(int i = 1; i < 101; i++) v.push_back(i);

    cout << delim;
    cout << "vector v --> " << endl;
    print_vector_to_out(v);
    
    cout << "removing multiples of 5" << endl;

    vector<int> non_five_multiples;
    remove_copy_if(v.begin(), v.end(), back_inserter(non_five_multiples), is_5_multiple);

    cout << "non multiples of 5 in the vector v -->" << endl;
    print_vector_to_out(non_five_multiples);
    cout << delim;

}



