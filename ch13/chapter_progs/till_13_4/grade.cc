#include <vector>
#include "median.h"
#include <stdexcept>

using std::vector;
using std::domain_error;

double grade(double midterm, double fin, double hw)
{
    return 0.2 * midterm + 0.4 * fin + 0.4 * hw;
}

double grade(double midterm, double fin, const vector<double>& hw)
{
    if(hw.size() == 0)
        throw domain_error("hw vector is empty!");
    return grade(midterm, fin, median(hw));
}
