#ifndef Guard_Vec_h
#define Guard_Vec_h

#include <cctype>
#include <memory>
#include <algorithm>

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
        Vec(const Vec& v) {create(v.begin(), v.end());}

        Vec& operator= (const Vec&);//DONE

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

        void create(); //DONE
        void create(size_type, const T&); //DONE
        void create(const_iterator, const_iterator); //DONE

        void uncreate(); //DONE

        std::allocator<T> alloc;

        void grow(); //DONE
        void unchecked_append(const T&); //DONE
};
using std::max;

template <class T> 
Vec<T>& Vec<T>::operator= (const Vec& rhs) {
    if (this != &rhs) {
        uncreate();
        create(rhs.begin(), rhs.end());
    }
    return *this;
}

template <class T>
void Vec<T>::create() {
    data = avail = limit = 0;
}

template <class T>
void Vec<T>::create(size_type n, const T& val) {
    data = alloc.allocate(n);
    avail = limit = data + n;
    std::uninitialized_fill(data, limit, val);
}

template <class T>
void Vec<T>::create(const_iterator i, const_iterator j) {
    data = alloc.allocate(j - i);
    avail = limit = uninitialized_fill(i, j, data);
}

template <class T>
void Vec<T>::uncreate() {
    if(data) {
        iterator it = avail;
        while(it != data)
            alloc.destroy(--it);
        alloc.deallocate(data, limit - data);
    }
    data = avail = limit = 0;
}

template <class T>
void Vec<T>::grow() {
    size_type new_size = max(2 * (limit - data), ptrdiff_t(1));

    iterator new_data = alloc.allocate(new_size);
    iterator new_avail = uninitialized_fill(data, limit, new_data);

    uncreate();

    data = new_data;
    avail = new_avail;
    limit = data + new_size;
}

template <class T>
void Vec<T>::unchecked_append(const T& val) {
    alloc.construct(avail++, val);
}

#endif
