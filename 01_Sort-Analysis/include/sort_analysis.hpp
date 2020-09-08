#ifndef ANALYSIS_HPP
#define ANALYSIS_HPP

#include "type_stat_wrap.hpp"
#include "sorting_data.hpp"

#include <vector>


template <typename T>
void fill_random(std::vector<T>& arr);


template <typename RandomIter>
SortingData analyse_sorting_func(void (*sorting_func)(RandomIter, RandomIter),
                                 const size_t& lower_arr_size,
                                 const size_t& upper_arr_size,
                                 const size_t& step) {

    std::vector<Stat<int>> array;
    array.reserve(upper_arr_size);

    for (size_t arr_size = lower_arr_size; arr_size <= upper_arr_size; arr_size += step) {

        array.resize(arr_size);

        printf("%lu;", arr_size);

        fill_random(array);
        // $D( print_array(data, arr_size); )

        Stat<int>::reset();

        sorting_func(array.begin(), array.end());
        //$D( print_array(data, arr_size); )

        Stat<int>::print_stat();
    }

    return SortingData();
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
