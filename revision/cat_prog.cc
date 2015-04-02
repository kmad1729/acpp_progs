#include <iostream>
#include <string>
#include <fstream>

using std::cout;
using std::endl;
using std::cerr;
using std::string;
using std::ifstream;
using std::getline;

int main(int argc, char *argv[])
{
    int fail_count = 0;
    if(argc == 1) {
        cout << "Please enter file name/s to cat" << endl;
    } else {
        for(int i = 1; i < argc; i++) {
            ifstream in_file(argv[i]);
            if(in_file) {
                string line;
                while(getline(in_file, line)) {
                    cout << line << endl;
                }
            } else {
                cerr << "unable to open file " << argv[i] << endl;
                fail_count++;
            }
        }
    }
    return fail_count;
}
