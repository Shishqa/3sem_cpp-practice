#ifndef APPLICATION_HPP
#define APPLICATION_HPP


#include "sorting_wrap.hpp"
#include "sort_graph.hpp"
#include "../include/sorting_stat/sort_collection.hpp"
#include "../include/openGL_util/color.hpp"


enum {
    CLEAR = 0,
    BUBBLE_SORT = 1,
    MERGE_SORT  = 2,
    STD_SORT    = 3
};


void processMenu(int option);

void onRender();

void drawGraph(SortGraph& graph);

void onReshape(int width, int height);


#endif //APPLICATION_HPP
