#include<GL/glut.h>
#define marginHeight 60
#define marginWidth 70
#define pageHeight 600
#define pageWidth 600
#define maxRows 30
#define maxCols 30
#define lineWidth 30
GLfloat x[maxRows]={0,0};
GLfloat y[maxCols]={0,0};
void initReshape()
{
    glViewport(0,0,pageWidth,pageHeight);
    glClearColor(1.0,1.0,1.0,0.0);
    glMatrixMode(GL_PROJECTION);
    glLoadIdentity();
    glOrtho(-pageWidth,pageHeight*2,-pageHeight,pageWidth*2,-10.0,10.0);
    glMatrixMode(GL_MODELVIEW);
    glutPostRedisplay();
}

void setMargin()
{
    glBegin(GL_LINE_LOOP);
        glVertex3f(0.0,0.0,0.0);
        glVertex3f(pageWidth,0.0,0.0);
        glVertex3f(pageWidth,pageHeight,0.0);
        glVertex3f(0.0,pageHeight,0.0);
    glEnd();
    glBegin(GL_LINE_LOOP);
        glVertex3f(0.0,-10.0,-2.0);
        glVertex3f(pageWidth,-10.0,-2.0);
        glVertex3f(pageWidth,pageHeight,-2.0);
        glVertex3f(0.0,pageHeight,-2.0);
    glEnd();
 glBegin(GL_LINE_LOOP);
        glVertex3f(marginWidth,0,0.0);
        glVertex3f(marginWidth,pageHeight,0.0);
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
    for(index=1;index<maxRows && index<(pageBodyStarty)/lineWidth;index++)
    {
        y[index] = (pageBodyStarty- (lineWidth * index));
        glBegin(GL_LINES);
            glVertex3f(pageBodyStartx,y[index],0.0);
            glVertex3f(pageWidth,y[index],0.0);
        glEnd();
    }
    noOfLines=index; 

} 
void display()
{
    glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT );
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
    glutCreateWindow("Notebook");
    initReshape();
    glutDisplayFunc(display);
    glEnable(GL_DEPTH_TEST);
    glutMainLoop();
}
