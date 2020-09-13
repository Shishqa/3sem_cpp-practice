#ifndef ANALYSIS_HPP
#define ANALYSIS_HPP


#include <vector>

#include "sortable.hpp"


template <typename T>
void fill_random(std::vector<T>& arr);


template <typename RandomIter>
Stat analyse_sorting_func(void (* sorting_func)(RandomIter, RandomIter),
                          const size_t& arr_size) {

    std::vector<Sortable<int>> array(arr_size);

    fill_random(array);

    Sortable<int>::reset();

    sorting_func(array.begin(), array.end());

    return Sortable<int>::stat;
}


template <typename T>
void fill_random(std::vector<T>& arr) {

    static const int MAX_INT_BOUND = 1024;
    srand(arr.size());

    for (auto& item : arr) {
        item = rand() % MAX_INT_BOUND;
    }
}


#endif //ANALYSIS_HPP
