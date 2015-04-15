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
using std::remove_copy;



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

double median_analysis(const vector<Student_info>& v)
{
    vector<double> grades;
    transform(v.begin(), v.end(), back_inserter(grades), grade_aux);
    return median(grades);
}

double average(const vector<double>& v)
{
    return accumulate(v.begin(), v.end(), 0.0) / v.size();
}

double average_grade(const Student_info& s)
{
    return grade(s.midterm, s.final, average(s.homeworks));
}

double average_analysis(const vector<Student_info>& v)
{
    vector<double> grades;
    transform(v.begin(), v.end(), back_inserter(grades), average_grade);
    return median(grades);
}

double o_median_grade(const Student_info& s)
{
    vector<double> nonzero;
    remove_copy(s.homeworks.begin(), s.homeworks.end(), back_inserter(nonzero), 0);
    if(nonzero.empty()) {
        return grade(s.midterm, s.final, 0.0);
    } else {
        return grade(s.midterm, s.final, median(nonzero));
    }
}

double optimistic_median_analysis(const std::vector<Student_info>& v)
{
    vector<double> grades;
    transform(v.begin(), v.end(), back_inserter(grades), o_median_grade);
    return median(grades);
}


void write_analysis(ostream& os, const string& func_name, 
        double analysis_fun(const vector<Student_info>&),
        const vector<Student_info>& did, 
        const vector<Student_info>& didnt)
{
    os << func_name << endl << "median(did): " << analysis_fun(did)
        << " median(didnt): " << analysis_fun(didnt) << endl;
}



/*
 *  partition the students vector based on pass or fail grade
 *
 */

bool fgrade(const Student_info& s)
{
    return grade(s) < 60;
}

bool pgrade(const Student_info& s)
{
    return !fgrade(s);
}

vector<Student_info> extract_fails(vector<Student_info>& students)
{
    vector<Student_info> fails;
    remove_copy_if(students.begin(), students.end(), back_inserter(fails), pgrade);
    students.erase(remove_if(students.begin(), students.end(), fgrade), students.end());
    return fails;
}







