#include "main.h"

void setHexColor(int x){
    GLfloat b=(x%0xff)/255.0;
    GLfloat g=((x>>8)%0xff)/255.0;
    GLfloat r=((x>>16)%0xff)/255.0;
    glColor3f(r, g, b); 
}

void selectFlippingPageType()
{
    if(flipId == 0){
        pageFlipLimit=270;
        glRotatef(pageAngle,0.0,-1.0,0.0);
    }
    else if(flipId == 1){
        pageFlipLimit = 320;
        glRotatef(pageAngle,-1.0,-1.0,0.0);
    }
    else if(flipId == 2){
        pageFlipLimit = 350;
        glRotatef(pageAngle,-1.0,-0.0,0.0);
    }
    else if(flipId == 3){
        pageFlipLimit=340;
        glRotatef(pageAngle,-1.0,0.0,-1.0);
    }
}

void selectViewingAngle()
{
    if(viewId == 0){
        gluLookAt(0,0,1900,0,0,0,0,50,0);
    }
    else if(viewId == 1){
        gluLookAt(0,700,2500,0,0,0,0,10,0);
    }
    else if(viewId == 2){
        gluLookAt(0,-700,2500,20,0,-50,0,50,0);
    }
    else if(viewId == 3){
        viewAngleLimit = 720;
        gluLookAt(-500,0,3000,0,0,0,0,80,0);
        glRotatef(viewAngle,0.0,-1.0,-1.0);
    }
}
void flipPage(){
    if(startFlipping == 1){
        if(pageAngle<=pageFlipLimit){
            pageAngle += speed;
        }
        else{
            pageAngle-=pageFlipLimit;
            pageId = (pageId + 1)%11;
        }
    }
    if(viewId == 3){
        if(viewAngle<=viewAngleLimit)
            viewAngle += speed;
        else
            viewAngle-=viewAngleLimit;
    }
}

void idleStateExecute()
{
    flipPage();
    glutPostRedisplay();
}

void initReshape(int w, int h)
{
    window_height = h;
    window_width = w;
    glViewport(0, 0, w, h);
    glClearColor(0.0,0.0,0.0,1.0);
    glMatrixMode(GL_PROJECTION);
    glLoadIdentity();
    if(showWelcomeScreen == 1)
    {
        if(w<=h)
            glOrtho(-WINDOW_WIDTH,WINDOW_WIDTH,-WINDOW_HEIGHT*(GLfloat)h/(GLfloat)w,WINDOW_HEIGHT*(GLfloat)h/(GLfloat)w,-MAX_NO_PAGES*BOOK_THICKNESS,MAX_NO_PAGES*BOOK_THICKNESS);
        else
            glOrtho(-WINDOW_WIDTH*(GLfloat)w/(GLfloat)h,WINDOW_WIDTH*(GLfloat)w/(GLfloat)h,-WINDOW_HEIGHT,WINDOW_HEIGHT,-MAX_NO_PAGES*BOOK_THICKNESS,MAX_NO_PAGES*BOOK_THICKNESS);
    }
    else
        gluPerspective(45,(w/h),20,20000);
    glMatrixMode(GL_MODELVIEW);
    //glutPostRedisplay();
}

