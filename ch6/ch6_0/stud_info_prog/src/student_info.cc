#include "student_info.h"
#include <vector>
#include <string>
#include <stdexcept>
#include <iostream>

using std::vector;
using std::string;
using std::domain_error;
using std::istream;
using std::cin;


istream& read_hw(istream& in_stream, vector<double>& hw)
{
    //making sure in_stream is clear of errors
    if(in_stream) {
        //we are not making hw vector - its given to us by caller. So we make sure the it is empty before we enter any data
        hw.clear();
        double x;

        while(in_stream >> x) {
            hw.push_back(x);
            //std::cout << "read value " << x << std::endl;
        }

        /*make sure istream is clear. It won't be clear for 2 possible reasons
        1) Reached EOF. which is a valid scenario. clear() does no harm in this case.
        2) in_stream encountered a non-double value. In this case error flag is set. So clear remove the error flag so that cin can be used in future read operations.
        */
        in_stream.clear();
    }
    return in_stream;
}

istream& read_stud_info(istream& in_stream, Student_info& s)
{
    in_stream >> s.name >> s.midterm >> s.final;
    //std::cout << "name is " << s.name << std::endl;
    read_hw(in_stream, s.homeworks);
    return in_stream;
}

bool did_all_hw(const Student_info& s)
{
    return (find(s.homeworks.begin(), s.homeworks.end(), 0) == s.homeworks.end());
}

bool compare(const Student_info& s1, const Student_info& s2)
{
    return s1.name < s2.name;
}
