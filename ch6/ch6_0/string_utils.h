#ifndef Guard_print_utils_h
#define Guard_print_utils_h


#include <vector>
#include <string>

/*
    splits a string into words by white spaces
*/
std::vector<std::string> split(const std::string&);
std::vector<std::string> splitlines(const std::string&);

std::vector<std::string> vcat(const std::vector<std::string>&,const std::vector<std::string>&);
void print_str_vector(const std::vector<std::string>&);


#endif
