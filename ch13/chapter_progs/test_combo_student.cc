#include "student_info.h"
#include <iostream>
#include <vector>
#include <string>
#include <ios>
#include <iomanip>
#include <algorithm>
#include <stdexcept>

using std::endl;
using std::cout;
using std::cin;

using std::vector;

using std::string;

using std::streamsize;

using std::setprecision;

using std::max;
using std::sort;

using std::domain_error;

int main()
{
    Core* record;
    vector<Core*> students;
    string::size_type maxlen = 0;
    char ch;

    while(cin >> ch) {
        if(ch == 'U') {
            record = new Core;
        } else {
            record = new Grad;
        }

        record->read(cin);
        maxlen = max(maxlen, (record->name()).size());
        students.push_back(record);
    }

    sort(students.begin(), students.end(), compare_Core_pts);

    for(vector<Core*>::size_type i = 0; i < students.size(); i++) {
        cout << students[i]->name() << string(maxlen + 1 
                - (students[i]->name()).size(), ' ');
        try {
            double grade = students[i]->grade();
            streamsize prec = cout.precision();
            cout << setprecision(3) << grade << setprecision(prec)
                << endl;
        } catch (domain_error e) {
            cout << e.what() << endl;
        }
        delete students[i];
    }

}
