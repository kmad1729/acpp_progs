#include <memory>
#include <algorithm>
#include <cctype>

template <class T>
class Vec {
    public:
        typedef T value_type;
        typedef T* reference;
        typedef const T* const_reference;
        typedef std::ptrdiff_t difference_type;

        typedef T* iterator;
        typedef const T* const_iterator;
        typedef std::size_t size_type;

        size_type size() const {return avail - data;}

        iterator begin() {return data;}
        const_iterator begin() const {return data;}

        iterator end() {return avail;}
        const_iterator end() const {return avail;}

        Vec() {create();}
        explicit Vec(size_type n, const T& val) {create(n, val);}
        Vec(const Vec& v) {create(v.begin(), v.end());}

        Vec& operator=(const Vec&);

        ~Vec() {uncreate();}

        void push_back(const T& val) {
            if(avail == limit)
                grow();
            unchecked_append(val);
        }

        T operator[](size_type i) {return data[i];}

    private:
        iterator data;
        iterator avail;
        iterator limit;

        std::allocator<T> alloc;

        void create();
        void create(size_type, const T&);
        void create(const_iterator, const_iterator);

        void grow();
        void unchecked_append(const T&);
        void uncreate();
};

template <class T>
Vec<T>& Vec<T>::operator=(const Vec& rhs)
{
    //check if self assignment
    if(this != &rhs) {
        uncreate();
        create(rhs.begin(), rhs.end());
    }
    return *this;
}

template <class T>
void Vec<T>::create()
{
    data = avail = limit = 0;
}


template <class T>
void Vec<T>::create(size_type n, const T& val) {
    data = alloc.allocate(n);
    limit = avail = data + n;
    std::uninitialized_fill(data, limit, val);
}

template <class T>
void Vec<T>::create(const_iterator b, const_iterator e)
{
    data = alloc.allocate(e - b);
    limit = avail = std::uninitialized_copy(b, e, data);
}

template <class T>
void Vec<T>::uncreate()
{
    if(data) {
        iterator it = avail;
        while(it != data) 
            alloc.destroy(--it);

        alloc.deallocate(data, limit - data);
    }
    data = avail = limit = 0;
}

template <class T>
void Vec<T>::grow()
{
    size_type new_size = std::max(std::ptrdiff_t(1), 2 * (limit - data));

    iterator new_data = alloc.allocate(new_size);
    iterator new_avail = std::uninitialized_copy(data, avail, new_data);
    uncreate();

    data = new_data;
    avail = new_avail;
    limit = new_data + new_size;
}


template <class T>
void Vec<T>::unchecked_append(const T& val)
{
    alloc.construct(avail++, val);
}
