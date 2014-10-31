#include "student_info.h"
#include "grade.h"

using std::vector;
using std::istream;
using std::string;


istream& read_hw(istream& in, vector<double>& h)
{
    if(in) {
        //make sure h is not populated with previous homework entries
        h.clear();

        double x;
        while(in >> x) {
            h.push_back(x);
        }

        //clearing hte istream flag
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


Student_info::Student_info() : midterm(0), final(0) { }
Student_info::Student_info(istream& in) { read(in);}

bool compare(const Student_info& s1, const Student_info& s2) 
{
    return s1.name() < s2.name();
}
