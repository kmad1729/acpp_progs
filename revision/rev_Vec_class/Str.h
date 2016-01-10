#pragma once

#include "Vec.h"

class Str {
    public:
        typedef Vec<char>::size_type size_type;

        Str() {};

        Str(size_type n, char c) : data(n, c) { }



    private:
        Vec<char> data;


};
