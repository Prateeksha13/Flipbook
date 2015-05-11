/*!
    /file Room.cpp
    /brief Construction of Room, furniture and their walls.
*/

#include "./headers/Room.h"
#include <stdio.h>
GLuint wallTexture;
GLuint ceilingTexture;
GLuint floorTexture;
GLuint picTexture;
GLuint tableTexture;
GLuint pic2Texture;
GLuint wall2Texture;
extern GLuint welcomeTexture;
static void setHexColor(int);
void makeTable();

/*!
    \fn drawRoom()
    \brief Construct the room, walls with a table
    Constructs the Room with the table with texture mapping for the walls.
    Flooring and ceiling set with the furniture texture.
*/
void drawRoom(){
    /*! Left wall being constructed */
    glEnable(GL_TEXTURE_2D);
    glTexEnvf(GL_TEXTURE_ENV, GL_TEXTURE_ENV_MODE, GL_MODULATE);
    glBindTexture(GL_TEXTURE_2D, wall2Texture);
    glColor3f(1,1,1);
    glBegin(GL_QUADS);
        glTexCoord2f(0, 0); glVertex3f(-900, -800, 0);
        glNormal3f(-900, -800, 0);
        glTexCoord2f(0, 1); glVertex3f(-900, 800, 0);
        glNormal3f(-900, 800, 0);
        glTexCoord2f(1, 1); glVertex3f(-500, 500, -500);
        glNormal3f(-500, 500, -500);
        glTexCoord2f(1, 0); glVertex3f(-500, -500, -500);
        glNormal3f(-500, -500, -500);
    glEnd();
    /*! Right wall being constructed */
    glBegin(GL_QUADS);
        glTexCoord2f(1, 1); glVertex3f(900, 800, 0);
        glNormal3f(900, 800, 0);
        glTexCoord2f(1, 0); glVertex3f(900, -800, 0);
        glNormal3f(900, -800, 0);
        glTexCoord2f(0, 0); glVertex3f(500, -500, -500);
        glNormal3f(500, -500, -500);
        glTexCoord2f(0, 1); glVertex3f(500, 500, -500);
        glNormal3f(500, 500, -500);
    glEnd();
    glDisable(GL_TEXTURE_2D);
    /*! Center wall being constructed */
    glEnable(GL_TEXTURE_2D);
    glTexEnvf(GL_TEXTURE_ENV, GL_TEXTURE_ENV_MODE, GL_MODULATE);
    glBindTexture(GL_TEXTURE_2D, wall2Texture);
    glColor3f(1,1,1);
    glBegin(GL_QUADS);
        glTexCoord2f(0, 0); glVertex3f(-500, -500, -500);
        glNormal3f(-500, -500, -500);
        glTexCoord2f(0, 1); glVertex3f(-500, 500, -500);
        glNormal3f(-500, 500, -500);
        glTexCoord2f(1, 1); glVertex3f(500, 500, -500);
        glNormal3f(500, 500, -500);
        glTexCoord2f(1, 0); glVertex3f(500, -500, -500);
        glNormal3f(500, -500, -500);
    glEnd();
    glDisable(GL_TEXTURE_2D);
    /*! Floor being constructed */
    glEnable(GL_TEXTURE_2D);
    glTexEnvf(GL_TEXTURE_ENV, GL_TEXTURE_ENV_MODE, GL_MODULATE);
    glBindTexture(GL_TEXTURE_2D, floorTexture);
    setHexColor(0xE0E0E0);
    glBegin(GL_QUADS);
        glTexCoord2f(0, 0); glVertex3f(-900, -800, 0);
        glNormal3f(-900, -800, 0);
        glTexCoord2f(1, 0); glVertex3f(-500, -500, -500);
        glNormal3f(-500, -500, -500);
        glTexCoord2f(1, 1); glVertex3f(500, -500, -500);
        glNormal3f(500, -500, -500);
        glTexCoord2f(0, 1); glVertex3f(900, -800, 0);
        glNormal3f(900, -800, 0);
    glEnd();
    glDisable(GL_TEXTURE_2D);
    /*! Roof being constructed */
    glEnable(GL_TEXTURE_2D);
    glTexEnvf(GL_TEXTURE_ENV, GL_TEXTURE_ENV_MODE, GL_MODULATE);
    glBindTexture(GL_TEXTURE_2D, wallTexture);
    glColor3f(0.5,0.5,1);
    glBegin(GL_QUADS);
        glTexCoord2f(0, 0); glVertex3f(-900, 800, 0);
        glNormal3f(-900, 800, 0);
        glTexCoord2f(1, 0); glVertex3f(-500, 500, -500);
        glNormal3f(-500, 500, -500);
        glTexCoord2f(1, 1); glVertex3f(500, 500, -500);
        glNormal3f(500, 500, -500);
        glTexCoord2f(0, 1); glVertex3f(900, 800, 0);
        glNormal3f(900, 800, 0);
    glEnd();
    glDisable(GL_TEXTURE_2D);
    glColor3f(1,1,1);
    /*! Left Photoframe with photo being constructed */
    glEnable(GL_TEXTURE_2D);
    glTexEnvf(GL_TEXTURE_ENV, GL_TEXTURE_ENV_MODE, GL_MODULATE);
    glBindTexture(GL_TEXTURE_2D, picTexture);
    glBegin(GL_QUADS);
        glTexCoord2f(0, 0); glVertex3f(-700, 100, 0);
        glNormal3f(-700, 100, 0);
        glTexCoord2f(0, 1); glVertex3f(-700, 400, 0);
        glNormal3f(-700, 400, 0);
        glTexCoord2f(1, 1); glVertex3f(-600, 350, -300);
        glNormal3f(-600, 350, -300);
        glTexCoord2f(1, 0); glVertex3f(-600, 120, -300);
        glNormal3f(-600, 120, -300);
    glEnd();
    glDisable(GL_TEXTURE_2D);
    /*! Right photoframe with photo being constructed */
    glEnable(GL_TEXTURE_2D);
    glTexEnvf(GL_TEXTURE_ENV, GL_TEXTURE_ENV_MODE, GL_MODULATE);
    glBindTexture(GL_TEXTURE_2D, pic2Texture);
    glBegin(GL_QUADS);
        glTexCoord2f(0, 0); glVertex3f(700, 100, 0);
        glNormal3f(700, 100, 0);
        glTexCoord2f(0, 1); glVertex3f(700, 400, 0);
        glNormal3f(700, 400, 0);
        glTexCoord2f(1, 1); glVertex3f(600, 350, -300);
        glNormal3f(600, 350, -300);
        glTexCoord2f(1, 0); glVertex3f(600, 120, -300);
        glNormal3f(600, 120, -300);
    glEnd();
    glDisable(GL_TEXTURE_2D);
    makeTable(); /*!< Table construction */
}

