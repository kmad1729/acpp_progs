#include "student_info.h"
#include "grade.h"

#include <stdexcept>

using std::string;
using std::vector;
using std::istream;
using std::domain_error;


Student_info::Student_info(): midterm(0), final(0) {}


istream& read_hw(istream& is, vector<double>& hw)
{
    if(is) {
        hw.clear();
        double x;
        while(is >> x)
            hw.push_back(x);
        is.clear();
    }
    return is;
}

Student_info::Student_info(istream& is)
{
    is >> n >> midterm >> final;
    read_hw(is, homework);
}

double Student_info::grade() const 
{
    string delim = '\n' + string(20, '*') + '\n';

    if(n.empty())
        throw domain_error(delim + "Student is not initialized !!!" + delim);

    return ::grade(midterm, final, homework);
}

bool compare(const Student_info& s1, const Student_info& s2)
{
    return s1.name() < s2.name();
}

