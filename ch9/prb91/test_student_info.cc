#include "student_info.h"
#include <vector>
#include <iomanip>
#include <string>
#include <stdexcept>
#include <algorithm>

using std::string;
using std::vector;
using std::cin;
using std::cout;
using std::endl;
using std::streamsize;
using std::domain_error;
using std::max;
using std::sort;
using std::setprecision;

//testing if this change shows up in github contributions

int main()
{
    vector<Student_info> students;
    Student_info record;
    string::size_type maxlen = 0;

    cout << "Please enter the data: " << endl;
    while(record.read(cin)) {
        students.push_back(record);
        maxlen = max(maxlen, record.name().size());
    }

    sort(students.begin(), students.end(), compare);

    for(vector<Student_info>::size_type i = 0; i < students.size(); i++) {
            string name = students[i].name();
            streamsize prec = cout.precision();
            
            cout << name << string(maxlen + 1 - name.size(), ' ');
        try {
            double grade = students[i].grade();
            cout << setprecision(3) <<  grade << setprecision(prec) << endl;

        } catch(domain_error e) {
            cout << e.what() << endl;
        }
    }
    return 0;
}
