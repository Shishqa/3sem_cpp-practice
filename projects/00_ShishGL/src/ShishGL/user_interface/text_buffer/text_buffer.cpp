/*============================================================================*/
#include <cassert>

#include "ShishGL/user_interface/text_buffer/text_buffer.hpp"
/*============================================================================*/
using namespace ShishGL;
/*============================================================================*/

TextBuffer::TextBuffer(Window *parent, const std::string_view& filename,
                       const Vector2<double>& size,
                       const Vector2<double>& pos)
    : RectWindow(parent, WHITE, size, pos)
    , text(filename)
    , curr_line_height(DEFAULT_FONT_HEIGHT)
    , scrollbar(nullptr)
    , curr_delta(0) {

    adjust();
}

/*----------------------------------------------------------------------------*/

double TextBuffer::stepSize() {
    return static_cast<double>(curr_line_height);
}

/*----------------------------------------------------------------------------*/

double TextBuffer::frameSize() {
    return static_cast<double>((text.lines().size() + 1) * curr_line_height) - size.y;
}

/*----------------------------------------------------------------------------*/

void TextBuffer::slide(double delta_in_pixels) {

    curr_delta += delta_in_pixels;
    if (curr_delta < 0) {
        curr_delta = 0;
    } else if (curr_delta > frameSize()) {
        curr_delta = frameSize();
    }
}

/*----------------------------------------------------------------------------*/

void TextBuffer::adjust() {

    if (frameSize() > size.y) {

        scrollbar = attach<Scrollbar>(
                this,
                DEFAULT_SCROLLBAR_COLORS,
                Vector2<double>{SCROLLBAR_WIDTH, size.y - SCROLLBAR_WIDTH},
                Vector2<double>{size.x - SCROLLBAR_WIDTH, 0}
                );

        printf("scrollbar height: %lg\n"
               "scrollbar step: %lg\n"
               "text height: %lg\n"
               "text step: %lg\n",
               scrollbar->frameSize(), scrollbar->stepSize(),
               frameSize(), stepSize());
    }

}

/*----------------------------------------------------------------------------*/

void TextBuffer::onRender() {

    RectWindow::onRender();

    assert(curr_line_height != 0);
    size_t curr_start = curr_delta / curr_line_height;
    size_t n_lines_to_render = size.y / curr_line_height;
    size_t curr_end = std::min(curr_start + n_lines_to_render, text.lines().size());

    Vector2<double> curr_pos = getAbsPos();
    const Vector2<double> delta{0, static_cast<double>(curr_line_height)};

    Engine::setColor(RED);
    for (size_t i = curr_start; i < curr_end; ++i) {

        Engine::displayText(text.lines()[i], curr_line_height, curr_pos);
        curr_pos += delta;

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
    if (scrollbar && !scrollbar->contains(event->where())) {

        auto n_steps = static_cast<int>(event->delta());

        scroll(n_steps);
        scrollbar->scroll(n_steps);

        return true;
    }
    return false;
}

/*============================================================================*/
