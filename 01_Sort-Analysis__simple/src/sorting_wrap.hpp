#ifndef SORTING_WRAP_HPP
#define SORTING_WRAP_HPP


#include <vector>

#include "../include/sorting_stat/stat_wrap.hpp"


struct SortingWrap {

    using Iterator = std::vector<StatWrap<int>>::iterator;

    SortingWrap() = delete;

    SortingWrap(void (*sort)(Iterator begin, Iterator end),
                void (*fill_array)(Iterator begin, Iterator end));

    Stat operator()(const size_t& arr_size);

    void set_func(void (*sort)(Iterator begin, Iterator end));

private:

    void (*sorting_function)(Iterator begin, Iterator end);
    void (*fill_array)(Iterator begin, Iterator end);
};


#endif //SORTING_WRAP_HPP
