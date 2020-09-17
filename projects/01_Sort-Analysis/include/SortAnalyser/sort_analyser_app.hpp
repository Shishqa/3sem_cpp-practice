#ifndef SORT_ANALYSER_APP_HPP
#define SORT_ANALYSER_APP_HPP


#include "../ShishGL/ShishGL.hpp"
using namespace ShishGL;

#include "Sorts/sorting_wrap.hpp"
#include "Sorts/sort_collection.hpp"

#include <algorithm>


namespace SortAnalyser {

    enum {
        CLEAR_SIGNAL = -1
    };

    struct Sort {
        const char* name;
        SortingWrap stat_function;
        Color color;
    };

    static const Sort SORTS[] = {
        {"Bubble Sort", SortingWrap(bubble_sort, fill_random), {RED,   255}},
        {"Merge Sort",  SortingWrap(merge_sort,  fill_random), {GREEN, 255}},
        {"Std Sort",    SortingWrap(std::sort,   fill_random), {BLUE,  255}},
        {"Id (sort)",   SortingWrap(id_sort,     fill_random), {WHITE, 255}}
    };

}


#endif //SORT_ANALYSER_APP_HPP
