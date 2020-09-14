#include "sort_graph.hpp"


SortGraph::SortGraph(const SortingWrap& sort,
                     const Color& color)
        : sort(sort)
        , line_color(color)
        , is_cache_valid(false) { }


Stat SortGraph::operator[](const size_t& arr_size) {

    if (is_cache_valid && cache.count(arr_size)) {
        return cache[arr_size];
    }

    printf("# dot recount\n");

    Stat stat = sort(arr_size);

    cache[arr_size] = stat;

    return stat;
}


void SortGraph::fill(const size_t& min_arr_size,
                     const size_t& max_arr_size,
                     const size_t& step) {

    if (min_arr_size == min_size &&
        max_arr_size == max_size &&
        size_step    == step &&
        is_cache_valid) {

        return;

    }

    printf("# cache recount\n");
    min_size  = min_arr_size;
    max_size  = max_arr_size;
    size_step = step;

    cache.clear();

    for (size_t size = min_arr_size; size <= max_arr_size; size += step) {

        cache[size] = sort(size);

    }

    is_cache_valid = true;

}