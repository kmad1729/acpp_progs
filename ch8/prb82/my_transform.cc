//program to demo transform function in c++ stl
//it also includes an implementation of transform

#include "my_include.h"

int triple(int i)
{
    return 3 * i;
}

int squared(int i)
{
    return i * i;
}

//capitalize a given character c
char char_capitalize(char c)
{
    if(!isalpha(c))
        throw domain_error("Cannot capitalize non alphabet");
    if(c >= 'A' && c <= 'Z')
        return c;

    char diff = 'A' - 'a';
    return (c + diff);
}



template <class For, class Out, class Tranform_Func>
void my_transform(For b, For e, Out o, Tranform_Func f)
{
    while(b != e) {
        *o++ = f(*b++);
    }
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

    vector<int> v_ints_squared;
    cout << "v_ints_squared using my transform" << endl;
    my_transform(v_ints.begin(), v_ints.end(), back_inserter(v_ints_squared), squared);
    print_vector_to_out(v_ints_squared);
    cout << delim;


    string s;
    for(char c = 'a'; c <= 'z'; c+= 3) s.push_back(c);
    cout << "string after push back = " << endl;
    cout << s << endl;
    cout << delim;

    string s_capitalized;
    my_transform(s.begin(), s.end(), back_inserter(s_capitalized), char_capitalize);
    cout << "string after capitalizing = " << endl;
    cout << s_capitalized << endl;
    cout << delim;
    
}


