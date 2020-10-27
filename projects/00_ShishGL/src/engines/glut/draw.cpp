/*============================================================================*/
#include <GL/freeglut.h>

#include "ShishGL/engines/glut/base.hpp"
/*============================================================================*/
using namespace ShishGL;
/*============================================================================*/

void GlutEngine::setColor(const Color& color) {
    glColor4ub(color.r, color.g, color.b, color.a);
}

/*----------------------------------------------------------------------------*/

void GlutEngine::fillWithColor(const Color& color) {
    glClearColor(static_cast<float>(color.r) / 255.0,
                 static_cast<float>(color.g) / 255.0,
                 static_cast<float>(color.b) / 255.0,
                 static_cast<float>(color.a) / 255.0);
    glClear(GL_COLOR_BUFFER_BIT);
}

/*----------------------------------------------------------------------------*/

void GlutEngine::drawRectangle(const Vector2<int>& pos,
                               const Vector2<size_t>& size) {

    glBegin(GL_POLYGON);
        glVertex2i(pos.x,          pos.y);
        glVertex2i(pos.x + size.x, pos.y);
        glVertex2i(pos.x + size.x, pos.y + size.y);
        glVertex2i(pos.x,          pos.y + size.y);
    glEnd();

}

/*============================================================================*/
