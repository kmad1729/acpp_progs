#include <fstream>
#include <iostream>
#include "Str.h"

using std::cout;
using std::endl;
using std::cerr;
using std::ifstream; 
using std::string;

int main(int argc, char* argv[])
{
    int fail_count = 0;
    for(int i = 1; i < argc; i++) {
        ifstream inp_file(argv[i]);
        if(inp_file) {
            Str line;
            while(getline(inp_file, line)) {
                cout << line << endl;
            }
        } else {
            cerr << "Couldn't open file " << argv[i] << endl;
            ++fail_count;
        }
    }
    return fail_count;
}
