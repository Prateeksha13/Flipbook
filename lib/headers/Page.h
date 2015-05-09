#ifndef _OPENGL_H
#define _OPENGL_H
#include <GL/glut.h>
#endif

#ifndef _CONSTANTS_H
#define _CONSTANTS_H
#include "../../config/Constants.h"
#endif

#ifndef _PAGE_H
#define _PAGE_H
#include <string.h>
class Page
{
    public:
        char *text;
        GLint type;
        GLfloat x, y, z;
        GLfloat width, height;
        GLfloat marginWidth, marginHeight;
        GLfloat lineHeight, noOfLines, currentLine, lines[MAX_LINES];
        void (*pageContent)(GLfloat, GLfloat, GLfloat, GLfloat, GLfloat);
        Page(GLint, GLfloat, GLfloat, GLfloat, char[]);
        Page(GLint, GLfloat, GLfloat, GLfloat, void (*)(GLfloat, GLfloat, GLfloat, GLfloat, GLfloat));
        void renderPage();
        void setMargin();
        void setPageLines();
        void setBorder();
        void renderText();
        void init(GLint, GLfloat, GLfloat, GLfloat);
};
void squareConstruction(GLint, GLint, GLint, GLint, GLfloat**);
void cubeConstruction(GLfloat, GLfloat, GLfloat, GLfloat, GLfloat, GLfloat);

#endif