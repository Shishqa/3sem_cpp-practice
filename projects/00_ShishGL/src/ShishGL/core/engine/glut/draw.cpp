/*============================================================================*/
#include <GL/freeglut.h>

#include "ShishGL/core/engines/glut/base.hpp"
/*============================================================================*/
using namespace ShishGL;
/*============================================================================*/

void GlutEngine::setColor(const Color& color) {
    glColor4ub(color.r, color.g, color.b, color.a);
}

/*----------------------------------------------------------------------------*/

void GlutEngine::fillBackground(const Color &color) {
    glClearColor(static_cast<float>(color.r) / 255.0f,
                 static_cast<float>(color.g) / 255.0f,
                 static_cast<float>(color.b) / 255.0f,
                 static_cast<float>(color.a) / 255.0f);
    glClear(GL_COLOR_BUFFER_BIT);
}

/*----------------------------------------------------------------------------*/

void GlutEngine::drawRectangle(const Vector2<int>& pos,
                               const Vector2<size_t>& size) {

    int width  = static_cast<int>(size.x),
        height = static_cast<int>(size.y);

    glBegin(GL_POLYGON);
        glVertex2i(pos.x,         pos.y);
        glVertex2i(pos.x + width, pos.y);
        glVertex2i(pos.x + width, pos.y + height);
        glVertex2i(pos.x,         pos.y + height);
    glEnd();

}

/*============================================================================*/
