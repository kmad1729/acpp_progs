#include "student_info.h"
#include <vector>
#include <string>
#include <iostream>

using std::vector;
using std::string;
using std::istream;

istream& read_hw(istream& in, vector<double>& hw)
{
    if(in) {
        hw.clear();
        double x;

        while(in >> x) {
            hw.push_back(x);
        }
        in.clear();
    }
    return in;
}

istream& read(istream& in, Student_info& s) {
    in >> s.name >> s.midterm >> s.final;
    read_hw(in, s.homework);
    return in;
}

bool compare(const Student_info& s1, const Student_info& s2) {
    return s1.name < s2.name;
}
