#include <stdio.h>
#include <GL/glut.h>
#include <IL/il.h>
#include "constants.h"
#include "Book.h"
#include "Drawings.h"
#include "Textures.h"
#include "Room.h"
using namespace std;
GLint pageId;
GLfloat angle, limit;
GLint flipId;
GLint viewId;

void selectFlippingPageType()
{
    if(flipId == 0){
        limit=270;
        glRotatef(angle,0.0,-1.0,0.0);
    }
    else if(flipId == 1){
        limit = 320;
        glRotatef(angle,-1.0,-1.0,0.0);
    }
    else if(flipId == 2){
        limit=350;
        glRotatef(angle,-1.0,-0.0,0.0);
    }
    else if(flipId == 3){
        limit=340;
        glRotatef(angle,-1.0,0.0,-1.0);
    }
}

void selectViewingAngle()
{
    if(viewId == 0){
        gluLookAt(0,0,100,0,0,0,0,50,0);
    }
    else if(viewId == 1){
        gluLookAt(-20,10,50,0,0,0,0,10,0);
    }
    else if(viewId == 2){
        gluLookAt(0,0,0,20,0,-50,0,50,0);
    }
    else if(viewId == 3){
        //glRotatef(angle,-1.0,0.0,-1.0);
        limit=0;
        gluLookAt(-500,0,100,0,0,0,0,80,0);
        glRotatef(angle,0.0,-1.0,-1.0);
    }
}
void flipPage(){
    if(angle<=limit)
        angle += 2;
    else{
        angle-=limit;
        pageId = (pageId + 1)%6;
    }
}

void idleStateExecute()
{
    flipPage();
    glutPostRedisplay();
}

void display()
{
    char string[]="Hello my name is kshitij karthick testing\n Hey\n hey";
    glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT );
    glLoadIdentity();
    selectViewingAngle();
    drawRoom();
    glPushMatrix();
        glTranslatef(-100,-100,0);
        Book flipbook(0, 0, 0);
        flipbook.addPage(PAGE_TYPE_DRAWING,triangle);   
        flipbook.addPage(PAGE_TYPE_DRAWING,square); 
        flipbook.addPage(PAGE_TYPE_TEXT,string);
        flipbook.addPage(PAGE_TYPE_DRAWING,triangle);   
        flipbook.addPage(PAGE_TYPE_DRAWING,square);
        glColor3f(0,0,0);
        flipbook.renderBook();
        glPushMatrix();
            glTranslatef(0,PAGE_HEIGHT+BOOK_BORDER_SIZE,0);
            selectFlippingPageType();
            glTranslatef(0,-PAGE_HEIGHT-BOOK_BORDER_SIZE,0);
            flipbook.renderPage(pageId);
            glFlush();
        glPopMatrix();
        flipbook.renderPage(pageId+1);
        glColor3f(0,0,0);
        glFlush();
    glPopMatrix();
    glutSwapBuffers();
}

void initReshape(int w, int h)
{
    glViewport(0, 0, w, h);
    glClearColor(0.0,0.0,0.0,1.0);
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
    glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT );
    if(key == '+')
        pageId = ( pageId + 1 ) % 6;
    if(key == '-')
        pageId = ( pageId - 1 ) % 6;
    glutPostRedisplay();
}
void mymenu(int id)
{
    glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT );
    if(id == 1)
        pageId = ( pageId + 1 ) % 6;
    else if(id == 2)
        pageId = ( pageId + 1 ) % 6;
    else if(id == 3)
        flipId=0;
    else if(id == 4)
        flipId=1;
    else if(id == 5)
        flipId=2;
    else if(id == 6)
        flipId=3;
    else if(id == 7)
        viewId=0;
    else if(id == 8)
        viewId=1;
    else if(id == 9)
        viewId=2;
    else if(id == 10)
        viewId=3;
    glutPostRedisplay();
}
int main(int argc, char **argv)
{
    ILuint image;
    int menuid;
    char filename[]="wall.jpg";
    glutInit(&argc,argv);
    glutInitDisplayMode(GLUT_DOUBLE | GLUT_RGB | GLUT_DEPTH);
    glutInitWindowPosition(50,50);
    glutInitWindowSize(WINDOW_WIDTH,WINDOW_HEIGHT);
    glutCreateWindow("FlipBook");
    glutReshapeFunc(initReshape);
    glutDisplayFunc(display);
    image = LoadImage(filename);
    loadTextures(texid);
    menuid=glutCreateMenu(mymenu);
    glutAddMenuEntry("Next Page",1);
    glutAddMenuEntry("Previous Page",2);
    glutAddMenuEntry("Flip1",3);
    glutAddMenuEntry("Flip2",4);
    glutAddMenuEntry("Flip3",5);
    glutAddMenuEntry("Flip4",6);
    glutAddMenuEntry("View1",7);
    glutAddMenuEntry("View2",8);
    glutAddMenuEntry("View3",9);
    glutAddMenuEntry("View4",10);
    glutAttachMenu(GLUT_RIGHT_BUTTON);
    glutKeyboardFunc(mykeyboard);
    glutIdleFunc(idleStateExecute);
    glEnable(GL_DEPTH_TEST);

    glutMainLoop();
}
void welcome()
{
    glPushMatrix();
    glLoadIdentity();
    glTranslatef(-200,-200,0);
    glScalef(1.5,1.5,1.5);
    glRasterPos2f(-80, -80);
    glutStrokeCharacter(GLUT_STROKE_ROMAN, 'H');
    glutStrokeCharacter(GLUT_STROKE_ROMAN, 'e');
    glutStrokeCharacter(GLUT_STROKE_ROMAN, 'l');
    glutStrokeCharacter(GLUT_STROKE_ROMAN, 'l');
    glutStrokeCharacter(GLUT_STROKE_ROMAN, 'o');
    glutStrokeCharacter(GLUT_STROKE_ROMAN, 'W');
    glutStrokeCharacter(GLUT_STROKE_ROMAN, 'o');
    glutStrokeCharacter(GLUT_STROKE_ROMAN, 'r');
    glutStrokeCharacter(GLUT_STROKE_ROMAN, 'l');
    glutStrokeCharacter(GLUT_STROKE_ROMAN, 'd');
    glutStrokeCharacter(GLUT_STROKE_ROMAN, '!');
    glFlush();
    glPopMatrix();
}