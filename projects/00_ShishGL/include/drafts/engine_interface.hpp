/*============================================================================*/
#ifndef SHISHGL_ENGINE_INTERFACE_HPP
#define SHISHGL_ENGINE_INTERFACE_HPP
/*============================================================================*/
#include <cstddef>

#include "../ShishGL/utility/color.hpp"
#include "../ShishGL/geometry/vector2.hpp"
#include "../ShishGL/core/event/base_event.hpp"
/*============================================================================*/
namespace ShishGL {

    /* TODO: inheritance? */

    class EngineInterface {

        /* Main */
        /*--------------------------------------------------------------------*/
        virtual bool initialize(int* argc_ptr, char* argv[]) = 0;

        virtual bool terminate() = 0;

        virtual Vector2<size_t> getDisplaySize() = 0;
        /*--------------------------------------------------------------------*/

        /* Events */
        /*--------------------------------------------------------------------*/
        virtual Event* pollEvent() = 0;
        /*--------------------------------------------------------------------*/

        /* Draw */
        /*--------------------------------------------------------------------*/
        virtual void setColor(const Color& color) = 0;

        virtual void fillBackground(const Color& color) = 0;

        virtual void drawRectangle(const Vector2<int>& pos,
                                   const Vector2<size_t>& size) = 0;
        /*--------------------------------------------------------------------*/
    };

}
/*============================================================================*/
#endif //SHISHGL_ENGINE_INTERFACE_HPP
/*============================================================================*/