#include "Page.h"
#include<iostream>
using namespace std;

void boxConstruction(GLint a,GLint b,GLint c,GLint d,GLfloat vertices[][3])
{
    glBegin(GL_LINE_LOOP);
    glVertex3fv(vertices[a]);
    glVertex3fv(vertices[b]);
    glVertex3fv(vertices[c]);
    glVertex3fv(vertices[d]);
    glEnd();
}

class Book
{
    public:
        GLfloat x, y, z;
        GLfloat width, height;
        GLint noOfPages, currentPageIndex;
        Page **pages;
        Book(GLfloat, GLfloat, GLfloat);
        void addPage(GLint, char[]);
        void addPage(GLint, void (*)(GLfloat, GLfloat, GLfloat, GLfloat, GLfloat));
        void renderPage();
        void renderPage(GLint);
        void renderBook();
        void setBorder();
};
Book::Book(GLfloat x, GLfloat y, GLfloat z)
{
    this->x = x;
    this->y = y;
    this->z = z;
    this->width = BOOK_WIDTH;
    this->height = BOOK_HEIGHT;
    this->noOfPages = 0;
    this->pages = new Page*[MAX_NO_PAGES];
}
void Book::renderBook()
{
    glColor3f(0.0,0.0,0.0);
    setBorder();
}
void Book::setBorder()
{
    GLfloat xLimit = x + width + BOOK_BORDER_SIZE;
    GLfloat yLimit = y + height + BOOK_BORDER_SIZE;
    GLfloat zLimit = z - BOOK_THICKNESS;
    x = -x - width - 2*BOOK_BORDER_SIZE + 2*MARGIN_WIDTH;
    GLfloat vertices[][3]={
        {x, y, z}, {xLimit, y, z}, {xLimit, yLimit, z}, {x, yLimit, z},
        {x, y, zLimit}, {xLimit, y, zLimit}, {xLimit, yLimit, zLimit}, {x, yLimit, zLimit}
    };
    glPointSize(5.0);
    boxConstruction(0,3,2,1,vertices);
    boxConstruction(2,3,7,6,vertices);
    boxConstruction(0,4,7,3,vertices);
    boxConstruction(1,2,6,5,vertices);
    boxConstruction(4,5,6,7,vertices);
    boxConstruction(0,1,5,4,vertices);
}
void Book::addPage(GLint type, char s[])
{
    pages[noOfPages] = new Page(type, (x + BOOK_BORDER_SIZE), y + BOOK_BORDER_SIZE, noOfPages, s);
    currentPageIndex = noOfPages++;
}
void Book::addPage(GLint type, void (*pageContent)(GLfloat, GLfloat, GLfloat, GLfloat, GLfloat))
{
    pages[noOfPages] = new Page(type, (x + BOOK_BORDER_SIZE), y + BOOK_BORDER_SIZE, noOfPages, pageContent);
    currentPageIndex = noOfPages++;
}
void Book::renderPage()
{
    //glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT );
    renderBook();
    pages[currentPageIndex]->renderPage();
}
void Book::renderPage(GLint pageIndex)
{
    //glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT );
    //renderBook();
    if(pageIndex<noOfPages)
        pages[pageIndex]->renderPage();
}
