#include <vector>
#include <string>
#include <iostream>
#include <algorithm>
#include <iomanip>
#include <stdexcept>
#include "student_info.h"
#include "grade.h"

using std::setprecision;
using std::vector;
using std::string;
using std::cin;
using std::cout;
using std::endl;
using std::max;
using std::streamsize;
using std::domain_error;

int main()
{
    vector<Student_info> students;
    cout << "Please enter student data " << endl;
    Student_info student;
    string::size_type maxlen = 0;

    while(read(cin, student)) {
        students.push_back(student);
        maxlen = max(maxlen, student.name.size());
    }

    sort(students.begin(), students.end(), compare);

    for(vector<Student_info>::const_iterator i = students.begin();
            i != students.end(); i++) {
        string name = (i -> name);
        cout << name << string(maxlen + 1 - name.size(), ' ');
        try {
            //streamsize prec= cout.precision();
            //cout << setprecision(3) << grade(*i) << setprecision(prec);
            cout << grade(*i);
        } catch (domain_error e) {
            cout << e.what();
        }
        cout << endl;

    }
    return 0;
}
