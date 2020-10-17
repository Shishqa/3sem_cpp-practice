#include "ShishGL/ShishGL.hpp"


int main(int argc, char* argv[]) {

    ShishGL::Application::init(&argc, argv);

    ShishGL::Application::display<ShishGL::Window>(
            ShishGL::Vector2<size_t>{400, 400}
            );

    ShishGL::Application::display<ShishGL::Window>(
            ShishGL::Vector2<size_t>{400, 400}
    );

    return ShishGL::Application::run();
}
