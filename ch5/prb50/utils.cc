#include "my_include.h"

void print_vector_to_out(const vector<string>& v)
{
    copy(v.begin(), v.end(), ostream_iterator<string>(cout, "\n"));
}
