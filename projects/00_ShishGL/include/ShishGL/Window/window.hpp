/*============================================================================*/
#ifndef SHISHGL_WINDOW_HPP
#define SHISHGL_WINDOW_HPP
/*============================================================================*/
#include "Window/abstracts/shaped_window.hpp"
#include "Window/abstracts/shaped_button.hpp"
#include "Window/abstracts/shaped_holdable_button.hpp"
#include "Window/abstracts/shaped_float.hpp"
#include "Window/abstracts/shaped_slider.hpp"
#include "ShishGL/geometry/shapes/rectangle.hpp"
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