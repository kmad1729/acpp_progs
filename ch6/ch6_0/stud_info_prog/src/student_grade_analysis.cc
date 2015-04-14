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


int main()
{
    vector<Student_info> did,didnt;

    Student_info record;

    while(read_stud_info(cin, record)) {
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
    return 0;
}
