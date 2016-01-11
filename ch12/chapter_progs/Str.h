#pragma once

#include "Vec.h"
#include <cstring>
#include <algorithm>
#include <iostream>

class Str {
    public:
        typedef Vec<char>::size_type size_type;

        size_type size() const {return data.size();}

        char& operator[](size_type i) {return data[i];}
        const char& operator[](size_type i) const {return data[i];}


        Str() {};
        Str(size_type n, char c): data(n, c) {};

        Str(const char* cp) {std::copy(cp, cp + std::strlen(cp), 
                std::back_inserter(data));}

        template <class In>
            Str(In b, In e) {std::copy(b, e, std::back_inserter(data));}

        void clear() { data.clear(); }

    private:
        Vec<char> data;
};


std::ostream& operator<<(std::ostream& os, const Str& s) {
    for(Str::size_type i = 0; i < s.size(); i++)
        os << s[i];
    return os;
}
