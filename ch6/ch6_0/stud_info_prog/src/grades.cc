#include "student_info.h"
#include "median.h"
#include <vector>
#include <string>
#include <stdexcept>
#include <iostream>
#include <algorithm>
#include <iterator>
#include <numeric>

using std::vector;
using std::string;
using std::domain_error;
using std::ostream;
using std::cin;
using std::transform;
using std::back_inserter;
using std::endl;
using std::accumulate;



double grade(double midt, double final, double hw)
{
    return 0.2 * midt + 0.4 * final + 0.4 * hw;
}

double grade(double midt, double final, const std::vector<double>& hw) 
{
    if(hw.size() == 0)
        throw domain_error("homework vector cannot be empty");
    return grade(midt, final, median(hw));
}

double grade(const Student_info& s) 
{
    return grade(s.midterm, s.final, s.homeworks);
}




double grade_aux(const Student_info& s)
{
    try {
        return grade(s.midterm, s.final, s.homeworks);
    } catch(domain_error e) {
        return grade(s.midterm, s.final, 0);
    }
}

double median_analysis(const std::vector<Student_info>& v)
{
    vector<double> grades;
    transform(v.begin(), v.end(), back_inserter(grades), grade_aux);
    return median(grades);
}


void write_analysis(ostream& os, const string& func_name, 
        double analysis_fun(const vector<Student_info>&),
        const vector<Student_info>& did, 
        const vector<Student_info>& didnt)
{
    os << func_name << "(did): " << analysis_fun(did) << endl
        << func_name << "(didnt): " << analysis_fun(didnt) << endl;
}
