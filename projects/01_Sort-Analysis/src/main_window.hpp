#ifndef MAIN_WINDOW_HPP
#define MAIN_WINDOW_HPP

#include <cstdio>
#include <cstddef>

#include "window.hpp"

namespace ShishGL {

    class MainWindow : public Window {
    public:

        MainWindow(const char* title, const size_t& width, const size_t& height);

        virtual ~MainWindow();

    protected:

        const char* title;

    };

}

#endif //MAIN_WINDOW_HPP
