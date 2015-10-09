#ifndef Guard_Student_info_h
#define Guard_Student_info_h

#include <string>
#include <vector>
#include <iostream>

class Student_info {
    private:
        std::string n;
        double midterm, final;
        std::vector<double> homework;
    public:
        Student_info();
        Student_info(std::istream&);
        std::istream read(std::istream&);
        double grade() const;
        bool valid() const {return !homework.empty();}
        std::string name() const {return n;}
};

bool compare(const Student_info&, const Student_info&);

#endif
