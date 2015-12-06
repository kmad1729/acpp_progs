/* question: Add an operation to remove and element from a Vec and another to 
 * empty the entire Vec. These should behave analogously to the erase and clear 
 * operations on vectors.
 */

#include <algorithm>
#include <memory>

template <class T>
class Vec {
    public:
        typedef T value_type;
        typedef T& reference;
        typedef const T& const_reference;
        typedef ptrdiff_t difference_type;
        
        typedef size_t size_type;

        typedef T* iterator;
        typedef const T* const_iterator;

        size_type size() const {return avail - data;}

        iterator begin() {return data;}
        const_iterator begin() const {return data;}

        iterator end() {return avail;}
        const_iterator end() const {return avail;}

        Vec() {create();} //default
        explicit Vec(size_type n, const T& val = T()) {create(n, val);} //replication
        Vec(const Vec& v) {create(v.begin(), v.end());} //copy constructor
        Vec& operator= (const Vec&); //assignment

        ~Vec() {uncreate();} // destructor

        void push_back(const T& val) {
            if(avail == limit)
                grow();
            unchecked_append(val);
        }

        void clear() {uncreate(); data = avail = limit = 0;};

        iterator erase(iterator);

    private:
        iterator data;
        iterator avail;
        iterator limit;

        //managing memory
        std::allocator<T> alloc;

        void create();
        void create(size_type, const T&);
        void create(const_iterator, const_iterator);

        void uncreate();

        void grow();
        void unchecked_append(const T&);

};

template <class T> 
Vec<T>& Vec<T>::operator= (const Vec& rhs) {
    //checking for self assignment
    if(this != &rhs) {
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
    std::uninitialized_fill(data, avail, val);
}

template <class T>
void Vec<T>::create(const_iterator i, const_iterator j) {
    data = alloc.allocate(j - i);
    avail = limit = std::uninitialized_copy(i, j, data);
}

template <class T>
void Vec<T>::uncreate() {
    if(data) {
        iterator it = avail;
        while(it != data)
            alloc.destroy(--it);
        alloc.deallocate(data, limit - data);
    }
}

template <class T>
void Vec<T>::grow() {
    size_type new_size = std::max(2 * (limit - data), ptrdiff_t(1));
    iterator new_data = alloc.allocate(new_size);
    iterator new_avail = std::uninitialized_copy(data, limit, new_data);

    uncreate();

    data = new_data;
    avail = new_avail;
    limit = data + new_size;
}

template <class T>
void Vec<T>::unchecked_append(const T& val) {
    alloc.construct(avail++, val);
}

template <class T>
typename Vec<T>::iterator Vec<T>::erase(iterator i) {
    size_type result_pos = i - data;
    avail = std::uninitialized_copy(i + 1, avail, i);
    return data + result_pos;

}
