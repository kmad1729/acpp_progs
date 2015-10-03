#include "student_info.h"
#include "grade.h"

using std::string;
using std::vector;
using std::istream;

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

istream& Student_info::read(istream& is)
{
    is >> n >> midterm >> final;
    read_hw(is, homework);
    if(valid()) {
        g = ::grade(midterm, final, homework);
    }
    return is;
}

Student_info::Student_info(istream& is)
{
    read(is);
}

bool compare(const Student_info& s1, const Student_info& s2)
{
    return s1.name() < s2.name();
}


