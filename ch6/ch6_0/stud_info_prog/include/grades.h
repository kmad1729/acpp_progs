#ifndef Guard_Grade_h
#define Guard_Grade_h

#include <vector>
#include <iostream>
#include <string>

double grade(double , double , double);
double grade(double, double, const std::vector<double>&);
double grade(const Student_info&);

/*
 * median_analysis: returns the median of all homoworks of vector of students
 */
double median_analysis(const std::vector<Student_info>&);

void write_analysis(std::ostream&, const std::string&, 
        double analysis_func(const std::vector<Student_info>&),
        const std::vector<Student_info>&, const std::vector<Student_info>&);


#endif
