#include <vector>
#include <algorithm>
#include <stdexcept>

using std::sort;
using std::vector;
using std::domain_error;

double median(vector<double> v)
{
    if(v.size() == 0)
        throw domain_error("median of empty vector cannot be found!");
    typedef vector<double>::size_type vec_sz;
    sort(v.begin(), v.end());
    vec_sz size = v.size();
    vec_sz mid = size / 2;
    return size % 2 == 0? (v[mid - 1] + v[mid]) / 2: v[mid];
}
