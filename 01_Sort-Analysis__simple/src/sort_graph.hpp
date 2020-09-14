#ifndef SORT_GRAPH_HPP
#define SORT_GRAPH_HPP

#include <cstddef>
#include <map>

#include "../include/openGL_util/color.hpp"
#include "sorting_wrap.hpp"

struct SortGraph {

    SortGraph() = delete;

    SortGraph(const SortingWrap& sort,
              const Color& color);

    void fill(const size_t& min_arr_size,
              const size_t& max_arr_size,
              const size_t& step);

    Stat operator[](const size_t& arr_size);

    Color line_color;

private:

    SortingWrap sort;

    size_t min_size,
           max_size,
           size_step;

    bool is_cache_valid;
    std::map<size_t, Stat> cache;

};

#endif //SORT_GRAPH_HPP
