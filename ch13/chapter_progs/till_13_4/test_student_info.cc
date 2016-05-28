#include "student_info.h"
#include <iostream>
#include <algorithm>
#include <vector>
#include <string>
#include <stdexcept>
#include <ios>
#include <iomanip>

using std::cin;
using std::endl;
using std::cout;
using std::cerr;

using std::copy;
using std::max;

using std::vector;

using std::string;

using std::domain_error;

using std::streamsize;

using std::setprecision;

int main()
{
    vector<Core*> students;
    Core* record;
    vector<string>::size_type maxlen = 0;
    char c;

    while(cin >> c) {
        if(c == 'U')
            record = new Core();
        else
            record = new Grad();
        record -> read(cin);
        maxlen = max(maxlen, (record -> name()).size());
        students.push_back(record);
    }

    sort(students.begin(), students.end(), compare_Core_ptrs);

    for(int i = 0; i < students.size(); i++) {
        cout << (students[i] -> name()) << 
            string(maxlen + 1 - (students[i] -> name()).size(), ' ');
        try {
            double grade = students[i] -> grade();
            streamsize prec = cout.precision();
            cout << setprecision(3) << grade << setprecision(prec) << endl;
        } catch (domain_error e) {
            cerr << e.what() << endl;
        }

        delete students[i];

    }
}
