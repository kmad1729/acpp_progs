#ifndef Guard_Student_info_h
#define Guard_Student_info_h

#include <string>
#include <vector>
#include <iostream>

class Student_info {
    public:
        std::string name() const {return n;}
        double grade() const {return g;}
        std::istream& read(std::istream&);
        bool valid() const {return !homework.empty();}
        Student_info() {} ;
        Student_info(std::istream&);


    private:
        std::string n;
        double midterm, final;
        std::vector<double> homework;
        double g;
};


bool compare(const Student_info&, const Student_info&);

#endif
