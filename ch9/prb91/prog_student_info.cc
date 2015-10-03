#include "student_info.h"

#include <iomanip>
#include <string>
#include <stdexcept>

using std::vector;
using std::cout;
using std::cin;
using std::cerr;
using std::endl;

using std::string;
using std::setprecision;
using std::streamsize;
using std::max;
using std::domain_error;

int main()
{
    vector<Student_info> students;
    Student_info record;
    string::size_type maxlen = 0;

    while(record.read(cin)) {
        students.push_back(record);
        maxlen = max(maxlen, record.name().size());
    }

    sort(students.begin(), students.end(), compare);

    for(vector<string>::size_type i = 0; i != students.size(); i++) {
        cout << students[i].name() << string(maxlen + 1 - students[i].name().size(), ' ');
        if(students[i].valid()) {
            streamsize prec = cout.precision();
            cout << setprecision(3) << students[i].grade() << setprecision(prec);
        } else {
            cerr << "Homework vector is empty!!";
        }
        cout << endl;
    }
}
