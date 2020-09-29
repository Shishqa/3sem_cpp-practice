#ifndef MAIN_WINDOW_HPP
#define MAIN_WINDOW_HPP


#include <cstddef>
#include <string_view>

#include "window.hpp"


namespace ShishGL {

    class MainWindow : public Window {
    public:

        MainWindow(const std::string_view& title, const Vector2<size_t>& size);

        void run();

        ~MainWindow() override = default;

    protected:

        const std::string_view title;

    };

}


#endif //MAIN_WINDOW_HPP
