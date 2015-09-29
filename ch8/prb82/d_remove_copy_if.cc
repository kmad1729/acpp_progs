//program to demonstrate remove_copy_if function in stl

#include "my_include.h"


template <class ForwardIterator, class OutputIterator, class Predicate>
OutputIterator my_remove_copy_if(ForwardIterator b, ForwardIterator e, OutputIterator result, Predicate pred)
{
    while(b != e) {
        if(!pred(*b)) {
            *result++ = *b;
        }
        b++;
    }
    return result;
}

bool is_5_multiple (int i)
{
    return (i % 5 == 0);
}

bool is_3_multiple (int i)
{
    return (i % 3 == 0);
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

    cout << "removing multiples of 3" << endl;

    vector<int> non_three_multiples;
    my_remove_copy_if(v.begin(), v.end(), back_inserter(non_three_multiples), is_3_multiple);

    cout << "non multiples of 3 in the vector v -->" << endl;
    print_vector_to_out(non_three_multiples);
    cout << delim;

}



