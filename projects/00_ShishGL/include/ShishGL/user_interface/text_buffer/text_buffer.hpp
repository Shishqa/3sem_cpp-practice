/*============================================================================*/
#ifndef SHISHGL_TEXT_BUFFER_HPP
#define SHISHGL_TEXT_BUFFER_HPP
/*============================================================================*/
#include "ShishGL/text/text.hpp"
#include "ShishGL/window.hpp"
#include "ShishGL/ables/scrollable.hpp"
#include "ShishGL/user_interface/scrollbar/scrollbar.hpp"
/*============================================================================*/
namespace ShishGL {

    class TextBuffer : public RectWindow, public FrameScrollable {
    protected:

        static constexpr size_t DEFAULT_FONT_HEIGHT = 14;
        static constexpr size_t SCROLLBAR_WIDTH = 20;

        Text text;

        size_t curr_line_height;

        Object::ID scrollbar;
        double curr_delta;

    public:

        TextBuffer(Object::ID id, Object::ID parent, const std::string_view& filename,
                   const Vector2<double>& size,
                   const Vector2<double>& pos = {0, 0});

        ~TextBuffer() override = default;

        void slide(double delta_in_pixels) override;

        double stepSize() const override;

        double limitSize() const override;

        double frameSize() const override;

    protected:

        void adjust();

        /*--------------------------------------------------------------------*/

        bool filterEvent(const Event* event) override;

        bool onMouseScroll(const MouseScrollEvent* event) override;

        void onRender() override;
    };

}
/*============================================================================*/
#endif //SHISHGL_TEXT_BUFFER_HPP
/*============================================================================*/
