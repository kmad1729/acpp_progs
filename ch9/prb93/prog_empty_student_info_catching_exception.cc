#include "student_info.h"

#include <stdexcept>

using std::cout;
using std::domain_error;
using std::endl;

int main()
{
    Student_info s;
    try {
        cout << "calling grade function on an unitialized Student_info object" << endl;
        double g = s.grade();
        cout << "grade = " << g << endl;
    } catch (domain_error e) {
        cout << "Caught exception e. It says " << e.what() << endl;
    }
    return 0;
}
