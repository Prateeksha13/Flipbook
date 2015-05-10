#include "./headers/Book.h"

/*!
    \fn Book::Book(GLfloat x, GLfloat y, GLfloat z)
    \brief Constructor
    Constructor which initialises all the required data members for the class
*/
Book::Book(GLfloat x, GLfloat y, GLfloat z){
    this->x = x;
    this->y = y;
    this->z = z;
    this->width = BOOK_WIDTH;
    this->height = BOOK_HEIGHT;
    this->noOfPages = 0;
    this->pages = new Page*[MAX_NO_PAGES];
    this->currentPageIndex = 0;
}

/*!
    \fn Book::renderBook()
    \brief Render the book.
    Render the Book with the margin and border on the screen.
*/
void Book::renderBook(){
    int i=0;
    glColor3f(0.0,0.0,0.0);
    setBorder();
}

/*!
    \fn Book::setBorder()
    \brief Set Page Border
    Set the page border based on the size mentioned in the config/constants file.
    Render a 3d image for the book.
*/
void Book::setBorder(){
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

/*!
    \fn Book::addPage(GLint type, char s[])
    \brief Add a new Page
    Add a text page to the book by creating a new page from Page class and storing that as 
    a page in the created Book object.
    type -> Page type
    s -> String to be rendered onto the page
*/
void Book::addPage(GLint type, char s[]){
    pages[noOfPages] = new Page(type, (x + BOOK_BORDER_SIZE), y + BOOK_BORDER_SIZE, -(noOfPages * (PAGE_THICKNESS + PAGE_GAP)), s);
    noOfPages++;
}

/*!
    \fn Book::addPage(GLint type, void (*pageContent)(GLfloat, GLfloat, GLfloat, GLfloat, GLfloat))
    \brief Add a new Page
    Add a drawing page to the book by creating a new page from Page class and storing that as 
    a page in the created Book object.
    type -> Page type
    pageContent -> function pointer which renders the drawing inside the Page. 
*/
void Book::addPage(GLint type, void (*pageContent)(GLfloat, GLfloat, GLfloat, GLfloat, GLfloat)){
    pages[noOfPages] = new Page(type, (x + BOOK_BORDER_SIZE), y + BOOK_BORDER_SIZE, -(noOfPages * (PAGE_THICKNESS + PAGE_GAP)), pageContent);
    noOfPages++;
}

/*!
    \fn Book::renderPage()
    \brief Render the Page constructed
    Render the Page pointed by the currentPageIndex.
*/
void Book::renderPage(){
    pages[currentPageIndex]->renderPage();
}

/*!
    \fn Book::renderPage(GLint pageIndex)
    \brief Render the Page constructed
    Render the specified page in the book.
*/
void Book::renderPage(GLint pageIndex){
    if(pageIndex<noOfPages){
        pages[pageIndex]->renderPage();
    }
}