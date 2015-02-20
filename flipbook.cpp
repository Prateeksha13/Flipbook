#include<iostream>
#include<stdlib.h>
#include<GL/glut.h>
#include "constants.h"
#include "Page.h"
#include "Book.h"
using namespace std;
void display()
{
    glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT );
    glColor3f(0.0,0.0,0.0);
    glPointSize(5.0);
    Page page1(PAGE_TYPE_TEXT);
    glColor3f(0.0,0.0,0.0);
    glFlush();
}
void initReshape()
{
    glViewport(0,0,PAGE_WIDTH,PAGE_HEIGHT);
    glClearColor(1.0,1.0,1.0,0.0);
    glMatrixMode(GL_PROJECTION);
    glLoadIdentity();
    glOrtho(-PAGE_WIDTH,PAGE_HEIGHT*2,-PAGE_HEIGHT,PAGE_WIDTH*2,-10.0,10.0);
    glMatrixMode(GL_MODELVIEW);
    glutPostRedisplay();
}
int main(int argc, char **argv)
{
    glutInit(&argc,argv);
    glutInitDisplayMode(GLUT_SINGLE | GLUT_RGB);
    glutInitWindowPosition(50,50);
    glutInitWindowSize(PAGE_WIDTH,PAGE_HEIGHT);
    glutCreateWindow("Notebook");
    initReshape();
    glutDisplayFunc(display);
    glEnable(GL_DEPTH_TEST);
    glutMainLoop();
}


