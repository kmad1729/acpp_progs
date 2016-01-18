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

        size_type size() const {return len;}

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
        size_type len;

        std::allocator<char> alloc;

        void create();
        void create(size_type, char);
        template<class In>
            void create(In, In);

        void grow();
        void uncreate();
};

void Str::grow()
{
    size_type new_len = std::max(2 * len, size_type(1));

    char *new_data = alloc.allocate(new_len);
    std::uninitialized_copy(data, data + len, new_data);

    uncreate();

    data = new_data;
    avail = data + len + 1;
    limit = data + new_len;
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
                if(s.avail == s.limit)
                    s.grow();
                s.data[s.len++] = c;
            } while(is.get(c) && !isspace(c));
            s.data[s.len] = '\0';
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
    std::uninitialized_copy(b, e, data);
    len = e - b;
    data[len] = '\0';
    avail = limit = data + len + 1;
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
    len = 0;
    avail = limit = data + 1;
}

void Str::create(size_type n, char c)
{
    data = alloc.allocate(n + 1);
    std::uninitialized_fill(data, data + n, c);
    data[n] = '\0';
    len = n;
    avail = limit = data + len + 1;
}

void Str::uncreate()
{
    alloc.deallocate(data, len + 1);
    data = avail = limit = 0;
}
