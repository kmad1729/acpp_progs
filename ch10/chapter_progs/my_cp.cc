//"my_cp <f1> <f2>" copies file f1 to f2

#include <iostream>
#include <string>
#include <fstream>

using std::ofstream;
using std::ifstream;
using std::fstream;
using std::cerr;
using std::endl;
using std::getline;
using std::string;

int main(int argc, char **argv)
{
    if(argc != 3)
        cerr << "Wrong number of arguments. Expecting 3 arguments" << endl;

    ifstream in_file(argv[1]);
    ofstream out_file(argv[2]);

    string line;
    while(getline(in_file, line)) {
        out_file << line << endl;
    }
    return 0;
}