/*!
    \fn makeTable()
    \brief Construct a table
    Constructs the table with the specified texture mapped.
*/
void makeTable(){
    /*! Top view of the table */
    glEnable(GL_TEXTURE_2D);
    glTexEnvf(GL_TEXTURE_ENV, GL_TEXTURE_ENV_MODE, GL_MODULATE);
    glBindTexture(GL_TEXTURE_2D, tableTexture);
    setHexColor(0x9E9E9E);
    glBegin(GL_QUADS);
        glTexCoord2f(0, 0); glVertex3f(-300, -300, -300);
        glNormal3f(-300, -300, -300);
        glTexCoord2f(1, 0); glVertex3f(-400, -280, -500);
        glNormal3f(-400, -280, -500);
        glTexCoord2f(1, 1); glVertex3f(400, -280, -500);
        glNormal3f(400, -280, -500);
        glTexCoord2f(0, 1); glVertex3f(300, -300, -300);
        glNormal3f(300, -300, -300);
    glEnd();
    /*! Front view of the table */
    glBegin(GL_QUADS);
        glTexCoord2f(0, 0); glVertex3f(-300, -300, -300);
        glNormal3f(-300, -300, -300);
        glTexCoord2f(0, 1); glVertex3f(300, -300, -300);
        glNormal3f(300, -300, -300);
        glTexCoord2f(1, 0); glVertex3f(300, -500, -310);
        glNormal3f(300, -500, -310);
        glTexCoord2f(1, 1); glVertex3f(-300, -500, -310);
        glNormal3f(-300, -500, -310);
    glEnd();
    /*! Left view of the table */
    glBegin(GL_QUADS);
        glTexCoord2f(0, 0); glVertex3f(-300, -300, -300);
        glNormal3f(-300, -300, -300);
        glTexCoord2f(0, 1); glVertex3f(-400, -280, -500);
        glNormal3f(-400, -280, -500);
        glTexCoord2f(1, 0); glVertex3f(-300, -500, -500);
        glNormal3f(-300, -500, -500);
        glTexCoord2f(1, 1); glVertex3f(-300, -500, -310);
        glNormal3f(-300, -500, -310);
    glEnd();
    /*! Right view of the table */
    glBegin(GL_QUADS);
        glTexCoord2f(0, 0); glVertex3f(300, -300, -300);
        glNormal3f(300, -300, -300);
        glTexCoord2f(0, 1); glVertex3f(400, -280, -500);
        glNormal3f(400, -280, -500);
        glTexCoord2f(1, 0); glVertex3f(300, -500, -500);
        glNormal3f(300, -500, -500);
        glTexCoord2f(1, 1); glVertex3f(300, -500, -310);
        glNormal3f(300, -500, -310);
    glEnd();
    /*! Bottom view of the table */
    glBegin(GL_QUADS);
        glTexCoord2f(1, 0); glVertex3f(-300, -500, -500);
        glNormal3f(-400, -280, -500);
        glTexCoord2f(1, 1); glVertex3f(300, -500, -500);
        glNormal3f(400, -280, -500);
        glTexCoord2f(1, 0); glVertex3f(300, -500, -310);
        glNormal3f(300, -500, -310);
        glTexCoord2f(1, 1); glVertex3f(-300, -500, -310);
        glNormal3f(-300, -500, -310);
    glEnd();
    glDisable(GL_TEXTURE_2D);
}

/*!
    \fn setHexColor(int x)
    \brief Set hexadecimal color value as rgb color
    setHexColor is used to set color from received hexadecimal, to
    the required rgb format.    
*/
static void setHexColor(int x /*!< Hexadecimal value */){
    GLfloat b=(x%0xff)/255.0;
    GLfloat g=((x>>8)%0xff)/255.0;
    GLfloat r=((x>>16)%0xff)/255.0;
    glColor3f(r, g, b); 
}