void display()
{
    char string[]="\n\n  Game Over!";
    glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT );
    glLoadIdentity();
    if(showWelcomeScreen == 1){
        initReshape(window_width, window_height);
        runWelcomeScreen();
    }
    else{
        GLfloat LIGHT_AMBIENT[]={0.5f,0.59f, 0.57f, 0.0f};
        GLfloat LIGHT_DIFFUSE[]={0.73f,0.74f,0.76f,0.22f};
        GLfloat LIGHT_POSITION[]={350.0f, 300.0f, 20.0f, 999.0f};
        GLfloat mat_ambient[]={0.7f,0.7f,0.7f,1.0f};
        GLfloat mat_diffuse[]={0.5f,0.5f,0.5f,1.0f};
        GLfloat mat_specular[]={1.0f,1.0f,1.0f,1.0f};
        GLfloat mat_shininess[]={50.0f};

        initReshape(window_width, window_height);
        glEnable(GL_LIGHTING);
        glEnable(GL_LIGHT0);
        glEnable(GL_LIGHT1);
        glLightfv(GL_LIGHT1, GL_AMBIENT, LIGHT_AMBIENT);
        glLightfv(GL_LIGHT1, GL_DIFFUSE, LIGHT_DIFFUSE);
        glLightfv(GL_LIGHT1, GL_POSITION, LIGHT_POSITION);
        selectViewingAngle();
        drawRoom();
        glPushMatrix();
            glTranslatef(-100,-100,0);
            Book flipbook(0, 0, 0);
            glMaterialfv(GL_FRONT,GL_AMBIENT,mat_ambient);
            glMaterialfv(GL_FRONT,GL_DIFFUSE,mat_diffuse);
            glMaterialfv(GL_FRONT,GL_SPECULAR,mat_specular);
            glMaterialfv(GL_FRONT,GL_SHININESS,mat_shininess);
            flipbook.addPage(PAGE_TYPE_DRAWING,square);   
            flipbook.addPage(PAGE_TYPE_DRAWING,square1);
            flipbook.addPage(PAGE_TYPE_DRAWING,square2);   
            flipbook.addPage(PAGE_TYPE_DRAWING,square3);   
            flipbook.addPage(PAGE_TYPE_DRAWING,square4);
            flipbook.addPage(PAGE_TYPE_DRAWING,square5); 
            flipbook.addPage(PAGE_TYPE_DRAWING,square6);
            flipbook.addPage(PAGE_TYPE_DRAWING,square7);   
            flipbook.addPage(PAGE_TYPE_DRAWING,square8);
            flipbook.addPage(PAGE_TYPE_TEXT,string);
            glColor3f(0,0,0);
            if(startFlipping == 0){
                glTranslatef(-80, -140, -100);
                glRotatef(-90, 1, 0, 0);
            }
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
        glDisable(GL_LIGHTING);
        glDisable(GL_LIGHT0);
        glDisable(GL_LIGHT1);
        glDisable(GL_LIGHT2);
    }
    glFlush();
    glutSwapBuffers();
}

void mykeyboard(unsigned char key, GLint x,GLint y)
{
    glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT );
    if(key == 'n' || key == 'N')
        pageId = ( pageId + 1 ) % 11;
    else if(key == 'p' || key == 'P')
        pageId = ( pageId - 1 ) % 11;
    else if(key == 13){
        showWelcomeScreen = 0;
        startFlipping = 0;
        pageAngle = 0;
    }
    else if(key == 61)
        speed += 1;
    else if(key == 45)
        speed -= 1;
    glutPostRedisplay();
}
void mymenu(int id)
{
    glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT );
    if(id == 1)
        pageId = ( pageId + 1 ) % 11;
    else if(id == 2)
        pageId = ( pageId + 1 ) % 11;
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
    else if(id == 11)
        startFlipping=1;
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
    wallTexture = loadTextures(wallImageFilename);
    picTexture = loadTextures(picImageFilename);
    welcomeTexture = loadTextures(welcomeImageFilename);
    tableTexture = loadTextures(tableImageFilename);
    floorTexture = loadTextures(floorImageFilename);
    pic2Texture = loadTextures(pic2ImageFilename);
    wall2Texture = loadTextures(wall2ImageFilename);
    menuid=glutCreateMenu(mymenu);
    glutAddMenuEntry("Next Page",1);
    glutAddMenuEntry("Previous Page",2);
    glutAddMenuEntry("Book Flip",3);
    glutAddMenuEntry("Writing Pad Flip",4);
    glutAddMenuEntry("Notebook Flip",5);
    glutAddMenuEntry("Special Flip",6);
    glutAddMenuEntry("Normal View",7);
    glutAddMenuEntry("Top View",8);
    glutAddMenuEntry("Bottom View",9);
    glutAddMenuEntry("Horizontal 360 View",10);
    glutAddMenuEntry("Start Flipping",11);
    //Specifies a symbolic value representing a shading technique. Accepted values are GL_FLAT and GL_SMOOTH.
    glShadeModel(GL_SMOOTH);
    glEnable(GL_DEPTH_TEST);
    glEnable(GL_NORMALIZE);
    glEnable(GL_COLOR_MATERIAL);
    glutAttachMenu(GLUT_RIGHT_BUTTON);
    glutKeyboardFunc(mykeyboard);
    glutIdleFunc(idleStateExecute);
    glEnable(GL_DEPTH_TEST);
    glutMainLoop();
}