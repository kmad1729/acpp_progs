#include <vector>
#include <stdexcept>
#include <algorithm>
#include <numeric>

#include "median.h"
#include "student_info.h"


using std::vector;
using std::domain_error;
using std::transform;
using std::accumulate;




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


//function calculates the grade based on midterm, final
//and homework
//if homework vector is empty, calculate the grade assuming
// 0 homework grade
double grade_aux(const Student_info& s)
{
    try {
        return grade(s);
    } catch (domain_error) {
        return grade(s.midterm, s.final, 0.0);
    }
}

double median_analysis(const vector<Student_info>& v)
{
    vector<double> grades;
    transform(v.begin(), v.end(), back_inserter(grades), grade_aux);
    return median(grades);
}


double average(const Student_info& s)
{
    double av = accumulate(s.homework.begin(), s.homework.end(), 0.0) / s.homework.size();
    return grade(s.midterm, s.final, av);
}

double average_analysis(const vector<Student_info>& v)
{
    vector<double> grades;
    transform(v.begin(), v.end(), back_inserter(grades), average);
    return median(grades);
}

