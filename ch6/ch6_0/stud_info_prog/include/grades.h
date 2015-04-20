#ifndef Guard_Grade_h
#define Guard_Grade_h

#include <vector>
#include <iostream>
#include <string>

double grade(double , double , double);
double grade(double, double, const std::vector<double>&);
double grade(const Student_info&);

/*
 * median_analysis: returns the median analysis of all student grades.
 * Each student grade is calculated using median of their homeworks.
 */
double median_analysis(const std::vector<Student_info>&);

/*
 * average_analysis: returns the median analysis of all student grades 
 * Each student grade is calculated using average of their homeworks.
 */
double average_analysis(const std::vector<Student_info>&);

double optimistic_median_analysis(const std::vector<Student_info>&);

void write_analysis(std::ostream&, const std::string&, 
        double analysis_func(const std::vector<Student_info>&),
        const std::vector<Student_info>&, const std::vector<Student_info>&);

bool pgrade(const Student_info&);
std::vector<Student_info> double_pass_extract_fails(std::vector<Student_info>&);

std::vector<Student_info> single_pass_extract_fails(std::vector<Student_info>&);

#endif
