#include "Page.h"
#include<iostream>
using namespace std;
class Book
{
    public:
    	GLfloat x, y, z;
        GLfloat width, height;
        GLint noOfPages, currentPageIndex;
        Page **pages;
        int **test;
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
	glPointSize(5.0);
	glBegin(GL_LINE_LOOP);
        glVertex3f(x, y, z);
        glVertex3f(x + width + BOOK_BORDER_SIZE, y, z);
        glVertex3f(x + width + BOOK_BORDER_SIZE, y + height + BOOK_BORDER_SIZE, z);
        glVertex3f(x, y + height + BOOK_BORDER_SIZE, z);
    glEnd();
}
void Book::addPage(GLint type, char s[])
{
	pages[noOfPages] = new Page(type, x + BOOK_BORDER_SIZE, y + BOOK_BORDER_SIZE, noOfPages, s);
	currentPageIndex = noOfPages++;
}
void Book::addPage(GLint type, void (*pageContent)(GLfloat, GLfloat, GLfloat, GLfloat, GLfloat))
{
    pages[noOfPages] = new Page(type, x + BOOK_BORDER_SIZE, y + BOOK_BORDER_SIZE, noOfPages, pageContent);
    currentPageIndex = noOfPages++;
}
void Book::renderPage()
{
	pages[currentPageIndex]->renderPage();
}
void Book::renderPage(GLint pageIndex)
{
	if(pageIndex<noOfPages)
		pages[pageIndex]->renderPage();
}