#pragma once

#include <memory>
#include <cctype>
#include <iostream>
#include <algorithm>

class Str {
    public:
        typedef size_t size_type;
        typedef char value_type;
        typedef char* iterator;
        typedef const char* const_itearator;

        size_type size() const {return avail - str_beg;}

        char& operator[](size_type i) { return str_beg[i];}
        const char& operator[](size_type i) const { return str_beg[i];}

        Str() { create(); }
        Str(size_type n, char c) { create(n, c);}

        template<class In>
            Str(In b, const In e) { create(b, e);}

        ~Str() {uncreate();}

        friend std::istream& operator>>(std::istream&, Str&);

        //c_str return a NUL terminated char array
        const char* c_str() const { return str_beg; };
        //c_str and data are same as implementation make sure there is NUL
        //at the end
        const char* data() const { return str_beg; };

        size_type copy(char *, size_type) const;

        void clear() {uncreate();}



    private:
        iterator str_beg;
        iterator avail;
        iterator limit;

        std::allocator<char> alloc;

        void create();
        void create(size_type, char);
        template<class In>
            void create(In, In);

        void grow();
        void unchecked_append(const char c);
        void uncreate();
};

Str::size_type Str::copy(char* s, size_type n) const 
{
    size_type curr_str_size = (this -> size());
    size_type result = std::min(curr_str_size, n);
    std::copy(str_beg, str_beg + result, s);
    return result;
}

void Str::grow()
{
    size_type new_len = std::max(2 * (limit - str_beg), std::ptrdiff_t(1)) + 1;

    char* new_data = alloc.allocate(new_len);
    char* new_avail = std::uninitialized_copy(str_beg, avail, new_data);

    uncreate();

    str_beg = new_data;
    avail = new_avail;
    avail[0] = '\0';
    limit = str_beg + new_len;
}

void Str::unchecked_append(const char c)
{
    alloc.construct(avail++, c);
}


std::istream& operator>>(std::istream& is, Str& s)
{
    if(is) {
        s.clear();
        char c;

        while(is.get(c) && std::isspace(c))
            ;
        if(is) {
            do {
                if(s.avail == s.limit) {
                    std::cout << "adding char (" << c << ") as avail = limit" << std::endl;
                    s.grow();
                }
                s.unchecked_append(c);
            } while(is.get(c) && !isspace(c));
            s.avail[0] = '\0';
        }

        if(is)
            is.unget();

    }
    return is;
}

template <class In>
void Str::create(In b, In e)
{
    str_beg = alloc.allocate(e - b + 1);
    avail = std::uninitialized_copy(b, e, str_beg);
    avail[0] = '\0';
    limit = avail + 1;
}

std::ostream& operator<<(std::ostream& os, const Str& s)
{
    for(Str::size_type i = 0; i < s.size(); i++)
        os << s[i];
    return os;
}


void Str::create()
{
    str_beg = alloc.allocate(1);
    str_beg[0] = '\0';
    avail = str_beg;
    limit = str_beg + 1;
}

void Str::create(size_type n, char c)
{
    str_beg = alloc.allocate(n + 1);
    std::uninitialized_fill(str_beg, str_beg + n, c);
    str_beg[n] = '\0';
    avail = str_beg + n;
    limit =  avail + 1;
}

void Str::uncreate()
{
    alloc.deallocate(str_beg, limit - str_beg);
    str_beg = avail = limit = 0;
}
