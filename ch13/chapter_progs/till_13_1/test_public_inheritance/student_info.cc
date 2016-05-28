#include <string>
#include <iostream>

using namespace std;

class Core {
    public:
        std::string name() const {return n;}
        string public_name;
        double grade() const;
        Core() {
            n = "kashyap";
            public_name = "kashyap the great";
        }

    private:
        std::string n;
};

class Grad : Core {
    public:
        string core_name() {return public_name;}

};


int main()
{
    Grad g;
    cout << "name = " << g.core_name() << endl;
}
