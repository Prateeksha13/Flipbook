#include "Page.h"
class Book
{
    public:
    	GLfloat x, y, z;
        GLfloat width, height;
        GLint noOfPages, currentPageIndex;
        Page **pages;
        Book(GLfloat, GLfloat, GLfloat);
        void addPage(GLint);
        void renderPage();
        void renderPage(GLint);
};
Book::Book(GLfloat x, GLfloat y, GLfloat z)
{
	this->x = x;
	this->y = y;
	this->z = z;
	this->noOfPages = 0;
}
void Book::addPage(GLint type)
{
	pages[noOfPages]=new Page(type, x + BOOK_BORDER_SIZE, y + BOOK_BORDER_SIZE, noOfPages);
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