/*============================================================================*/
#ifndef SHISHGL_WINDOW_HPP
#define SHISHGL_WINDOW_HPP
/*============================================================================*/
#include "window/shaped_window.hpp"
#include "window/shaped_button.hpp"
#include "window/shaped_float.hpp"
#include "ShishGL/shapes/rectangle.hpp"
/*============================================================================*/
namespace ShishGL {

    using RectWindow = ShapedWindow<Rectangle>;
    using RectButton = ShapedButton<Rectangle>;
    using RectFloat  = ShapedFloat<Rectangle>;

}
/*============================================================================*/
#endif //SHISHGL_WINDOW_HPP
/*============================================================================*/