#include <vector>
#include "median.h"
#include <stdexcept>

using std::domain_error;
using std::vector;

double grade(double midterm, double final_grade, double homework)
{
    return 0.2 * midterm + 0.4 * final_grade + 0.4 * homework;
}

double grade(double midterm, double final_grade, const vector<double>& hw)
{
    if(hw.size() == 0)
        throw domain_error("homework vector is empty!");
    return grade(midterm, final_grade, median(hw));
}
