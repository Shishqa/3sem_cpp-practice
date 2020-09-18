#ifndef SORT_ANALYSER_APP_HPP
#define SORT_ANALYSER_APP_HPP


#include "../ShishGL/ShishGL.hpp"
using namespace ShishGL;

#include "Sorts/sorting_wrap.hpp"
#include "Sorts/sort_collection.hpp"

#include <algorithm>


namespace SortAnalyser {

    struct ButtonDescription {
        const char* name;
        int event_signal;
        Color color;
    };

    enum {
        CLEAR_SIGNAL = -100,
        NORMAL_RANGE,
        BIG_RANGE
    };

    const ButtonDescription UTIL_BUTTONS[] = {
            {"Clear",        CLEAR_SIGNAL, {WHITE, 255}},
            {"Normal rng", NORMAL_RANGE, {DARK_SEA_GREEN, 255}},
            {"Big range",    BIG_RANGE,    {FIRE_BRICK, 255}}
    };

    struct Sort {
        const char* name;
        SortingWrap stat_function;
        Color color;
    };

    const size_t MIN_ARRAY_SIZE = 0,
                 MAX_ARRAY_SIZE = 1000,
                 NUM_OF_DOTS    = 100,
                 STEP           = (MAX_ARRAY_SIZE - MIN_ARRAY_SIZE) / NUM_OF_DOTS;

    const Sort SORTS[] = {
        {"Bubble Sort", SortingWrap(bubble_sort, fill_random), {FIRE_BRICK,   255}},
        {"Merge Sort",  SortingWrap(merge_sort,  fill_random), {MEDIUM_AQUAMARINE, 255}},
        {"Std Sort",    SortingWrap(std::sort,   fill_random), {LAVENDER,  255}},
        {"Id (sort)",   SortingWrap(id_sort,     fill_random), {KHAKI, 255}}
    };

}


#endif //SORT_ANALYSER_APP_HPP
