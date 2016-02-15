#include <vector>
#include <algorithm>
#include <stdexcept>

using std::vector;
using std::copy;
using std::domain_error;

double median(vector<double> v)
{
    typedef vector<double>::size_type sz;
    sz vec_size = v.size();
    if(vec_size == 0)
        throw domain_error("cannot find median of empty vector!");

    sz mid = vec_size / 2;

    return vec_size % 2 == 0 ? (v[mid - 1] + v[mid]) / 2 : v[mid];

}
