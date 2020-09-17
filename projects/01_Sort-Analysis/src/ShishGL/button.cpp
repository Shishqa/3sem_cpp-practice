#include <cstring>

#include "ShishGL/button.hpp"
#include "ShishGL/log.hpp"

using namespace ShishGL;


Button::Button(const char* button_label, const Event& click_event,
               const int& pos_x, const int& pos_y,
               const size_t& width, const size_t& height,
               const Color& default_color,
               const Color& hover_color,
               const Color& click_color)
        : Window(pos_x, pos_y, width, height)
        , on_click(click_event)
        , label(button_label)
        , color_current(default_color)
        , color_default(default_color)
        , color_hover(hover_color)
        , color_click(click_color) {

    label_len = strlen(label);

    printLog("Button created");
}


void Button::onRender() {

    fillWithColor(color_current);

    glMatrixMode(GL_MODELVIEW);
    glLoadIdentity();

    drawLabel();

    glutSwapBuffers();

}


void Button::onEntry(int state) {

    if (state == GLUT_ENTERED) {
        color_current = color_hover;
    } else {
        color_current = color_default;
    }

    glutPostRedisplay();

}


void Button::onMouseClick(int button, int state, int, int) {

    if (button != GLUT_LEFT_BUTTON) {
        return;
    }

    switch (state) {
        case GLUT_DOWN:
            color_current = color_click;
            generateEvent(on_click);
            break;

        case GLUT_UP:
            color_current = color_hover;
            break;

        default:
            throw std::runtime_error("Error: unknown state of mouse button\n");
    }

    glutPostRedisplay();
}


void Button::drawLabel() {

    glColor4ub(0, 0, 0, 1);

    static const size_t FONT_HEIGHT = 15,
                        FONT_WIDTH  = 9;

    size_t bitmap_width = FONT_WIDTH * label_len;

    glRasterPos2d( - static_cast<double>(bitmap_width) / static_cast<double>(info.width),
                   - static_cast<double>(FONT_HEIGHT)  / static_cast<double>(info.height));

    for(const char* curr_symbol = label; *curr_symbol != '\0'; ++curr_symbol) {

        glutBitmapCharacter(GLUT_BITMAP_9_BY_15, *curr_symbol);

    }


}

