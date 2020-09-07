#include "analysis.hpp"
#include "sorting_data.hpp"

#include "util/debug.hpp"

#include <iostream>
#include <cstdlib>
#include <ctime>


SortingData analyze_sorting_func(void (*sorting_func)(int*, const size_t&),
                          const size_t& lower_arr_size,
                          const size_t& upper_arr_size,
                          const size_t& step) {

    int* data = reinterpret_cast<int*>(::operator new(upper_arr_size * sizeof(*data) + 1));

    for (size_t arr_size = lower_arr_size; arr_size <= upper_arr_size; arr_size += step) {

        $D( std::cout << "size = " << arr_size << "\n"; )

        fill_random(data, arr_size);

        $D(
                std::cout << "\t[";
                for (size_t i = 0; i < arr_size; ++i) {
                    std::cout << data[i] << " ";
                    if ((i + 1) % step == 0) {
                        std::cout << "][ ";
                    }
                }
                std::cout << "\n";
        )

        sorting_func(data, arr_size);

        $D(
                std::cout << "\t[";
                for (size_t i = 0; i < arr_size; ++i) {
                    std::cout << data[i] << " ";
                    if ((i + 1) % step == 0) {
                        std::cout << "][ ";
                    }
                }
                std::cout << "\n";
        )

    }

    return SortingData();
}


void fill_random(int* arr, const size_t& arr_size) {

    static const int MAX_INT_BOUND = 1024;
    srand(arr_size);
    for (size_t i = 0; i < arr_size; ++i) {
        arr[i] = rand() % MAX_INT_BOUND;
    }
}
