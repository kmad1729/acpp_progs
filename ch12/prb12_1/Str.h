#pragma once

#include <memory>
#include <cctype>
#include <iostream>

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


    private:
        char* data;
        size_type len;
        std::allocator<char> alloc;

        void create();
        void create(size_type, char);
        template<class In>
            void create(In, In);

        void uncreate();
};

template <class In>
void Str::create(In b, In e)
{
    data = alloc.allocate(e - b + 1);
    std::uninitialized_copy(b, e, data);
    len = e - b;
    data[len] = '\0';
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
}

void Str::create(size_type n, char c)
{
    data = alloc.allocate(n + 1);
    std::uninitialized_fill(data, data + n, c);
    data[n] = '\0';
    len = n;
}

void Str::uncreate()
{
    alloc.deallocate(data, len + 1);
    data = NULL;
}
