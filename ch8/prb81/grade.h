#ifndef Guard_Grade_h
#define Guard_Grade_h

#include <vector>

double grade(const Student_info&);
double grade(double, double, double);
double grade(double, double, const std::vector<double>&);
double grade_aux(const Student_info&);
double median_analysis(const std::vector<Student_info>&);


#endif
