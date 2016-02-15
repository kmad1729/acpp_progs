#include "median.h"
#include <vector>
#include <stdexcept>

using std::vector;
using std::domain_error;

double grade(double midterm, double final, double hw)
{
    return 0.2 * midterm + 0.4 * final + 0.4 * hw;
}

double grade(double midterm, double final, const vector<double>& hw)
{
    if(hw.size() == 0)
        throw domain_error("homework vector is empty!");
    return grade(midterm, final, median(hw));
}

