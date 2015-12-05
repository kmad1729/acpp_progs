#ifndef Guard_Vec_h
#define Guard_Vec_h

#include <cctype>
#include <memory>
#include "Vec.cc"

template <class T>
class Vec {
    public:
        typedef T value_type;
        typedef T& reference_type;
        typedef const T& const_reference_type;
        typedef std::ptrdiff_t difference_type;

        typedef T* iterator;
        typedef const T* const_iterator;

        typedef std::size_t size_type;

        Vec() {create();}
        explicit Vec(size_type n, const T& t = T()) {create(n, t);}
        Vec(const Vec<T>& v) {create(v.begin(), v.end());}

        Vec() operator= (const Vec<T>&);

        ~Vec() {uncreate();}

        size_type size() const {return avail - data;}

        iterator begin() {return data;}
        const_iterator begin() const {return data;}

        iterator end() {return avail;}
        const_iterator end() const {return avail;}

        T& operator[] (size_type i)  {return data[i];}
        const T& operator[] (size_type i) const {return data[i];}

        void push_back(const T& val) {
            if(avail == limit)
                grow();
            unchecked_append(val);
        }

    private:
        iterator data;
        iterator avail;
        iterator limit;

        void create();
        void create(size_type, const T&);
        void create(const_iterator, const_iterator);

        void uncreate();

        std::allocator<T> alloc;

        void grow();
        void unchecked_append(const T&);
};

#endif
