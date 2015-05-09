void square(GLfloat x,GLfloat y, GLfloat z, GLfloat width, GLfloat height)
{
    glColor3f(0,1,1);
    glBegin(GL_POLYGON);
    glVertex3f(x, y, z);
    glVertex3f(x+width/3, y, z);
    glVertex3f(x+width/3,y+ height/3.5, z);
    glVertex3f(x,y+height/3.5,z);
    glEnd();
    glColor3f(1,1,1);
}
void square1(GLfloat x,GLfloat y, GLfloat z, GLfloat width, GLfloat height)
{
    glColor3f(0,1,1);
    glBegin(GL_POLYGON);
    glVertex3f(x, y, z);
    glVertex3f(x+width/3, y, z);
    glVertex3f(x+width/3,y+ height/3.5, z);
    glVertex3f(x,y+height/3.5,z);
    glEnd();
    glColor3f(0,0,1);
    glBegin(GL_POLYGON);
    glVertex3f(x, y+height/1.08, z);
    glVertex3f(x+width/3, y+height/1.08, z);
    glVertex3f(x+width/3,y+height/1.5, z);
    glVertex3f(x,y+height/1.5,z);
    glEnd();
    glColor3f(1,1,1);
}

void square2(GLfloat x,GLfloat y, GLfloat z, GLfloat width, GLfloat height)
{
    glColor3f(0,1,1);
    glBegin(GL_POLYGON);
    glVertex3f(x, y, z);
    glVertex3f(x+width/3, y, z);
    glVertex3f(x+width/3,y+ height/3.5, z);
    glVertex3f(x,y+height/3.5,z);
    glEnd();
    glColor3f(0,0,1);
    glBegin(GL_POLYGON);
    glVertex3f(x, y+height/1.3, z);
    glVertex3f(x+width/3, y+height/1.3, z);
    glVertex3f(x+width/3,y+height/1.9, z);
    glVertex3f(x,y+height/1.9,z);
    glEnd();
    glColor3f(1,1,1);
}
void square3(GLfloat x,GLfloat y, GLfloat z, GLfloat width, GLfloat height)
{
    glColor3f(0,1,1);
    glBegin(GL_POLYGON);
    glVertex3f(x, y, z);
    glVertex3f(x+width/3, y, z);
    glVertex3f(x+width/3,y+ height/3.5, z);
    glVertex3f(x,y+height/3.5,z);
    glEnd();
    glColor3f(0,0,1);
    glBegin(GL_POLYGON);
    glVertex3f(x, y+height/3.5, z);
    glVertex3f(x+width/3, y+height/3.5, z);
    glVertex3f(x+width/3,y+height/1.9, z);
    glVertex3f(x,y+height/1.9,z);
    glEnd();
    glColor3f(1,1,1);
}
void square4(GLfloat x,GLfloat y, GLfloat z, GLfloat width, GLfloat height)
{
    glColor3f(0,1,1);
    glBegin(GL_POLYGON);
    glVertex3f(x, y, z);
    glVertex3f(x+width/3, y, z);
    glVertex3f(x+width/3,y+ height/3.5, z);
    glVertex3f(x,y+height/3.5,z);
    glEnd();
    glColor3f(0,0,1);
    glBegin(GL_POLYGON);
    glVertex3f(x, y+height/3.5, z);
    glVertex3f(x+width/3, y+height/3.5, z);
    glVertex3f(x+width/3,y+height/1.9, z);
    glVertex3f(x,y+height/1.9,z);
    glEnd();
    glColor3f(1,1,1);
    glColor3f(0,1,0);
    glBegin(GL_POLYGON);
    glVertex3f(x+width/3, y, z);
    glVertex3f(x+width/1.6, y, z);
    glVertex3f(x+width/1.6,y+ height/3.5, z);
    glVertex3f(x+width/3,y+height/3.5,z);
    glEnd();
    glColor3f(1,0,1);
    glBegin(GL_POLYGON);
    glVertex3f(x+width/3, y+height/1.08, z);
    glVertex3f(x+width/1.6, y+height/1.08, z);
    glVertex3f(x+width/1.6,y+height/1.5, z);
    glVertex3f(x+width/3,y+height/1.5,z);
    glEnd();
    glColor3f(1,1,1);
}
void square5(GLfloat x,GLfloat y, GLfloat z, GLfloat width, GLfloat height)
{
    glColor3f(0,1,1);
    glBegin(GL_POLYGON);
    glVertex3f(x, y, z);
    glVertex3f(x+width/3, y, z);
    glVertex3f(x+width/3,y+ height/3.5, z);
    glVertex3f(x,y+height/3.5,z);
    glEnd();
    glColor3f(0,0,1);
    glBegin(GL_POLYGON);
    glVertex3f(x, y+height/3.5, z);
    glVertex3f(x+width/3, y+height/3.5, z);
    glVertex3f(x+width/3,y+height/1.9, z);
    glVertex3f(x,y+height/1.9,z);
    glEnd();
    glColor3f(1,1,1);
    glColor3f(0,1,0);
    glBegin(GL_POLYGON);
    glVertex3f(x+width/3, y, z);
    glVertex3f(x+width/1.6, y, z);
    glVertex3f(x+width/1.6,y+ height/3.5, z);
    glVertex3f(x+width/3,y+height/3.5,z);
    glEnd();
    glColor3f(1,0,1);
    glBegin(GL_POLYGON);
    glVertex3f(x+width/3, y+height/1.3, z);
    glVertex3f(x+width/1.6, y+height/1.3, z);
    glVertex3f(x+width/1.6,y+height/1.9, z);
    glVertex3f(x+width/3,y+height/1.9,z);
    glEnd();
    glColor3f(1,1,1);
}
void square6(GLfloat x,GLfloat y, GLfloat z, GLfloat width, GLfloat height)
{
    glColor3f(0,1,1);
    glBegin(GL_POLYGON);
    glVertex3f(x, y, z);
    glVertex3f(x+width/3, y, z);
    glVertex3f(x+width/3,y+ height/3.5, z);
    glVertex3f(x,y+height/3.5,z);
    glEnd();
    glColor3f(0,0,1);
    glBegin(GL_POLYGON);
    glVertex3f(x, y+height/3.5, z);
    glVertex3f(x+width/3, y+height/3.5, z);
    glVertex3f(x+width/3,y+height/1.9, z);
    glVertex3f(x,y+height/1.9,z);
    glEnd();
    glColor3f(1,1,1);
    glColor3f(0,1,0);
    glBegin(GL_POLYGON);
    glVertex3f(x+width/3, y, z);
    glVertex3f(x+width/1.6, y, z);
    glVertex3f(x+width/1.6,y+ height/3.5, z);
    glVertex3f(x+width/3,y+height/3.5,z);
    glEnd();
    glColor3f(1,0,1);
    glBegin(GL_POLYGON);
    glVertex3f(x+width/3, y+height/3.5, z);
    glVertex3f(x+width/1.6, y+height/3.5, z);
    glVertex3f(x+width/1.6,y+height/1.9, z);
    glVertex3f(x+width/3,y+height/1.9,z);
    glEnd();
    glColor3f(1,1,1);
}
 void square7(GLfloat x,GLfloat y, GLfloat z, GLfloat width, GLfloat height)
{
    glColor3f(0,1,1);
    glBegin(GL_POLYGON);
    glVertex3f(x, y, z);
    glVertex3f(x+width/3, y, z);
    glVertex3f(x+width/3,y+ height/3.5, z);
    glVertex3f(x,y+height/3.5,z);
    glEnd();
    glColor3f(1,1,1); 
    glColor3f(0,1,0);
    glBegin(GL_POLYGON);
    glVertex3f(x+width/3, y, z);
    glVertex3f(x+width/1.6, y, z);
    glVertex3f(x+width/1.6,y+ height/3.5, z);
    glVertex3f(x+width/3,y+height/3.5,z);
    glEnd();
}

  void square8(GLfloat x,GLfloat y, GLfloat z, GLfloat width, GLfloat height)
{
    glColor3f(0,1,1);
    glBegin(GL_POLYGON);
    glVertex3f(x, y, z);
    glVertex3f(x+width/3, y, z);
    glVertex3f(x+width/3,y+ height/3.5, z);
    glVertex3f(x,y+height/3.5,z);
    glEnd();
    glColor3f(1,1,1); 
    glColor3f(0,1,0);
    glBegin(GL_POLYGON);
    glVertex3f(x+width/3, y, z);
    glVertex3f(x+width/1.6, y, z);
    glVertex3f(x+width/1.6,y+ height/3.5, z);
    glVertex3f(x+width/3,y+height/3.5,z);
    glEnd();
    glColor3f(1,1,0);
    glBegin(GL_POLYGON);
    glVertex3f(x+width/1.6, y+height/1.08, z);
    glVertex3f(x+width/1.2, y+height/1.08, z);
    glVertex3f(x+width/1.2,y+height/1.6, z);
    glVertex3f(x+width/1.6,y+height/1.6,z);
    glEnd();
    glColor3f(1,1,1);
}

