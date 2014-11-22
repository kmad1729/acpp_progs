#include <iostream>
#include <algorithm>
#include <string>
#include <cstddef>
#define DEFAULT_SIZE 10

using std::string;
using std::cout;
using std::endl;
using std::copy;

class String_List{
    public:
        String_List();
        String_List(size_t);
        void push_back(const string&);
        void print_list();
    private:
        string *s_list;
        size_t total_size;
        size_t populated_size;
};


String_List::String_List() : populated_size(0), total_size(DEFAULT_SIZE)
{
    s_list = new string[total_size];

}

String_List::String_List(size_t n): populated_size(0)
{
    s_list = new string[n];
    total_size = n;
}

void String_List::print_list() 
{
    for(size_t i = 0; i < populated_size; i++) {
        if (i == 0) cout << s_list[i];
        else cout << ", " <<  s_list[i];
    }
    cout << endl;
}

void String_List::push_back(const string& s)
{
    if(populated_size < total_size) {
        s_list[populated_size++] = s;
    } else {
        string *new_list = new string[2 * total_size];
        copy(s_list, s_list + total_size, new_list);
        string *old_list = s_list;
        s_list = new_list;
        total_size *= 2;
        delete[] old_list;
    }
}

int main()
{
    String_List sl(2);
    sl.print_list();
    sl.push_back("coldplay");
    sl.push_back("metallica");
    sl.push_back("aerosmith");
    sl.push_back("imagine_dragons");
    sl.push_back("led_zeppelin");
    sl.push_back("doors");
    sl.push_back("beatles");
    sl.print_list();
    /*
    names[0] = "coldplay";
    names[1] = "metallica";
    names[2] = "aerosmith";
    */

}
