#include <stdexcept>
#include <vector>
#include "median.h"

using std::vector;
using std::domain_error;

double grade(double midterm, double final, double homework)
{
    return 0.2 * midterm + 0.4 * final + 0.4 * homework;
}

double grade(double midterm, double final, const vector<double>& homework)
{
    if(homework.empty())
        throw domain_error("homewor vector is empty. Can't find median");
    return grade(midterm, final, median(homework));
}
