/*============================================================================*/
#ifndef SHISHGL_ENGINE_HPP
#define SHISHGL_ENGINE_HPP
/*============================================================================*/
#include <cstddef>

#include "engines/sfml/base.hpp"
/*============================================================================*/
namespace ShishGL {

    template <typename GraphicEngine>
    class GEngine : public GraphicEngine {
    private:
        GEngine() = default;

        /* giving roots for some classes */
        friend class EventSystem;
        friend class CoreApplication;

    public:
        virtual ~GEngine() = default;
    };

    /* SELECTED ENGINE */
    /*========================================================================*/
    using Engine = GEngine<SfmlEngine>;
    /*========================================================================*/

}
/*============================================================================*/
#endif //SHISHGL_ENGINE_HPP
/*============================================================================*/
