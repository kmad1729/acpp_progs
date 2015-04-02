#ifndef Guard_Student_info_h
#define Guard_Student_info_h

#include <vector>
#include <string>
#include <iostream>

struct Student_info {
    std::string name;
    double midterm, final;
    std::vector<double> homeworks;
};

double grade(const Student_info&);
double grade(double, double, const std::vector<double>&);
double grade(double , double , double);

std::istream& read(std::istream&, Student_info&);


bool compare(const Student_info&, const Student_info&);

#endif
