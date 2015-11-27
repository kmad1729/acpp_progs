#include <fstream>
#include <string>
#include <iostream>

using std::getline;
using std::ifstream;
using std::ofstream;
using std::string;
using std::cerr;
using std::cout;
using std::endl;

int main(int argc, char **argv)
{
    if(argc != 3) {
        cerr << "please enter a source and dest file name" << endl;
        return 1;
    }

    string fname(argv[1]);
    string o_fname(argv[2]);

    ifstream inp(fname.c_str());
    ofstream outp(o_fname.c_str());

    if (inp) {
        string line;
        while(getline(inp, line)) {
            outp << line << endl;
        }

        return 0;
    }

}
