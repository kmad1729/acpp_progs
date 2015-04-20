#include <iostream>
#include "student_info.h"
#include "grades.h"
#include <vector>
#include <string>

using std::cin;
using std::cout;
using std::endl;
using std::vector;
using std::string;
using std::max;

void print_vector_student_info(const vector<Student_info>& v, string::size_type maxlen)
{
    for(vector<Student_info>::size_type i = 0; i < v.size(); i++) {
        cout << v[i].name << string(maxlen + 1 - v[i].name.size(), ' ') << grade(v[i]) << endl;
    }
}

void print_extract_fails(vector<Student_info> passed, vector<Student_info> extract_failed_func(vector<Student_info>&), string::size_type maxlen)
{
    cout << string(40, '*') << endl;
    cout << "Pass fail analysis --->" << endl;
    vector<Student_info> failed = extract_failed_func(passed);

    cout << "Passed students -->" << endl;
    print_vector_student_info(passed, maxlen);

    cout << "Failed students -->" << endl;
    print_vector_student_info(failed, maxlen);
    cout << string(40, '*') << endl;
}

int main()
{
    cout << string(40, '*') << endl;
    vector<Student_info> did,didnt, students;

    Student_info record;
    string::size_type maxlen = 0;

    while(read_stud_info(cin, record)) {
        students.push_back(record);
        maxlen = max(maxlen, record.name.size());
        if(did_all_hw(record)) {
            did.push_back(record);
        } else {
            didnt.push_back(record);
        }
    }

    if(did.empty()) {
        cout << "no student finished all homework!" << endl;
        return 1;
    } 
    if (didnt.empty()) {
        cout << "all students finished homework!" << endl;
        return 1;
    }

    write_analysis(cout, "median analaysis", median_analysis, did, didnt);
    
    write_analysis(cout, "average analysis", average_analysis, did, didnt);
    
    write_analysis(cout, "optimistic analysis", optimistic_median_analysis, did, didnt);


    cout << string(40, '*') << endl;
    cout << "Double pass solution --->" << endl;
    print_extract_fails(students, double_pass_extract_fails, maxlen);

    cout << "Single pass solution --->" << endl;
    print_extract_fails(students, single_pass_extract_fails, maxlen);


    return 0;
}
