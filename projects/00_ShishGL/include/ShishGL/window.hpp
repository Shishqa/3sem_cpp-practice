/*============================================================================*/
#ifndef SHISHGL_WINDOW_HPP
#define SHISHGL_WINDOW_HPP
/*============================================================================*/
#include "graphics/window/shaped_window.hpp"
#include "graphics/window/button.hpp"
#include "graphics/window/holdable_button.hpp"
#include "graphics/window/float.hpp"
#include "graphics/window/slider.hpp"
#include "ShishGL/graphics/shapes/rectangle.hpp"
/*============================================================================*/
namespace ShishGL {

    using RectWindow = ShapedWindow<Rectangle>;
    using RectButton = ShapedButton<Rectangle>;
    using RectHoldableButton = ShapedHoldableButton<Rectangle>;
    using RectFloat  = ShapedFloat<Rectangle>;
    using RectSlider = ShapedSlider<Rectangle>;

}
/*============================================================================*/
#endif //SHISHGL_WINDOW_HPP
/*============================================================================*/