#include "student_info.h"
#include <iostream>
#include <string>
#include <vector>
#include <iomanip>
#include <ios>
#include <stdexcept>
#include <algorithm>

using std::cin;
using std::cout;
using std::endl;
using std::cerr;

using std::string;
using std::vector;

using std::setprecision;

using std::streamsize;

using std::domain_error;

using std::sort;
using std::max;

int main()
{
    vector<Student_info> students;
    Student_info record;
    string::size_type maxlen = 0;

    while(record.read(cin)) {
        students.push_back(record);
        maxlen = max(maxlen, record.name().size());
    }

    sort(students.begin(), students.end(), Student_info::compare);

    for(vector<Student_info>::size_type i = 0;
            i < students.size(); i++) {
        cout << students[i].name() << string(maxlen + 1 
                - students[i].name().size(), ' ');
        try {
            double grade = students[i].grade();
            streamsize prec = cout.precision();
            cout << setprecision(3) << grade << setprecision(prec) << endl;
        } catch(domain_error e) {
            cerr << e.what() << endl;
        }
    }

}
