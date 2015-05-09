#ifndef _OPENGL_H
#define _OPENGL_H
#include <GL/glut.h>
#endif

#ifndef _CONSTANTS_H
#define _CONSTANTS_H
#include "../../config/Constants.h"
#endif

#ifndef _BOOK_H
#define _BOOK_H
#include "./Page.h"
class Book
{
    public:
        GLfloat x, y, z;
        GLfloat width, height;
        GLint noOfPages, currentPageIndex, destinationPageIndex;
        Page **pages;
        Book(GLfloat, GLfloat, GLfloat);
        void addPage(GLint, char[]);
        void addPage(GLint, void (*)(GLfloat, GLfloat, GLfloat, GLfloat, GLfloat));
        void renderPage();
        void renderPage(GLint);
        void renderBook();
        void setBorder();
};
#endif