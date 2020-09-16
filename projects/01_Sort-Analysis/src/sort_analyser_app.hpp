#ifndef SORT_ANALYSER_APP_HPP
#define SORT_ANALYSER_APP_HPP

#include "main_window.hpp"


class SortAnalyserApp : public ShishGL::MainWindow {
public:

    SortAnalyserApp();

    virtual ~SortAnalyserApp();

private:

    void onRender() override;

};


#endif //SORT_ANALYSER_APP_HPP
