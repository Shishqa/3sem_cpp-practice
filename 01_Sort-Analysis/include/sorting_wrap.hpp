#ifndef SORTING_WRAP_HPP
#define SORTING_WRAP_HPP


#include <vector>

#include "sortable.hpp"


struct SortingWrap {

    using Iterator = std::vector<Sortable<int>>::iterator;

    SortingWrap() = delete;

    SortingWrap(void (*sort)(Iterator begin, Iterator end));

    Stat operator()(const size_t& arr_size);

    void set_func(void (*sort)(Iterator begin, Iterator end));

private:

    void (*sorting_function)(Iterator begin, Iterator end);
};


#endif //SORTING_WRAP_HPP
