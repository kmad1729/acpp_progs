#ifndef Guard_Student_info_h
#define Guard_Student_info_h

#include <iostream>
#include <string>
#include <vector>

class Student_info {
    public:
        std::istream& read(std::istream&);
        std::string name() const {return n;}
        bool valid() const {return !homework.empty()};
        double grade();
    private:
        std::string n;
        double midterm, final;
        std::vector<double> homework;
};

bool compare(const Student_info&, const Student_info&);

#endif
