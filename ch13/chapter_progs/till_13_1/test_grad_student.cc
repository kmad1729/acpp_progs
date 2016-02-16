#include "student_info.h"
#include "grade.h"
#include <vector>
#include <iostream>
#include <string>
#include <iomanip>
#include <ios>
#include <algorithm>
#include <stdexcept>

using std::vector;

using std::cout;
using std::cin;
using std::endl;

using std::string;

using std::setprecision;

using std::streamsize;

using std::max;
using std::sort;

using std::domain_error;

int main()
{
    Grad record;
    vector<Grad> students;
    string::size_type maxlen = 0;

    //reading the student records
    while(record.read(cin)) {
        maxlen = max(record.name().size(), maxlen);
        students.push_back(record);
    }

    //sort the student records based on name
    sort(students.begin(), students.end(), compare);

    //outputting the result
    for(vector<Grad>::size_type i = 0; i < students.size(); i++) {
        try {
            double grade = students[i].grade();
            cout << students[i].name() 
                << string(maxlen + 1 - students[i].name().size(), ' ');
            streamsize prec = cout.precision();
            cout << setprecision(3) << grade << setprecision(prec) << endl;
        } catch(domain_error e) {
            cout << e.what() << endl;
        }
    }

}

