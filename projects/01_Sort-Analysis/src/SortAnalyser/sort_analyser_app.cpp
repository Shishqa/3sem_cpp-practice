#include "SortAnalyser/sort_analyser_app.hpp"

using namespace SortAnalyser;


const std::vector<SortAnalyser::Sort>& SortAnalyser::Sorts() {
    static const std::vector<Sort> SORTS {
        {"Bubble Sort", SortingWrap(bubble_sort, fill_random), FIRE_BRICK},
        {"Merge Sort",  SortingWrap(merge_sort,  fill_random), MEDIUM_AQUAMARINE},
        {"Std Sort",    SortingWrap(std::sort,   fill_random), LAVENDER},
        {"Id (sort)",   SortingWrap(id_sort,     fill_random), KHAKI}
    };

    return SORTS;
}
