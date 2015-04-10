#include<iostream>
using namespace std;
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
        void init(GLint, GLfloat, GLfloat, GLfloat);
};
Page::Page(GLint type, GLfloat x, GLfloat y, GLfloat z, char text[])
{
    init(type, x, y, z);
    this->text=text;
}
Page::Page(GLint type, GLfloat x, GLfloat y, GLfloat z, void (*pageContent)(GLfloat, GLfloat, GLfloat, GLfloat, GLfloat))
{
    init(type, x, y, z);
    if(type == PAGE_TYPE_DRAWING)
    {
        this->pageContent = pageContent;
    }
}
void Page::init(GLint type, GLfloat x, GLfloat y, GLfloat z)
{
    this->x = x;
    this->y = y;
    this->z = z;
    this->type = type;
    this->width = PAGE_WIDTH;
    this->height = PAGE_HEIGHT;
    this->marginWidth = MARGIN_WIDTH;
    this->marginHeight = MARGIN_HEIGHT;
    this->lineHeight = LINE_HEIGHT;
    this->pageContent = NULL;
    this->text = NULL;

}
void Page::renderPage()
{
    glColor3f(0.0,0.0,0.0);
    setBorder();
    setMargin();
    if(type == PAGE_TYPE_TEXT && text != NULL)
        setPageLines();
    else if(type == PAGE_TYPE_DRAWING && pageContent != NULL)
        pageContent(x + marginWidth, y, z, x + width, y + height - marginHeight);
}
void Page::setBorder()
{
    glBegin(GL_LINE_LOOP);
    glVertex3f(x, y, z);
    glVertex3f(x + width, y, z);
    glVertex3f(x + width, y + height, z);
    glVertex3f(x, y + height, z);
    glEnd();
}
void Page::setMargin()
{
    glColor3f(0.0,0.0,0.0);
    glBegin(GL_LINE_LOOP);
    glVertex3f(x + marginWidth, y, z);
    glVertex3f(x + marginWidth, y + height, z);
    glEnd();
    glBegin(GL_LINES);
    glVertex2f(x, y + height - marginHeight);
    glVertex2f(x + width, x + height - marginHeight);
    glEnd();
}
void Page::setPageLines()
{
    /*
        Render Page Lines for the Page from the Margin where the line height is given
        by LINE_HEIGHT
    */
    int index=0;
    float pageBodyStartx = x + marginWidth;
    float pageBodyStarty = y + height - marginHeight;
    float pageBodyEndx = x + width;
    glColor3f(1.0,0.0,0.0);
    for(index=1;index<MAX_LINES && index<((pageBodyStarty-y)/(lineHeight));index++)
    {
        lines[index] = (pageBodyStarty - (LINE_HEIGHT * index));
        glBegin(GL_LINES);
        glVertex3f(pageBodyStartx, lines[index],0.0);
        glVertex3f(x + width, lines[index],0.0);
        glEnd();
    }
    glColor3f(0.0,0.0,0.0);
    noOfLines=index-1;
}
