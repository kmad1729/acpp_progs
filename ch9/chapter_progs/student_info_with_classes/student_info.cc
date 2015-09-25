#include "student_info.h"
#include "grade.h"

using std::string;
using std::istream;
using std::vector;


Student_info::Student_info(istream& in)
{
    read(in);
}

//default constructor initialized midterm and final
//by using constructor initializers
//rest of the values are class types so they have their own
//initializers
Student_info::Student_info(): midterm(0), final(0) { };

istream& read_hw(istream& in, vector<double>& hw)
{
    if(in) {
        hw.clear();
        double x;
        while(in >> x)
            hw.push_back(x);

        in.clear();
    }
    return in;
}

istream& Student_info::read(istream& in)
{
    in >> n >> midterm >> final;
    read_hw(in, homework);
    return in;
}

double Student_info::grade() const {
    return ::grade(midterm, final, homework);
}

bool compare(const Student_info& s1, const Student_info& s2)
{
    return s1.name() < s2.name();
}
