#include "student_info.h"
#include "grade.h"
#include <iostream>
#include <vector>
#include <string>
#include <algorithm>

using std::vector;
using std::istream;
using std::string;
using std::min;

istream& read_hw(istream& is, vector<double>& hw)
{
    if(is) {
        hw.clear();

        double x;
        while(is >> x)
            hw.push_back(x);

        is.clear();
    }
    return is;
}

istream& Core::read_common(std::istream& is)
{
    is >> n >> midterm >> final_grade;
    return is;
}

istream& Core::read(istream& is)
{
    read_common(is);
    read_hw(is, homework);
    return is;
}

string Core::name() const {
    return n;
}

double Core::grade() const {
    return ::grade(midterm, final_grade, homework);
}

istream& Grad::read(istream& is)
{
    read_common(is);
    is >> thesis;
    read_hw(is, homework);
    return is;
}

double Grad::grade() const {
    return min(thesis, Core::grade());
}

