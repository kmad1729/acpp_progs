#ifndef Guard_Student_info
#define Guard_Student_info

#include<iostream>
#include<string>
#include<vector>

struct Student_info {
    std::string name;
    double midterm, final;
    std::vector<double> homework;
};


std::istream& read_hw(std::istream&, std::vector<double>&);

std::istream& read(std::istream&, Student_info&);

bool compare(const Student_info&, const Student_info&);

bool did_all_hw(const Student_info&);


#endif
