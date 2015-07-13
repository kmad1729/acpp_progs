#ifndef GUARD_acpp_utils_h
#define GUARD_acpp_utils_h

#include <vector>
#include <string>
#include <iostream>
#include <iterator>
#include <algorithm>

std::vector<std::string> split(const std::string&);



template <typename T>
void print_vec(const std::vector<T>&);

#endif
