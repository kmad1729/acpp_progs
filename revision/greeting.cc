#include <iostream>
#include <string>

using std::cout;
using std::cin;
using std::endl;
using std::string;

void print_decorated(string& s, char c, int padding)
{
    string::size_type s_len = s.size();
    string::size_type banner_size = s_len + 5 + 2 * padding;
    string top = string(banner_size + 2, c);
    cout << top << endl;
    for(int i = 0; i < 2 * padding + 1; i++) {
        if(i == padding) {
            string greeting = c + string(padding, ' ') + "Hi, " + s + "!" + string(padding, ' ') + c;
            cout << greeting << endl;
        } else {
            string other = c + string(banner_size, ' ') + c;
            cout << other << endl;
        }
    }
    cout << top << endl;
    cout << endl;
}

int main()
{
    cout << "Please enter your name: " << endl;
    string name;
    cin >> name;
    print_decorated(name, '*', 1);
}
