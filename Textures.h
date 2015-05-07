#include <SOIL/SOIL.h>
static GLuint loadTextures(char* filename)
{
    GLuint texture = SOIL_load_OGL_texture(
                filename,
                SOIL_LOAD_AUTO,
                SOIL_CREATE_NEW_ID,
                SOIL_FLAG_POWER_OF_TWO
                | SOIL_FLAG_MIPMAPS
                | SOIL_FLAG_MULTIPLY_ALPHA
                | SOIL_FLAG_COMPRESS_TO_DXT
                | SOIL_FLAG_DDS_LOAD_DIRECT
                | SOIL_FLAG_INVERT_Y
                );

    if (texture == 0)
         cout<<"Texture Load Error: " + string(filename);

        glEnable(GL_TEXTURE_2D);
        glBindTexture (GL_TEXTURE_2D, texture);
    glTexParameterf(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_LINEAR);
    glTexParameterf(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_LINEAR);
    return texture;
}