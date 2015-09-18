#include <vector>
#include <stdexcept>

#include "median.h"
#include "student_info.h"

using std::vector;
using std::domain_error;




double grade(double midterm, double final, double hw)
{
    return 0.2 * midterm + 0.4 * final + 0.4 * hw;
}

double grade(double midterm, double final, const vector<double>& v)
{
    if(v.empty())
        throw domain_error("homework vector is empty!");
    return grade(midterm, final, median(v));
}


double  grade(const Student_info& s)
{
    return grade(s.midterm, s.final, s.homework);
}

