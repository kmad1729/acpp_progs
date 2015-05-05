#ifndef GUARD_acpp_utils_h
#define GUARD_acpp_utils_h

#include <vector>
#include <string>
#include <iostream>

std::vector<std::string> split(const std::string&);

void print_vec(const std::vector<std::string>&);

template <class T>
void print_vec(const std::vector<T>&);


#endif
