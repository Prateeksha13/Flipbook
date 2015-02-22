#include<iostream>
#include<stdlib.h>
#include<GL/glut.h>
#include "constants.h"
#include "Book.h"
using namespace std;
Book flipbook(-100, -100, 0);
void test2(GLfloat x,GLfloat y, GLfloat z, GLfloat width, GLfloat height)
{
    glBegin(GL_LINE_LOOP);
        glVertex3f(x, y, z);
        glVertex3f(width, y, z);
        glVertex3f((x + width)/2.0, height, z);
    glEnd();
}
void test(GLfloat x,GLfloat y, GLfloat z, GLfloat width, GLfloat height)
{
    glColor3f(0.0,0.0,1.0);
    glBegin(GL_LINE_LOOP);
        glVertex3f(x, y, z);
        glVertex3f(width, y, z);
        glVertex3f((x + width)/2.0, height, z);
    glEnd();
}
void display()
{
    char string[]="Hello";
    glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT );
    glColor3f(0.0,0.0,0.0);
    flipbook.addPage(PAGE_TYPE_DRAWING,test);
    flipbook.addPage(PAGE_TYPE_TEXT,string);
    flipbook.addPage(PAGE_TYPE_DRAWING,test2);
    flipbook.renderBook();
    flipbook.renderPage(2);
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


