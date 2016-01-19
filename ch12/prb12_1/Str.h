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

        size_type size() const {return avail - data;}

        char& operator[](size_type i) { return data[i];}
        const char& operator[](size_type i) const { return data[i];}

        Str() { create(); }
        Str(size_type n, char c) { create(n, c);}

        template<class In>
            Str(In b, const In e) { create(b, e);}

        ~Str() {uncreate();}

        friend std::istream& operator>>(std::istream&, Str&);

        void clear() {uncreate();}



    private:
        iterator data;
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

void Str::grow()
{
    size_type new_len = std::max(2 * (limit - data), std::ptrdiff_t(1)) + 1;

    char* new_data = alloc.allocate(new_len);
    char* new_avail = std::uninitialized_copy(data, avail, new_data);

    uncreate();

    data = new_data;
    avail = new_avail;
    avail[0] = '\0';
    limit = data + new_len;
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
    data = alloc.allocate(e - b + 1);
    avail = std::uninitialized_copy(b, e, data);
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
    data = alloc.allocate(1);
    data[0] = '\0';
    avail = data;
    limit = data + 1;
}

void Str::create(size_type n, char c)
{
    data = alloc.allocate(n + 1);
    std::uninitialized_fill(data, data + n, c);
    data[n] = '\0';
    avail = data + n;
    limit =  avail + 1;
}

void Str::uncreate()
{
    alloc.deallocate(data, limit - data);
    data = avail = limit = 0;
}


bool operator==(const Str& lhs, const Str& rhs)
{
    return (std::strcmp(lhs.c_str(), rhs.c_str()) == 0);
}
