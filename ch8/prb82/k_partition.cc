//demo of partition function in stl

#include "my_include.h"


template <class Bidir, class Pred>
Bidir my_partition(Bidir b, Bidir e, Pred p)
{
    while(b != e) {
        //skipping all the elements from the beginning
        //for which the predicate is true
        //if we reach the end, just return it i.e nothing to partition
        while(p(*b)) {
            b++;
            if(b == e) return b;
        }
        //there is at least one element which does not return
        //true on the predicate
        e--;
        
        //skipp all the elements from the end
        //for which the predicate is false
        //break when the predicate is true
        while(!p(*e)) {
            if(b == e) return b;
            e--;
        }
        //swap elements when predicate is false and true respectively
        //advance the true pointer as the false pointer now points to a true element
        swap(*b++, *e);
    }
    return b;
}


bool isEven(int i)
{
    return i % 2 == 0;
}

bool isOdd(int i)
{
    return !isEven(i);
}


void print_even_partition_analysis(vector<int> v)
{
    cout << "input vector --> " <<endl;
    print_vector_to_out(v);


    vector<int> v_stl(v.begin(), v.end());


    vector<int>::iterator i = partition(v_stl.begin(), v_stl.end(), isEven);
    cout << delim;

    cout << "even numbers in v (stl)" << endl << "(";
    copy(v_stl.begin(), i, ostream_iterator<int>(cout, " "));
    cout << ")" << endl;
    cout << "odd numbers in v (stl)" << endl << "(";
    copy(i, v_stl.end(), ostream_iterator<int>(cout, " "));
    cout << ")" << endl;

    cout << delim;
    i = my_partition(v.begin(), v.end(), isEven);
    cout << "even numbers in v (my)" << endl << "(";
    copy(v.begin(), i, ostream_iterator<int>(cout, " "));
    cout << ")" << endl;
    cout << "odd numbers in v (my)" << endl << "(" ;
    copy(i, v.end(), ostream_iterator<int>(cout, " "));
    cout << ")" << endl;
    cout << delim;
}


int main()
{
    vector<int> v1;
    for(int i = 0; i < 10; i++) v1.push_back(i);
    print_even_partition_analysis(v1);
    cout << delim;

    vector<int> v2;
    for(int i = 0; i < 10; i+= 2) v2.push_back(i);
    print_even_partition_analysis(v2);
    cout << delim;

    vector<int> v3;
    for(int i = 1; i < 10; i+= 2) v3.push_back(i);
    print_even_partition_analysis(v3);
    cout << delim;

    vector<int> v4;
    print_even_partition_analysis(v4);
    cout << delim;
}
