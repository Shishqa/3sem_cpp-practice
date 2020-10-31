/*============================================================================*/
#include <cassert>

#include "ShishGL/user_interface/text_buffer/text_buffer.hpp"
/*============================================================================*/
using namespace ShishGL;
/*============================================================================*/

TextBuffer::TextBuffer(Window *parent, const std::string_view &filename,
                       const Vector2<int> &pos,
                       const Vector2<size_t> &size)
    : RectWindow(parent, WHITE, pos, size)
    , text(filename)
    , n_lines(0)
    , curr_line_height(DEFAULT_FONT_HEIGHT)
    , scrollbar(nullptr)
    , curr_delta(0) {

    adjust();
}

/*----------------------------------------------------------------------------*/

size_t TextBuffer::stepSize() {
    return curr_line_height;
}

/*----------------------------------------------------------------------------*/

size_t TextBuffer::getFrameSize() {
    return getSize().y;
}

/*----------------------------------------------------------------------------*/

size_t TextBuffer::getContentSize() {
    return text.lines().size() * curr_line_height;
}

/*----------------------------------------------------------------------------*/

void TextBuffer::slide(int delta) {
    curr_delta += delta;
    if (curr_delta < 0) {
        curr_delta = 0;
    } else if (static_cast<size_t>(curr_delta) > getContentSize() - size.y) {
        curr_delta = static_cast<size_t>(getContentSize() - size.y);
    }
}

/*----------------------------------------------------------------------------*/

void TextBuffer::adjust() {

    n_lines = std::min(size.y / curr_line_height, text.lines().size());

    if (n_lines < text.lines().size()) {

        scrollbar = attach<Scrollbar>(
                this,
                DEFAULT_SCROLLBAR_COLORS,
                Vector2<int>{static_cast<int>(size.x - SCROLLBAR_WIDTH), 0},
                Vector2<size_t>{SCROLLBAR_WIDTH, size.y - SCROLLBAR_WIDTH}
                );

    }

}

/*----------------------------------------------------------------------------*/

void TextBuffer::onRender() {

    RectWindow::onRender();

    assert(curr_line_height != 0);
    size_t curr_start = curr_delta / curr_line_height;

    Engine::setColor(RED);
    Vector2<int> curr_pos = getAbsPos();
    for (size_t i = curr_start; i < std::min(curr_start + n_lines, text.lines().size()); ++i) {

        Engine::displayText(text.lines()[i], curr_line_height, curr_pos);
        curr_pos += Vector2<int>{0, static_cast<int>(curr_line_height)};

    }

}

/*----------------------------------------------------------------------------*/

bool TextBuffer::filterEvent(const Event* event) {

    if (event->type() == Event::MOUSE_SCROLL) {

        auto converted = dynamic_cast<const MouseScrollEvent*>(event);
        if (!converted) {
            return false;
        }

        if (!contains(converted->where())) {
            return false;
        }
    }

    return true;
}

/*----------------------------------------------------------------------------*/

bool TextBuffer::onMouseScroll(const MouseScrollEvent* event) {
    if (scrollbar) {

        auto n_steps = static_cast<int>(event->delta());

        scroll(n_steps);

        if (scrollbar && !scrollbar->contains(event->where())) {
            scrollbar->scroll(n_steps);
        }

        return true;
    }
    return false;
}

/*============================================================================*/
