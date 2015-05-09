#ifndef _OPENGL_H
#define _OPENGL_H
#include <GL/glut.h>
#endif

#ifndef _CONSTANTS_H
#define _CONSTANTS_H
#include "./config/Constants.h"
#endif

#ifndef _MAIN_H_
#define _MAIN_H_
#include "./components/headers/Drawings.h"
#include "./components/headers/Room.h"
#include "./components/headers/Textures.h"
#include "./components/headers/Welcome.h"
#include "./lib/headers/Book.h"

extern GLuint wallTexture;
extern GLuint ceilingTexture;
extern GLuint floorTexture;
extern GLuint welcomeTexture;
GLfloat angle, limit, speed = PAGE_FLIP_SPEED;
GLint pageId, flipId, viewId;
GLfloat window_width, window_height;
int showWelcomeScreen = 1;
char wallImageFilename[]="../img/wall.jpg";
char welcomeImageFilename[]="../img/welcome.jpg";

void setHexColor(int);
void selectFlippingPageType();
void selectViewingAngle();
void flipPage();
void idleStateExecute();
void initReshape(int, int);
void display();
void mykeyboard(unsigned char, GLint,GLint);
void mymenu(int);
#endif