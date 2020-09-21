#ifndef MAIN_WINDOW_HPP
#define MAIN_WINDOW_HPP


#include <cstddef>

#include "window.hpp"


namespace ShishGL {

    class MainWindow : public Window {
    public:

        MainWindow(const char* title, const Vector2<size_t>& size);

        void run();

        ~MainWindow() override = default;

    protected:

        const char* title;

    };

}


#endif //MAIN_WINDOW_HPP
