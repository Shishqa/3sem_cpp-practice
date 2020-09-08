#ifndef STAT_HPP
#define STAT_HPP

#include <cstdio>
#include <iostream>


template <typename T>
struct Stat {

    T value;

    static size_t assign_cnt;
    static size_t compare_cnt;


    static void reset();
    static void print_stat();

    Stat();

    Stat(T value);

    Stat(const Stat<T>& other);
    Stat& operator=(const Stat<T>& other);

    Stat(Stat<T>&& other);
    Stat& operator=(Stat<T>&& other);
};


template <typename T>
bool operator<(const Stat<T>& a, const Stat<T>& b);

template <typename T>
std::ostream& operator<<(std::ostream& out, const Stat<T>& value);


//==============================================================================


template <typename T>
Stat<T>::Stat() : value(T()) {}


template <typename T>
Stat<T>::Stat(T value) : value(value) {}


template <typename T>
Stat<T>::Stat(const Stat<T>& other) {
    ++assign_cnt;
    value = other.value;
}


template <typename T>
Stat<T>& Stat<T>::operator=(const Stat<T>& other) {
    if (&other == this) {
        return *this;
    }
    ++assign_cnt;
    value = other.value;
    return *this;
}


template <typename T>
Stat<T>::Stat(Stat<T>&& other) {
    ++assign_cnt;
    value = std::move(other.value);
}


template <typename T>
Stat<T>& Stat<T>::operator=(Stat<T>&& other) {
    ++assign_cnt;
    value = std::move(other.value);
    return *this;
}


template <typename T>
size_t Stat<T>::assign_cnt = 0;


template <typename T>
size_t Stat<T>::compare_cnt = 0;


template <typename T>
void Stat<T>::reset() {
    assign_cnt  = 0;
    compare_cnt = 0;
}


template <typename T>
void Stat<T>::print_stat() {
    printf("%lu;%lu\n",
           assign_cnt, compare_cnt);
}


template <typename T>
bool operator<(const Stat<T>& a, const Stat<T>& b) {
    ++Stat<T>::compare_cnt;
    return (a.value < b.value);
}


template <typename T>
std::ostream& operator<<(std::ostream& out, const Stat<T>& stat) {
    out << stat.value;
    return out;
}


#endif //STAT_HPP
