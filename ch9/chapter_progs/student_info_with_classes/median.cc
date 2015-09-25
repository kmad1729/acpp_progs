#include <vector>
#include <stdexcept>
#include <algorithm>

using std::vector;
using std::domain_error;
using std::sort;

double median(vector<double> v)
{
    if(v.empty())
        throw domain_error("median of an empty vector");
    typedef vector<double>::size_type sz;
    sz size = v.size();
    sz.mid = size / 2;
    sort(v.begin(), v.end());
    return size % 2== 0? (v[mid - 1] + v[mid]) / 2: v[mid];

}
