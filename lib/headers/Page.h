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
/*!
    \class Page
    \brief Create a Page instance
    Create a Page instance as type of text or drawing page
    with respective content.
*/
class Page{
    public:
        char *text;
        GLint type;
        GLfloat x, y, z; /*!< Set x, y, z coordinates for Page */
        GLfloat width, height; /*!< Set width and height of a Page */
        GLfloat marginWidth, marginHeight; /*!< Set margin of the Page */
        GLfloat lineHeight, noOfLines, currentLine, lines[MAX_LINES];
        void (*pageContent)(GLfloat, GLfloat, GLfloat, GLfloat, GLfloat); /*!< Set function to be called for rendering a drawing page */
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