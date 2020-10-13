#ifndef GLUT_SYSTEM_HPP
#define GLUT_SYSTEM_HPP


#include <cstddef>
#include <string_view>
#include <queue>

#include "../vector2.hpp"
#include "../graphic_interface.hpp"


namespace ShishGL {

    class GlutSystem {
    public:

        using WIN_ID = int;
        
        static WIN_ID create_window(
                const std::string_view& name,
                Vector2<int> position,
                Vector2<size_t> size
                );

        static WIN_ID create_window(
                WIN_ID parent_id,
                Vector2<int> position,
                Vector2<size_t> size
                );

        static void destroy_window(WIN_ID window_id);

        /*~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~*/

        static Event* nextEvent();
        
    private:

        GlutSystem() = default;

        using EventQueue = std::queue<Event>;

        static EventQueue& getEvents();

        static void manageOnIdle();

        static void manageOnRender();

        static void manageOnEntry(int state);

        static void manageOnReshape(int width, int height);

        static void manageOnKeyPress(unsigned char key, int x, int y);

        static void manageOnMouseClick(int button, int state, int x, int y);
    };


}


#endif //GLUT_SYSTEM_HPP
