#include <vector>
#include <string>
#include <iostream>
#include <algorithm>
#include <iomanip>
#include <stdexcept>
#include "student_info.h"
#include "grade.h"
#include "median.h"

using std::setprecision;

using std::vector;

using std::string;

using std::cin;
using std::cout;
using std::endl;
using std::ostream;

using std::max;
using std::streamsize;
using std::domain_error;


void write_analysis(ostream& os, string analysis_fun_name, 
        double analysis_fun(const vector<Student_info>&), const vector<Student_info>& did,
        const vector<Student_info>& didnt)
{
    os << analysis_fun_name << " of students median(did): " <<
        analysis_fun(did) << " of students median(didnt): " << 
            analysis_fun(didnt) << endl;
}

int main()
{
    vector<Student_info> students;
    cout << "Please enter student data " << endl;
    string delim = string(20, '*') + '\n';
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

    cout << delim; 
    cout << "Analysis functions" << endl;
    cout << delim; 
    //write median, average and optimistic median analyses of 
    //students who did and didn't do the homeworks
    write_analysis(cout, "median analysis", median_analysis,
            did, didnt);
    cout << delim; 
    return 0;
}
