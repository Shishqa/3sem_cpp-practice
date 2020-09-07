#include "sorting_data.hpp"
#include "analysis.hpp"

#include "util/debug.hpp"

#include <iostream>
#include <cassert>


template <typename DataType>
void bubble_sort(DataType* array, const size_t& array_size);


int main() {

    $D( std::cout << "Running analyzer...\n"; )

    SortingData data = analyze_sorting_func(bubble_sort<int>, 10, 100, 10);

    $D( std::cout << "Displaying data:\n"; )

    return 0;
}


template <typename DataType>
void bubble_sort(DataType* array, const size_t& array_size) {

    assert(array);
    assert(array_size != 0);

    for (size_t i = 0; i < array_size; ++i) {
        for (size_t j = 0; j < array_size - i - 1; ++j) {
            if (array[j] > array[j + 1]) {
                std::swap(array[j], array[j + 1]);
            }
        }
    }

    return;

}
