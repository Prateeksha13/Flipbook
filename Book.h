#include "Page.h"
#include<iostream>
using namespace std;

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
Book::Book(GLfloat x, GLfloat y, GLfloat z)
{
    this->x = x;
    this->y = y;
    this->z = z;
    this->width = BOOK_WIDTH;
    this->height = BOOK_HEIGHT;
    this->noOfPages = 0;
    this->pages = new Page*[MAX_NO_PAGES];
    this->currentPageIndex = 0;
    printf("\nBook");
    printf("\nBook x->%lf",x);
    printf("\nBook y->%lf",y);
    printf("\nBook z->%lf\n",z);
    fflush(stdout);
}
void Book::renderBook()
{
    int i=0;
    glColor3f(0.0,0.0,0.0);
    setBorder();
}
void Book::setBorder()
{
    glColor3f(0,0,0);
    GLfloat xLimit = x + width;
    GLfloat yLimit = y + height;
    GLfloat zLimit = z - BOOK_THICKNESS;
    printf("\nBook x1->%lf",xLimit);
    printf("\nBook y1->%lf",yLimit);
    printf("\nBook z1->%lf\n",zLimit);
    fflush(stdout);
    cubeConstruction(x, y, z, xLimit, yLimit, zLimit);
}
void Book::addPage(GLint type, char s[])
{
    pages[noOfPages] = new Page(type, (x + BOOK_BORDER_SIZE), y + BOOK_BORDER_SIZE, -(noOfPages * (PAGE_THICKNESS + PAGE_GAP)), s);
    noOfPages++;
}
void Book::addPage(GLint type, void (*pageContent)(GLfloat, GLfloat, GLfloat, GLfloat, GLfloat))
{
    pages[noOfPages] = new Page(type, (x + BOOK_BORDER_SIZE), y + BOOK_BORDER_SIZE, -(noOfPages * (PAGE_THICKNESS + PAGE_GAP)), pageContent);
    noOfPages++;
}
void Book::renderPage()
{
    //glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT );
    pages[currentPageIndex]->renderPage();
}
void Book::renderPage(GLint pageIndex)
{
    //glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT );
    if(pageIndex<noOfPages){
        pages[pageIndex]->renderPage();
    }
}