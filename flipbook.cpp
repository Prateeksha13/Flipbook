#include<iostream>
#include<stdlib.h>
#include<GL/glut.h>
#include "constants.h"
#include "Book.h"
using namespace std;
void display()
{
    glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT );
    glColor3f(0.0,0.0,0.0);
    Book flipbook(-100, -100, 0);
    flipbook.addPage(PAGE_TYPE_TEXT);
    flipbook.addPage(PAGE_TYPE_DRAWING);
    flipbook.renderPage(1);
    glFlush();
    glutSwapBuffers();
}
void initReshape(int w, int h)
{
    glViewport(0, 0, w, h);
    glClearColor(1.0,1.0,1.0,1.0);
    glMatrixMode(GL_PROJECTION);
    glLoadIdentity();
    //glOrtho(-PAGE_WIDTH,PAGE_HEIGHT*2,-PAGE_HEIGHT,PAGE_WIDTH*2,-10.0,10.0);
    if(w<=h)
        glOrtho(-WINDOW_WIDTH,WINDOW_WIDTH,-WINDOW_HEIGHT*(GLfloat)h/(GLfloat)w,WINDOW_HEIGHT*(GLfloat)h/(GLfloat)w,-10.0,10.0);
    else
        glOrtho(-WINDOW_WIDTH*(GLfloat)w/(GLfloat)h,WINDOW_WIDTH*(GLfloat)w/(GLfloat)h,-WINDOW_HEIGHT,WINDOW_HEIGHT,-10.0,10.0);
    glMatrixMode(GL_MODELVIEW);
    glutPostRedisplay();
}
int main(int argc, char **argv)
{
    glutInit(&argc,argv);
    glutInitDisplayMode(GLUT_DOUBLE | GLUT_RGB | GLUT_DEPTH);
    glutInitWindowPosition(50,50);
    glutInitWindowSize(WINDOW_WIDTH,WINDOW_HEIGHT);
    glutCreateWindow("FlipBook");
    glutReshapeFunc(initReshape);
    glutDisplayFunc(display);
    glEnable(GL_DEPTH_TEST);
    glutMainLoop();
}


