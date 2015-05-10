#include "./headers/Welcome.h"

extern GLfloat pageAngle, pageFlipLimit;
extern void setHexColor(int);
GLuint welcomeTexture;

void renderText(char *string){
    int length = strlen(string);
    for(int i=0;i<length;i++)
        glutStrokeCharacter(GLUT_STROKE_ROMAN, string[i]);
}
void showHeading()
{
    char heading[] = "FlipBook";
    glPushMatrix();
    glLoadIdentity();
    glTranslatef(-300,250,0);
    glScalef(1.5,1.5,10);
    glRotatef(pageAngle, 1 , 0 ,0);
    renderText(heading);
    glFlush();
    glPopMatrix();
    glDisable(GL_LIGHT0);
    glDisable(GL_LIGHTING);
}
void showCredits()
{
    char developer[][50] = {"Kshitij Karthick - 1RE12CS042","Srinivas Ananth - 1RE12CS034"};
    GLfloat LIGHT_AMBIENT[] =   // light ambience
        {0.0f,0.999f, 0.57f, 0.0f};
    GLfloat LIGHT_DIFFUSE[] =   // light diffusion
        {0.99f,0.99f,0.99f,0.99f};
    GLfloat LIGHT_POSITION[] =  // light position
        {-322.0f, -300.0f, 350.0f, 999.0f};
    glEnable(GL_LIGHT0);
    glEnable(GL_LIGHTING);
    glLightfv(GL_LIGHT0, GL_AMBIENT, LIGHT_AMBIENT);
    glLightfv(GL_LIGHT0, GL_DIFFUSE, LIGHT_DIFFUSE);
    glLightfv(GL_LIGHT0, GL_POSITION, LIGHT_POSITION);
    glPushMatrix();
    glLoadIdentity();
    glTranslatef(-150,-400,0);
    glScalef(0.5,0.5,1);
    renderText(developer[0]);
    glFlush();
    glPopMatrix();
    glPushMatrix();
    glLoadIdentity();
    glTranslatef(-150,-500,0);
    glScalef(0.5,0.5,1);
    renderText(developer[1]);
    glFlush();
    glPopMatrix();
    glDisable(GL_LIGHT0);
    glDisable(GL_LIGHTING);
}
void showFooter()
{
    char message[]="Press Enter to Continue to the Flipbook";
    glPushMatrix();
    glLoadIdentity();
    glTranslatef(- 2 * WINDOW_WIDTH + pageAngle*4,-650,0);
    glScalef(0.5,0.5,1);
    renderText(message);
    glFlush();
    glPopMatrix();
}
void runWelcomeScreen()
{
    pageFlipLimit = 720;
    glPushMatrix();
    glLoadIdentity();
    glEnable(GL_TEXTURE_2D);
    glTexEnvf(GL_TEXTURE_ENV, GL_TEXTURE_ENV_MODE, GL_MODULATE);
    glBindTexture(GL_TEXTURE_2D, welcomeTexture);
    glColor3f(1,1,1);
    glBegin(GL_QUADS);
        glTexCoord2f(0, 0); glVertex3f(-WINDOW_WIDTH, -WINDOW_HEIGHT, -1000);
        glNormal3f(-WINDOW_WIDTH, -WINDOW_HEIGHT, -1000);
        glTexCoord2f(1, 0); glVertex3f(WINDOW_WIDTH, -WINDOW_HEIGHT, -1000);
        glNormal3f(WINDOW_WIDTH, -WINDOW_HEIGHT, -1000);
        glTexCoord2f(1, 1); glVertex3f(WINDOW_WIDTH, WINDOW_HEIGHT, -1000);
        glNormal3f(WINDOW_WIDTH, WINDOW_HEIGHT, -1000);
        glTexCoord2f(0, 1); glVertex3f(-WINDOW_WIDTH, WINDOW_HEIGHT, -1000);
        glNormal3f(-WINDOW_WIDTH, WINDOW_HEIGHT, -1000);
    glEnd();
    glPopMatrix();
    showHeading();
    showCredits();
    showFooter();
}