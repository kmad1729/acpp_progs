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

    vector<Student_info> did;
    vector<Student_info> didnt;

    while(read(cin, student)) {
        students.push_back(student);
        if(did_all_hw(student))
            did.push_back(student);
        else
            didnt.push_back(student);
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

    for(vector<Student_info>::const_iterator i = did.begin();
            i != did.end(); i++) {

        string name = (i -> name);
        cout << name << string(maxlen + 1 - name.size(), ' ');
        cout << "did all hw" << endl;

    }

    for(vector<Student_info>::const_iterator i = didnt.begin();
            i != didnt.end(); i++) {

        string name = (i -> name);
        cout << name << string(maxlen + 1 - name.size(), ' ');
        cout << "didnt do all hw" << endl;
    }
    return 0;
}
