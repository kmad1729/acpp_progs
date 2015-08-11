#include <vector>
#include <stdexcept>
#include <algorithm>

using std::vector;
using std::domain_error;
using std::sort;

double median(vector<double> v)
{
    if(v.size() == 0)
        throw domain_error("median of an empty vector cannot be found");
    typedef vector<double>::size_type sz_t;
    sz_t size = v.size();
    sz_t mid = size / 2;
    return size % 2 == 0? (v[mid - 1] + v[mid])/ 2: v[mid];
}
