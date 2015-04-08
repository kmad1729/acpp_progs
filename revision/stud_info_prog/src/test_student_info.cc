#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
#include <stdexcept>
#include <iomanip>
#include "student_info.h"

using std::string;
using std::vector;
using std::cout;
using std::max;
using std::endl;
using std::domain_error;
using std::streamsize;
using std::setprecision;
using std::cin;

int main()
{
    vector<Student_info> students;
    string::size_type max_len = 0;

    Student_info tmp_student;
    while(read_stud_info(cin, tmp_student)) {
        max_len = max(max_len, tmp_student.name.size());
        students.push_back(tmp_student);
    }

    sort(students.begin(), students.end(), compare);

    for(vector<Student_info>::size_type i = 0; i != students.size(); i++) {
        cout << students[i].name << string(max_len + 1 - students[i].name.size(), ' ');

        //calculating the grade part
        try {
            double final_grade = grade(students[i]);
            streamsize prec = cout.precision();
            cout << setprecision(3) << final_grade << setprecision(prec) << endl;
        } catch(domain_error e) {
            cout << e.what() << endl;
        }
    }
    return 0;
}
