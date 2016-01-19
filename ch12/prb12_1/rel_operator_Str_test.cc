#include "Str.h"
#include <iostream>
#include <string>

using std::cout;
using std::cin;
using std::endl;

using std::string;

int main()
{
    Str delim(20, '*');
    Str s1("apple");
    char c_str1[] = "apple";
    Str s2("mango");

    cout << "s1 = (" << s1 << ")" << endl;
    cout << "s2 = (" << s2 << ")" << endl;
    cout << delim << endl;

    cout << "testing (==) rel operator" << endl;
    if(s1 == s2) 
        cout << s1 << " == " << s2 << " ? " << "true" << " expected false ";
    else
        cout << s1 << " == " << s2 << " ? " << "false" << " expected false ";

    cout << endl;

    if(s1 == s1) 
        cout << s1 << " == " << s1 << " ? " << "true" << " expected true ";
    else
        cout << s1 << " == " << s1 << " ? " << "false" << " expected true ";

    cout << endl;
    cout << delim << endl;

    cout << "testing (==) rel operator between Str and const char *" << endl;
    if(c_str1 == s1) 
        cout << c_str1 << " == " << s1 << " ? " << "true" << "expected true ";
    else
        cout << c_str1 << " == " << s1 << " ? " << "false" << "expected true ";

    cout << endl;
    if(c_str1 == s2) 
        cout << c_str1 << " == " << s2 << " ? " << "true" << "expected false ";
    else
        cout << c_str1 << " == " << s2 << " ? " << "false" << "expected false ";

    cout << endl;
    cout << delim << endl;


    //////// != OPERATOR /////////

    cout << "testing (!=) rel operator between Str and const char *" << endl;
    if(c_str1 != s1) 
        cout << c_str1 << " != " << s1 << " ? " << "true" << " expected false ";
    else
        cout << c_str1 << " != " << s1 << " ? " << "false" << " expected false ";

    cout << endl;
    if(c_str1 != s2) 
        cout << c_str1 << " != " << s2 << " ? " << "true" << " expected true ";
    else
        cout << c_str1 << " != " << s2 << " ? " << "false" << " expected true ";

    cout << endl;
    cout << delim << endl;

    cout << "testing (!=) rel operator" << endl;
    if(s1 != s2) 
        cout << s1 << " != " << s2 << " ? " << "true" << " expected true ";
    else
        cout << s1 << " != " << s2 << " ? " << "false" << " expected true ";

    cout << endl;

    if(s1 != s1) 
        cout << s1 << " != " << s1 << " ? " << "true" << " expected false ";
    else
        cout << s1 << " != " << s1 << " ? " << "false" << " expected false ";

    cout << endl;
    cout << delim << endl;
   
    //////// //////// /////////
    
    //////// < OPERATOR /////////

    cout << "testing (<) rel operator between Str and const char *" << endl;
    if(c_str1 < s1) 
        cout << c_str1 << " < " << s1 << " ? " << "true" << " expected false ";
    else
        cout << c_str1 << " < " << s1 << " ? " << "false" << " expected false ";

    cout << endl;
    if(c_str1 < s2) 
        cout << c_str1 << " < " << s2 << " ? " << "true" << " expected true ";
    else
        cout << c_str1 << " < " << s2 << " ? " << "false" << " expected true ";

    cout << endl;
    cout << delim << endl;

    cout << "testing (<) rel operator" << endl;
    if(s1 < s2) 
        cout << s1 << " < " << s2 << " ? " << "true" << " expected true ";
    else
        cout << s1 << " < " << s2 << " ? " << "false" << " expected true ";

    cout << endl;

    if(s1 < s1) 
        cout << s1 << " < " << s1 << " ? " << "true" << " expected false";
    else
        cout << s1 << " < " << s1 << " ? " << "false" << " expected false";

    cout << endl;
    cout << delim << endl;
   
    //////// //////// /////////

    //////// <= OPERATOR /////////

    cout << "testing (<=) rel operator between Str and const char *" << endl;
    if(c_str1 <= s1) 
        cout << c_str1 << " <= " << s1 << " ? " << "true" << " expected true ";
    else
        cout << c_str1 << " <= " << s1 << " ? " << "false" << " expected true ";

    cout << endl;
    if(c_str1 <= s2) 
        cout << c_str1 << " <= " << s2 << " ? " << "true" << " expected true ";
    else
        cout << c_str1 << " <= " << s2 << " ? " << "false" << " expected true ";

    cout << endl;
    cout << delim << endl;

    cout << "testing (<=) rel operator" << endl;
    if(s1 <= s2) 
        cout << s1 << " <= " << s2 << " ? " << "true" << " expected true ";
    else
        cout << s1 << " <= " << s2 << " ? " << "false" << " expected true ";

    cout << endl;

    if(s1 <= s1) 
        cout << s1 << " <= " << s1 << " ? " << "true" << " expected true ";
    else
        cout << s1 << " <= " << s1 << " ? " << "false" << " expected true ";

    cout << endl;
    cout << delim << endl;
    cout << delim << endl;
   
    //////// //////// /////////
    
    //////// >= OPERATOR /////////

    cout << "testing (>=) rel operator between Str and const char *" << endl;
    if(c_str1 >= s1) 
        cout << c_str1 << " >= " << s1 << " ? " << "true" << " expected true ";
    else
        cout << c_str1 << " >= " << s1 << " ? " << "false" << " expected true ";

    cout << endl;
    if(c_str1 >= s2) 
        cout << c_str1 << " >= " << s2 << " ? " << "true" << " expected false ";
    else
        cout << c_str1 << " >= " << s2 << " ? " << "false" << " expected false ";

    cout << endl;
    cout << delim << endl;

    cout << "testing (>=) rel operator" << endl;
    if(s1 >= s2) 
        cout << s1 << " >= " << s2 << " ? " << "true" << " expected false ";
    else
        cout << s1 << " >= " << s2 << " ? " << "false" << " expected false ";

    cout << endl;

    if(s1 >= s1) 
        cout << s1 << " >= " << s1 << " ? " << "true" << " expected true ";
    else
        cout << s1 << " >= " << s1 << " ? " << "false" << " expected true ";

    cout << endl;
    cout << delim << endl;
    cout << delim << endl;
   
    //////// //////// /////////
}
