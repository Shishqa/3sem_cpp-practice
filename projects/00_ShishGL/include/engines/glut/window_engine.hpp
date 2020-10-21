/*============================================================================*/
#ifndef GLUT_WINDOW_ENGINE_HPP
#define GLUT_WINDOW_ENGINE_HPP
/*============================================================================*/

#include <string_view>
#include <cstddef>

#include "../../vector2.hpp"

/*============================================================================*/

namespace ShishGL {

    class Event;

    class GlutWindowEngine {
    public:

        using WIN_ID = int;

        static constexpr WIN_ID ID_UNDEFINED = -1;

        static void init(int* argc_ptr, char** argv);

        static void enterMainLoop();

        static WIN_ID createWindow(
                const std::string_view& name,
                const Vector2<int>& position,
                const Vector2<size_t>& size
                );

        static WIN_ID createWindow(
                const WIN_ID& parent_id,
                const Vector2<int>& position,
                const Vector2<size_t>& size
                );

        static void destroyWindow(const WIN_ID& window_id);

        virtual ~GlutWindowEngine() = default;

    private:

        GlutWindowEngine() = default;

        static void setHandlers();

        static void manageIdle();

        static void manageRender();

        static void manageEntry(int state);

        static void manageReshape(int x, int y);

        static void manageKey(unsigned char key, int x, int y);

        static void manageMouse(int button, int state, int x, int y);

        static void manageMotion(int x, int y);

        static void managePassiveMotion(int x, int y);
    };

}

/*============================================================================*/
#endif //GLUT_WINDOW_ENGINE_HPP
/*============================================================================*/
