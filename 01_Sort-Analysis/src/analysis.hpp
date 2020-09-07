#ifndef ANALYSIS_HPP
#define ANALYSIS_HPP

#include "sorting_data.hpp"

#include <cstdlib>

SortingData analyze_sorting_func(void (*sorting_func)(int*, const size_t&),
                                      const size_t& lower_arr_size,
                                      const size_t& upper_arr_size,
                                      const size_t& step);

void fill_random(int* array, const size_t& array_size);

#endif //ANALYSIS_HPP
