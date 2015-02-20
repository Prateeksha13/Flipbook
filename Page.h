class Page
{
    public:
        GLfloat width;
        GLfloat height;
        GLfloat noOfLines;
        GLint type;
        GLfloat currentLine;
        GLfloat lines[MAX_LINES];
        Page(GLint);
        void renderPage();
        void setMargin();
        void setPageLines();
};
Page::Page(GLint type)
{
    this->type = type;
    renderPage();
    setMargin();
    if(type == PAGE_TYPE_TEXT)
        setPageLines();
}
void Page::renderPage()
{
    glBegin(GL_LINE_LOOP);
        glVertex3f(0.0,0.0,0.0);
        glVertex3f(PAGE_WIDTH,0.0,0.0);
        glVertex3f(PAGE_WIDTH,PAGE_HEIGHT,0.0);
        glVertex3f(0.0,PAGE_HEIGHT,0.0);
    glEnd();
}
void Page::setMargin()
{
    glBegin(GL_LINE_LOOP);
        glVertex3f(MARGIN_WIDTH,0,0.0);
        glVertex3f(MARGIN_WIDTH,PAGE_HEIGHT,0.0);
    glEnd();
    glBegin(GL_LINES);
        glVertex2f(0, PAGE_HEIGHT - MARGIN_HEIGHT);
        glVertex2f(PAGE_HEIGHT, PAGE_HEIGHT - MARGIN_HEIGHT);
    glEnd();
}
void Page::setPageLines()
{
    /*
        Render Page Lines for the Page from the Margin where the line height is given
        by LINE_HEIGHT
    */
    int index=0;
    float pageBodyStartx = MARGIN_WIDTH;
    float pageBodyStarty = PAGE_HEIGHT - MARGIN_HEIGHT;
    float pageBodyEndx = PAGE_WIDTH; 
    glColor3f(1.0,0.0,0.0);
    for(index=1;index<MAX_LINES && index<(pageBodyStarty)/LINE_HEIGHT;index++)
    {
        lines[index] = (pageBodyStarty- (LINE_HEIGHT * index));
        glBegin(GL_LINES);
            glVertex3f(pageBodyStartx,lines[index],0.0);
            glVertex3f(PAGE_WIDTH,lines[index],0.0);
        glEnd();
    }
    noOfLines=index-1; 
}