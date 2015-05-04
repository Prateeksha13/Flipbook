void square(GLfloat x,GLfloat y, GLfloat z, GLfloat width, GLfloat height)
{
    glColor3f(0,1,1);
    glBegin(GL_POLYGON);
    glVertex3f(x+width/10, y, z);
    glVertex3f(x+width/2, y, z);
    glVertex3f(x+width/2, height/2, z);
    glVertex3f(x+width/10,height/2,z);
    glEnd();
    glColor3f(1,1,1);
}
void triangle(GLfloat x,GLfloat y, GLfloat z, GLfloat width, GLfloat height)
{
    glColor3f(1,0,1);
    glBegin(GL_TRIANGLES);
    glVertex3f(x+width/8, y, z);
    glVertex3f(x+width/2, y, z);
    glVertex3f(x+width/2, height/2, z);
    glVertex3f(x+width/8,height/2,z);
    glEnd();
}