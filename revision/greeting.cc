#include <iostream>
#include <string>

using std::cout;
using std::cin;
using std::endl;
using std::string;

void print_decorated(string& s, char c, int padding)
{
    string::size_type s_len = s.size();
    string greeting = "Hello, " + s + "!";

    string::size_type banner_size = greeting.size() + padding * 2;
    string top = string(banner_size + 2, c);
    cout << top << endl;
    for(int i = 0; i < 2 * padding + 1; i++) {
        if(i == padding) {
            string white_sp = string(padding, ' ');
            cout << c << white_sp << greeting << white_sp << c << endl;
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
