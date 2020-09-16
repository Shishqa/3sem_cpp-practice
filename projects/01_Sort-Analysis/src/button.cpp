#include <cstring>

#include "button.hpp"
#include "log.hpp"

using namespace ShishGL;


Button::Button(const char* button_label,
               const int& pos_x, const int& pos_y,
               const size_t& width, const size_t& height,
               const Color& default_color, const Color& hover_color,
               const Color& click_color)
        : Window(pos_x, pos_y, width, height)
        , label(button_label)
        , color_default(default_color)
        , color_hover(hover_color)
        , color_click(click_color)
        , color_current(default_color) {

    label_len = strlen(label);

    printLog("Button created");
}


Button::~Button() {
    printLog("Button deleted");
}


void Button::onRender() {

    glClearColor(color_current.r / 255.,
                 color_current.g / 255.,
                 color_current.b / 255.,
                 color_current.a / 255.);

    glClear(GL_COLOR_BUFFER_BIT);
    glMatrixMode(GL_MODELVIEW);
    glLoadIdentity();

    drawLabel();

    glutSwapBuffers();

}


void Button::onEntry(int state) {

    switch (state) {

        case GLUT_ENTERED:
            color_current = color_hover;
            break;

        case GLUT_LEFT:
            color_current = color_default;
            break;

        default:
            throw std::runtime_error("Error: unknown state of button passed\n");
    }

    glutPostRedisplay();

}


void Button::onMouseClick(int button, int state, int x, int y) {

    if (button != GLUT_LEFT_BUTTON) {
        return;
    }

    switch (state) {
        case GLUT_DOWN:
            color_current = color_click;
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

    static const int FONT_HEIGHT = 15,
                     FONT_WIDTH  = 9;

    int bitmap_width = FONT_WIDTH * label_len;

    glRasterPos2d( - static_cast<double>(bitmap_width) / info.width,
                   - static_cast<double>(FONT_HEIGHT)  / info.height);

    for(const char* curr_symbol = label; *curr_symbol != '\0'; ++curr_symbol) {

        glutBitmapCharacter(GLUT_BITMAP_9_BY_15, *curr_symbol);

    }


}

