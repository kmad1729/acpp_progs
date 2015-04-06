#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include "string_utils.h"


using std::cout;
using std::endl;
using std::copy;
using std::string;
using std::vector;


int main()
{
    string top_string = "      accelerated cplus plu   andrew koening\nfadf dfadfa \n";
    string bottom_string = "  panasonic  \n this is a very big line\nsony dfad hollywood       \n california\n fad  aaaaa";

    cout << "top string = -->" << endl;
    cout << "(" << top_string << ")" << endl;

    cout << "bottom string = -->" << endl;
    cout << "(" << bottom_string << ")" << endl;

    cout << "after vcat -->" << endl;
    print_str_vector(split(top_string));

    return 0;
}

