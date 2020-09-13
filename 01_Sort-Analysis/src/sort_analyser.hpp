//
// Created by shishqa on 9/13/20.
//

#ifndef SORT_ANALYSER_HPP
#define SORT_ANALYSER_HPP


#include "../include/openGL_util/application.hpp"


class SortAnalyser : public Application {
public:

    SortAnalyser();

    virtual ~SortAnalyser() { }

private:

    virtual void onRender() override;

    virtual void onReshape(int, int) override;

    virtual void onKeyPress(unsigned char, int, int) override;

    virtual void onMouseClick(int, int, int, int) override;

};


#endif //SORT_ANALYSER_HPP
