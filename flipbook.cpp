#include<iostream>
#include<stdlib.h>
#include<stdio.h>
#include<GL/glut.h>
#include "constants.h"
#include "Book.h"
using namespace std;
int x;
float angle;
void test2(GLfloat x,GLfloat y, GLfloat z, GLfloat width, GLfloat height)
{
    glBegin(GL_LINE_LOOP);
    glVertex3f(x, y, z);
    glVertex3f(width, y, z);
    glVertex3f(width, height/2, z);
    glVertex3f(x,height/2,z);
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
    glLoadIdentity();
    gluLookAt(0,0,0,0,4,MAX_NO_PAGES,0,1,1);
    glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT );
    glColor3f(0.0,0.0,0.0);
    Book flipbook(0, 0, 0);
    flipbook.addPage(PAGE_TYPE_DRAWING,test);
    flipbook.addPage(PAGE_TYPE_TEXT,string);
    flipbook.addPage(PAGE_TYPE_DRAWING,test2);
    flipbook.renderBook();
    glPushMatrix();
    glLoadIdentity();
    glRotatef(angle,0,1.0,0.0);
    flipbook.renderPage(x);
    glFlush();
    glPopMatrix();
    glutSwapBuffers();
}
void rotate(){
    if(angle<=180)
    {
        angle += 2;
        glutPostRedisplay();
    }
    else{
        angle-=180;
    }
}
void initReshape(int w, int h)
{
    glViewport(0, 0, w, h);
    glClearColor(1.0,1.0,1.0,1.0);
    glMatrixMode(GL_PROJECTION);
    glLoadIdentity();
    //glFrustum(-WINDOW_WIDTH,WINDOW_WIDTH,-WINDOW_HEIGHT,WINDOW_HEIGHT,-20.0,20.0);
    if(w<=h)
        glOrtho(-WINDOW_WIDTH,WINDOW_WIDTH,-WINDOW_HEIGHT*(GLfloat)h/(GLfloat)w,WINDOW_HEIGHT*(GLfloat)h/(GLfloat)w,-MAX_NO_PAGES*BOOK_THICKNESS,MAX_NO_PAGES*BOOK_THICKNESS);
    else
        glOrtho(-WINDOW_WIDTH*(GLfloat)w/(GLfloat)h,WINDOW_WIDTH*(GLfloat)w/(GLfloat)h,-WINDOW_HEIGHT,WINDOW_HEIGHT,-MAX_NO_PAGES*BOOK_THICKNESS,MAX_NO_PAGES*BOOK_THICKNESS);

    glMatrixMode(GL_MODELVIEW);
    glutPostRedisplay();
}
void mykeyboard(unsigned char key, GLint x,GLint y)
{
    //glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT );
    if(key == 'z')
        x=0;
    if(key == 'x')
        x=1;
    if(key == 'c')
        x=2;
    //glutSwapBuffers();
    glutPostRedisplay();
}
void mymenu(int id)
{
    //glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT );
    if(id == 1)
        x=0;
    if(id == 2)
        x=1;
    if(id == 3)
        x=2;
    //glutSwapBuffers();
    glutPostRedisplay();
}
int main(int argc, char **argv)
{
    int menuid;
    glutInit(&argc,argv);
    glutInitDisplayMode(GLUT_DOUBLE | GLUT_RGB | GLUT_DEPTH);
    glutInitWindowPosition(50,50);
    glutInitWindowSize(WINDOW_WIDTH,WINDOW_HEIGHT);
    glutCreateWindow("FlipBook");
    glutReshapeFunc(initReshape);
    glutDisplayFunc(display);
    menuid=glutCreateMenu(mymenu);
    glutAddMenuEntry("page1",1);
    glutAddMenuEntry("page2",2);
    glutAddMenuEntry("page3",3);
    glutAttachMenu(GLUT_RIGHT_BUTTON);
    glutKeyboardFunc(mykeyboard);
    glutIdleFunc(rotate);
    glEnable(GL_DEPTH_TEST);
    glutMainLoop();
}
