#include "student_info.h"
#include "grade.h"

#include <iostream>
#include <vector>
#include <string>
#include <stdexcept>
#include <iomanip>
#include <algorithm>


using std::cin;
using std::cout;
using std::endl;
using std::streamsize;

using std::vector;

using std::string;

using std::domain_error;
using std::setprecision;

using std::max;
using std::sort;

int main()
{
    vector<Student_info> students;
    Student_info record;
    string::size_type max_len = 0;

    while(read(cin, record)){
        students.push_back(record);
        max_len = max(max_len, record.name.size());
    }
    sort(students.begin(), students.end(), compare);

    for(vector<Student_info>::size_type i = 0; i != students.size(); i++) {
        cout << students[i].name << string(max_len + 1 - students[i].name.size(), ' ');

        try {
            double final_grade = grade(students[i]);
            streamsize s = cout.precision();
            cout << setprecision(3) << final_grade << setprecision(s) << endl;
        } catch(domain_error e) {
            cout << e.what() << endl;
        }
    }
    return 0;
}