void square9(GLfloat x,GLfloat y, GLfloat z, GLfloat width, GLfloat height)
{
    glColor3f(0,1,1);
    glBegin(GL_POLYGON);
    glVertex3f(x, y, z);
    glVertex3f(x+width/3, y, z);
    glVertex3f(x+width/3,y+ height/3.5, z);
    glVertex3f(x,y+height/3.5,z);
    glEnd();
    glColor3f(1,1,1); 
    glColor3f(0,1,0);
    glBegin(GL_POLYGON);
    glVertex3f(x+width/3, y, z);
    glVertex3f(x+width/1.6, y, z);
    glVertex3f(x+width/1.6,y+ height/3.5, z);
    glVertex3f(x+width/3,y+height/3.5,z);
    glEnd();
    glColor3f(1,1,0);
    glBegin(GL_POLYGON);
    glVertex3f(x+width/1.6, y+height/1.8, z);
    glVertex3f(x+width/1.2, y+height/1.8, z);
    glVertex3f(x+width/1.2,y+height/3.5, z);
    glVertex3f(x+width/1.6,y+height/3.5,z);
    glEnd();
    glColor3f(1,1,1);
}

void square10(GLfloat x,GLfloat y, GLfloat z, GLfloat width, GLfloat height)
{
    glColor3f(0,1,1);
    glBegin(GL_POLYGON);
    glVertex3f(x, y, z);
    glVertex3f(x+width/3, y, z);
    glVertex3f(x+width/3,y+ height/3.5, z);
    glVertex3f(x,y+height/3.5,z);
    glEnd();
    glColor3f(1,1,1); 
    glColor3f(0,1,0);
    glBegin(GL_POLYGON);
    glVertex3f(x+width/3, y, z);
    glVertex3f(x+width/1.6, y, z);
    glVertex3f(x+width/1.6,y+ height/3.5, z);
    glVertex3f(x+width/3,y+height/3.5,z);
    glEnd();
    glColor3f(1,1,0);
    glBegin(GL_POLYGON);
    glVertex3f(x+width/1.6, y, z);
    glVertex3f(x+width/1.2, y, z);
    glVertex3f(x+width/1.2,y+height/3.5, z);
    glVertex3f(x+width/1.6,y+height/3.5,z);
    glEnd(); 
    glColor3f(1,1,1); 
}