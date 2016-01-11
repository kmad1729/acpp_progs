#ifndef Guard_Vec_h
#define Guard_Vec_h
#include <memory>
#include <algorithm>
#include <cctype>

template <class T>
class Vec {
    public:
        typedef T value_type;
        typedef T& reference_type;
        typedef const T& const_reference;
        typedef std::ptrdiff_t difference_type;

        typedef std::size_t size_type;
        typedef T* iterator;
        typedef const T* const_iterator;

        size_type size() const {return avail - data;}

        T& operator[](size_type ind) {return data[ind];}
        const T& operator[](size_type ind) const {return data[ind];}

        Vec() {create();}
        explicit Vec(size_type n, const T& val) {create(n, val);}

        iterator begin() {return data;}
        const_iterator begin() const {return data;}

        iterator end() {return avail;}
        const_iterator end() const {return avail;}

        Vec(const Vec& v) {create(v.begin(), v.end());}
        Vec& operator=(const Vec&);

        ~Vec() {uncreate();}

        void clear() {uncreate(); data = avail = limit = 0;}

        void push_back(const T& val) {
            if(avail == limit)
                grow();
            unchecked_append(val);
        }

    private:
        iterator data;
        iterator avail;
        iterator limit;

        std::allocator<T> alloc;
        void create();
        void create(const_iterator, const_iterator);
        void create(size_type, const T&);

        void uncreate();
        void grow();
        void unchecked_append(const T&);

};

template <class T>
Vec<T>& Vec<T>::operator=(const Vec& rhs) {
    if(this != &rhs) {
        uncreate();
        create(rhs.begin(), rhs.end());
    }
    return *this;
}

template<class T>
void Vec<T>::create() {
    data = avail = limit = 0;
}

template<class T>
void Vec<T>::create(size_type n, const T& val)
{
    data = alloc.allocate(n);
    std::uninitialized_fill(data, data + n, val);
    avail = limit = data + n;
}


template<class T>
void Vec<T>::create(const_iterator b, const_iterator e)
{
    data = alloc.allocate(e - b);
    avail = limit = std::uninitialized_copy(b, e, data);
}

template<class T>
void Vec<T>::grow() {
    size_type new_size = std::max(difference_type(1), 2 * (limit - data));

    iterator new_data = alloc.allocate(new_size);
    iterator new_avail = std::uninitialized_copy(data, avail, new_data);

    uncreate();
    data = new_data;
    avail = new_avail;
    limit = data + new_size;
}

template<class T>
void Vec<T>::uncreate() {
    if(avail != data) {
        iterator it = avail;
        while(data != it)
            alloc.destroy(--it);
        alloc.deallocate(data, limit - data);
    }
}

template<class T>
void Vec<T>::unchecked_append(const T& val)
{
    alloc.construct(avail++, val);
}

#endif
