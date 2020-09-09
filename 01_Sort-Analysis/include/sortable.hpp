#ifndef SORTABLE_HPP
#define SORTABLE_HPP

#include <cstdio>
#include <iostream>

#include "stat.hpp"


template <typename T>
struct Sortable {

    T value;

    static Stat stat;


    static void reset();
    static void print_stat();

    Sortable();

    Sortable(T value);

    Sortable(const Sortable<T>& other);
    Sortable& operator=(const Sortable<T>& other);

    Sortable(Sortable<T>&& other);
    Sortable& operator=(Sortable<T>&& other);
};


template <typename T>
bool operator<(const Sortable<T>& a, const Sortable<T>& b);

template <typename T>
std::ostream& operator<<(std::ostream& out, const Sortable<T>& value);


//==============================================================================


template <typename T>
Stat Sortable<T>::stat = {0, 0};


template <typename T>
Sortable<T>::Sortable() : value(T()) {}


template <typename T>
Sortable<T>::Sortable(T val) : value(val) {}


template <typename T>
Sortable<T>::Sortable(const Sortable<T>& other) {
    ++stat.assign_cnt;
    value = other.value;
}


template <typename T>
Sortable<T>& Sortable<T>::operator=(const Sortable<T>& other) {
    if (&other == this) {
        return *this;
    }
    ++stat.assign_cnt;
    value = other.value;
    return *this;
}


template <typename T>
Sortable<T>::Sortable(Sortable<T>&& other) {
    ++stat.assign_cnt;
    value = std::move(other.value);
}


template <typename T>
Sortable<T>& Sortable<T>::operator=(Sortable<T>&& other) {
    ++stat.assign_cnt;
    value = std::move(other.value);
    return *this;
}


template <typename T>
void Sortable<T>::reset() {
    stat.assign_cnt  = 0;
    stat.compare_cnt = 0;
}


template <typename T>
void Sortable<T>::print_stat() {
    printf("%lu;%lu\n",
           stat.assign_cnt, stat.compare_cnt);
}


template <typename T>
bool operator<(const Sortable<T>& a, const Sortable<T>& b) {
    ++Sortable<T>::stat.compare_cnt;
    return (a.value < b.value);
}


template <typename T>
std::ostream& operator<<(std::ostream& out, const Sortable<T>& item) {
    out << item.value;
    return out;
}


#endif //SORTABLE_HPP
