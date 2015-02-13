#include<GL/glut.h>
#define marginHeight 60
#define marginWidth 70
#define pageHeight 600
#define pageWidth 600
#define maxRows 30
#define maxCols 30
#define dx 30
GLfloat x[maxRows]={0,0};
GLfloat y[maxCols]={0,0};
void init()
{
    glClearColor(1.0,1.0,1.0,0.0);
    glMatrixMode(GL_PROJECTION);
    gluOrtho2D(0.0,pageHeight,0.0,pageWidth);
}
void setMargin()
{
    glBegin(GL_LINES);
        glVertex2f(marginWidth,0);
        glVertex2f(marginWidth,pageHeight);
    glEnd();
    glBegin(GL_LINES);
        glVertex2f(0, pageHeight - marginHeight);
        glVertex2f(pageHeight, pageHeight - marginHeight);
    glEnd();
}
 void setPageLines()
{
    int index=0;
    int noOfLines=0;
    float pageBodyStartx = marginWidth;
    float pageBodyStarty = pageHeight - marginHeight;
    float pageBodyEndx = pageWidth; 
    glColor3f(1.0,0.0,0.0);
    for(index=1;index<maxRows;index++)
    {
        y[index] = (pageBodyStarty- (dx * index));
        glBegin(GL_LINES);
            glVertex2f(pageBodyStartx,y[index]);
            glVertex2f(pageWidth,y[index]);
        glEnd();
    }
    noOfLines=index; 

} 
void display()
{
    glClear(GL_COLOR_BUFFER_BIT);
    glColor3f(0.0,0.0,0.0);
    glPointSize(5.0);
    setMargin();
    setPageLines(); 
    glColor3f(0.0,0.0,0.0);
    /*
    glBegin(GL_LINE_LOOP);
        glVertex2f(150,150);
        glVertex2f(250,150);
        glVertex2f(200,200);
    glEnd();
    */
    glFlush();
}
int main(int argc, char **argv)
{
    glutInit(&argc,argv);
    glutInitDisplayMode(GLUT_SINGLE | GLUT_RGB);
    glutInitWindowPosition(50,50);
    glutInitWindowSize(pageWidth,pageHeight);
    glutCreateWindow("Page");
    init();
    glutDisplayFunc(display);
    glutMainLoop();
}
