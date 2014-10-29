#include <vector>
#include <algorithm>
#include <stdexcept>


using std::domain_error;
using std::vector;
using std::sort;

double median(vector<double> v)
{
    if (v.empty()) {
        throw domain_error("median of an empty vector cannot be found");
    }
    typedef vector<double>::size_type vec_sz;

    vec_sz size = v.size();
    vec_sz mid = size / 2;
    return size % 2 == 0 ? (v[mid - 1] + v[mid]) / 2 : v[mid];
}
