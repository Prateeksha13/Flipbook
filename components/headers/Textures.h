#ifndef _OPENGL_H
#define _OPENGL_H
#include <GL/glut.h>
#endif

#ifndef _CONSTANTS_H
#define _CONSTANTS_H
#include "../../config/Constants.h"
#endif

#ifndef _TEXTURES_H_
#define _TEXTURES_H_
#include <SOIL/SOIL.h>
#include <iostream>
using namespace std;
GLuint loadTextures(char*);
#endif