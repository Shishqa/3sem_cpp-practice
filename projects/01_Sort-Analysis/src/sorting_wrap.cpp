#include <stdexcept>

#include "sorting_wrap.hpp"
#include "../include/sorting_stat/sort_analysis.hpp"


SortingWrap::SortingWrap(void (*sort)(Iterator, Iterator))
        : sorting_function(sort) {}


void SortingWrap::set_func(void (*sort)(Iterator, Iterator)) {
    if (!sort) {
        throw std::runtime_error("Passing NULL pointer to a function");
    }
    sorting_function = sort;
}


Stat SortingWrap::operator()(const size_t& arr_size) {
    if (!sorting_function) {
        throw std::runtime_error("Passing NULL pointer to a function");
    }
    return analyse_sorting_func(sorting_function, arr_size);
}
