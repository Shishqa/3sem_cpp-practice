#ifndef PLOT_HPP
#define PLOT_HPP

#include <vector>   // bad?
using std::vector;


template <typename DataType>
struct PlotDot {
    DataType x;
    DataType y;
};


template <typename DataType>
struct Plot {
    vector<PlotDot<DataType>> dots;

    void display();
};


#endif //PLOT_HPP
