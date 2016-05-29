#include "student_info.h"
#include "grade.h"
#include <iostream>
#include <vector>
#include <string>
#include <stdexcept>
#include <algorithm>

using std::istream;
using std::vector;
using std::string;
using std::domain_error;
using std::min;

string Core::name() const {
    return n;
}

double Core::grade() const {
    return ::grade(midterm, final_grade, homework);
}

istream& read_hw(istream& is, vector<double>& hw) {
    if(is) {
        hw.clear();

        double x;
        while(is >> x)
            hw.push_back(x);

        is.clear();
    }
    return is;
}

istream& Core::read(istream& is) {
    read_common(is);
    read_hw(is, homework);
    return is;

}

istream& Core::read_common(istream& is) {
    is >> n >> midterm >> final_grade;
    return is;
}

double Grad::grade() const {
    return min(thesis, Core::grade());
}

istream& Grad::read(istream& is)
{
    read_common(is);
    is >> thesis;
    read_hw(is, homework);
    return is;
}

Student_info::Student_info(const Student_info& st) : cp(0)
{
    if(st.cp) { cp = (st.cp -> clone()); }
}

Student_info& Student_info::operator=(const Student_info& s)
{
    if(this != &s) {
        delete cp;

        if(s.cp) {
            cp = s.cp -> clone();
        } else {
            cp = 0;
        }
    }
    return *this;
}

istream& Student_info::read(istream& is)
{
    char c;
    is >> c;

    if(c == 'U') {
        cp = new Core(is);
    } else {
        cp = new Grad(is);
    }

    return is;
}



