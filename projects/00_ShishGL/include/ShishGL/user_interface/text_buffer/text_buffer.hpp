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

        size_t n_lines;
        size_t curr_line_height;

        Scrollbar* scrollbar;
        int curr_delta;

    public:

        TextBuffer(Window* parent, const std::string_view& filename,
                   const Vector2<int>& pos, const Vector2<size_t>& size);

        ~TextBuffer() override = default;

        void slide(int delta) override;

        size_t stepSize() override;

        size_t getFrameSize() override;

        size_t getContentSize() override;

    protected:

        bool filterEvent(const Event* event) override;

        bool onMouseScroll(const MouseScrollEvent* event) override;

        void adjust();

        void onRender() override;
    };

}
/*============================================================================*/
#endif //SHISHGL_TEXT_BUFFER_HPP
/*============================================================================*/
