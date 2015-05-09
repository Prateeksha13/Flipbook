#include "./headers/Book.h"

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
    cubeConstruction(x, y, z, xLimit, yLimit, zLimit);
    glColor3f(1,1,1);
    glBegin(GL_POLYGON);
        glVertex3f(x, y, zLimit);
        glNormal3f(x, y, zLimit);
        glVertex3f(xLimit, y, zLimit);
        glNormal3f(xLimit, y, zLimit);
        glVertex3f(xLimit, yLimit, zLimit);
        glNormal3f(xLimit, yLimit, zLimit);
        glVertex3f(x, yLimit, zLimit);
        glNormal3f(x, yLimit, zLimit);
    glEnd();
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
    pages[currentPageIndex]->renderPage();
}
void Book::renderPage(GLint pageIndex)
{
    if(pageIndex<noOfPages){
        pages[pageIndex]->renderPage();
    }
}