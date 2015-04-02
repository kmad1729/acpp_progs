#include "student_info.h"
#include "median.h"
#include <vector>
#include <string>
#include <stdexcept>
#include <iostream>

using std::vector;
using std::string;
using std::domain_error;
using std::istream;
using std::cin;


double grade(const Student_info& s) 
{
    return grade(s.midterm, s.final, s.homeworks);
}


double grade(double midt, double final, const std::vector<double>& hw) 
{
    if(hw.size() == 0)
        throw domain_error("homework vector cannot be empty");
    return grade(midt, final, median(hw));
}


double grade(double midt, double final, double hw)
{
    return 0.2 * midt + 0.4 * final + 0.4 * hw;
}

istream& read_hw(istream& in_stream, vector<double>& hw)
{
    //making sure in_stream is clear of errors
    if(in_stream) {
        //we are not making hw vector - its given to us by caller. So we make sure the it is empty before we enter any data
        hw.clear();
        double x;

        while(in_stream >> x) {
            hw.push_back(x);
        }

        /*make sure istream is clear. It won't be clear for 2 possible reasons
        1) Reached EOF. which is a valid scenario. clear() does no harm in this case.
        2) in_stream encountered a non-double value. In this case error flag is set. So clear remove the error flag so that cin can be used in future read operations.
        */
        in_stream.clear();
    }
    return in_stream;
}

istream& read(istream& in_stream, Student_info& s)
{
    in_stream >> s.name >> s.midterm >> s.final;
    read_hw(in_stream, s.homeworks);
    return in_stream;
}

bool compare(const Student_info& s1, const Student_info& s2)
{
    return s1.name < s2.name;
}
