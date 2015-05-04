GLuint texid;
int image;

int LoadImage(char *filename)
{
    ILboolean success; 
    ILuint image; 
    if (ilGetInteger(IL_VERSION_NUM) < IL_VERSION)
    {
           printf("wrong DevIL version \n");
           exit(-1);
    }
    /* Initialization of DevIL */
    ilInit(); 
    ilGenImages(1, &image); /* Generation of one image name */
    ilBindImage(image); /* Binding of image name */
    success = ilLoadImage(filename); /* Loading of the image filename by DevIL */
    if (success) /* If no error occured: */
    {
        /* Convert every colour component into unsigned byte. If your image contains alpha channel you can replace IL_RGB with IL_RGBA */
        success = ilConvertImage(IL_RGBA, IL_UNSIGNED_BYTE); 
        if (!success)
           {
                printf("Can't load picture file %s by DevIL \n", filename);
                exit(-1);
           }
    }
    else
    {
        printf("Can't load picture file %s by DevIL \n", filename);
        exit(-1);
    }
    return image;
}

void loadTextures(GLuint texid)
{
    /* OpenGL 2D generic init */
    //glEnable(GL_TEXTURE_2D);
    /* OpenGL texture binding of the image loaded by DevIL  */
    glGenTextures(1, &texid); /* Texture name generation */
    /*glBindTexture(GL_TEXTURE_2D, texid); /* Binding of texture name */
    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_LINEAR); /* We will use linear interpolation for magnification filter */
    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_LINEAR); /* We will use linear interpolation for minifying filter */
    glTexImage2D(
        GL_TEXTURE_2D, 0,
        ilGetInteger(IL_IMAGE_BPP),
        ilGetInteger(IL_IMAGE_WIDTH),
        ilGetInteger(IL_IMAGE_HEIGHT), 
        0,
        ilGetInteger(IL_IMAGE_FORMAT),
        GL_UNSIGNED_BYTE,
        ilGetData()
    ); /* Texture specification */
}