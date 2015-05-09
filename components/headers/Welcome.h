#ifndef _OPENGL_H
#define _OPENGL_H
#include <GL/glut.h>
#endif

#ifndef _CONSTANTS_H
#define _CONSTANTS_H
#include "../../config/Constants.h"
#endif

#ifndef _WELCOME_SCREEN_H
#define _WELCOME_SCREEN_H
#include <string.h>
void renderText(char*);
void showHeading();
void showFooter();
void showCredits();
void runWelcomeScreen();
#endif