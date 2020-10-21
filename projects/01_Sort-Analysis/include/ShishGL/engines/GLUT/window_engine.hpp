/*============================================================================*/
#ifndef GLUT_WINDOW_ENGINE_HPP
#define GLUT_WINDOW_ENGINE_HPP
/*============================================================================*/

#include <string_view>
#include <cstddef>

#include "ShishGL/vector2.hpp"

/*============================================================================*/

namespace ShishGL {

    class Event;

    class GlutWindowEngine {
    public:

        using WIN_ID = int;

        static void init(int* argc_ptr, char** argv);

        static void enterMainLoop();

        static WIN_ID createWindow(
                const std::string_view& name,
                Vector2<int> position,
                Vector2<size_t> size
                );

        static WIN_ID createWindow(
                WIN_ID parent_id,
                Vector2<int> position,
                Vector2<size_t> size
                );

        static void destroyWindow(WIN_ID window_id);

        /*~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~*/

        static Event nextEvent();

        virtual ~GlutWindowEngine() = default;

    private:

        GlutWindowEngine() = default;

//        using EventQueue = std::queue<Event>;
//
//        static EventQueue& getEvents();

        static void manageOnIdle() {}

        static void manageOnRender() {}

        static void manageOnEntry(int) {}

        static void manageOnReshape(int, int) {}

        static void manageOnKeyPress(unsigned char, int, int) {}

        static void manageOnMouseClick(int, int, int, int) {}
    };

}

/*============================================================================*/
#endif //GLUT_WINDOW_ENGINE_HPP
/*============================================================================*/
