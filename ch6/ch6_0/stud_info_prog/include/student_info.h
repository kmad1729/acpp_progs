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

std::istream& read_hw(std::istream&, std::vector<double>&);
std::istream& read_stud_info(std::istream&, Student_info&);

bool did_all_hw(const Student_info&);

bool compare(const Student_info&, const Student_info&);

#endif
