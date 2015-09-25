#include "student_info.h"

#include <vector>
#include <string>
#include <iostream>
#include <algorithm>
#include <iomanip>
#include <ios>
#include <stdexcept>

using std::vector;

using std::string;

using std::cin;
using std::cout;
using std::endl;

using std::max;
using std::setprecision;
using std::streamsize;

using std::domain_error;

int main()
{
    vector<Student_info> students;
    Student_info record;
    string::size_type maxlen = 0;

    while(record.read(cin)) {
        maxlen = max(maxlen, record.name().size());
        students.push_back(record);
    }

    //sorting the students based on alphabetical order
    sort(students.begin(), students.end(), compare);

    for(vector<Student_info>::size_type i = 0; i < students.size(); i++) {
        cout << students[i].name() << 
            string(maxlen + 1 - students[i].name().size(), ' ');
        try {
            double grade = students[i].grade();
            streamsize prec = cout.precision();
            cout << setprecision(5) << grade << setprecision(prec) << endl;
        } catch (domain_error e) {
            cout << e.what() << endl;
        }

    }
    return 0;
}
