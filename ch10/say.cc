//program which displays all the arguments
//

#include <iostream>

using std::cout;
using std::endl;

int main(int argc, char **argv)
{
    for(int i = 1; i < argc; i++) {
        cout << argv[i] << " ";
    }
    cout << endl;
}
