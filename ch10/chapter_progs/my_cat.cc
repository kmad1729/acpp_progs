//my_cat program outputs file contents to stdout

#include <fstream>
#include <iostream>
#include <string>

using std::ifstream;
using std::cout;
using std::cerr;
using std::endl;
using std::getline;
using std::string;

int main(int argc, char **argv)
{
    int fail_count = 0;
    for(int i = 1; i < argc; i++) {
        ifstream infile(argv[i]);
        
        if(infile) {
            string line;
            while(getline(infile, line)) {
                cout << line << endl;
            }
        } else {
            cerr << "could not open file " << argv[i] << "!" << endl;
            ++fail_count;
        }
    }
    return fail_count;
}
