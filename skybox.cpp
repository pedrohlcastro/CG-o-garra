#include <GL/glew.h>
#include <GL/freeglut.h>
#ifdef LINUX
    #include <SOIL/SOIL.h>
#elif defined WIN32
    #include <SOIL.h>
#endif
#include <bits/stdc++.h>
#include "skybox.h"
#include "estruturas_basicas.h"

/*void setupTexturasSkybox(){
    *imgFundo = SOIL_load_OGL_texture(
        "img/tela_fundo.png",
        SOIL_LOAD_AUTO,
        SOIL_CREATE_NEW_ID,
        SOIL_FLAG_INVERT_Y
    );
}*/

void desenhaSkybox(float fltSize){
    bool blnTextureEnabled = glIsEnabled(GL_TEXTURE_2D);
    glDisable(GL_LIGHTING);
    glDisable(GL_DEPTH_TEST);
    //glEnable(GL_TEXTURE_2D);
    //glBindTexture(GL_TEXTURE_2D,skybox[SKY_BACK]);
    glPushMatrix();
        glBegin(GL_QUADS);
            //back face
            glColor4f(0,0,1,1);
            // glTexCoord2f(0,0);      
            glVertex3f(fltSize/2,fltSize/2,fltSize/2);       
            // glTexCoord2f(1,0);
            glVertex3f(-fltSize/2,fltSize/2,fltSize/2);
            // glTexCoord2f(1,1);
            glVertex3f(-fltSize/2,-fltSize/2,fltSize/2);
            // glTexCoord2f(0,1);
            glVertex3f(fltSize/2,-fltSize/2,fltSize/2);
        glEnd();

        // glBindTexture(GL_TEXTURE_2D,skybox[SKY_LEFT]);
        glBegin(GL_QUADS);
            //left face
            glColor4f(1,0.5,1,1);
            // glTexCoord2f(0,0);
            glVertex3f(-fltSize/2,fltSize/2,fltSize/2);
            // glTexCoord2f(1,0);
            glVertex3f(-fltSize/2,fltSize/2,-fltSize/2);
            // glTexCoord2f(1,1);
            glVertex3f(-fltSize/2,-fltSize/2,-fltSize/2);
            // glTexCoord2f(0,1);
            glVertex3f(-fltSize/2,-fltSize/2,fltSize/2);
        glEnd();

        // glBindTexture(GL_TEXTURE_2D,skybox[SKY_FRONT]);
        glBegin(GL_QUADS);
            //front face
            glColor4f(0.5,0,1,1);
            // glTexCoord2f(1,0);
            glVertex3f(fltSize/2,fltSize/2,-fltSize/2);
            // glTexCoord2f(0,0);
            glVertex3f(-fltSize/2,fltSize/2,-fltSize/2);
            // glTexCoord2f(0,1);
            glVertex3f(-fltSize/2,-fltSize/2,-fltSize/2);
            // glTexCoord2f(1,1);
            glVertex3f(fltSize/2,-fltSize/2,-fltSize/2);
        glEnd();

        // glBindTexture(GL_TEXTURE_2D,skybox[SKY_RIGHT]);
        glBegin(GL_QUADS);
            //right face
            glColor4f(0,0.5,1,1);
            // glTexCoord2f(0,0);
            glVertex3f(fltSize/2,fltSize/2,-fltSize/2);
            // glTexCoord2f(1,0);
            glVertex3f(fltSize/2,fltSize/2,fltSize/2);
            // glTexCoord2f(1,1);
            glVertex3f(fltSize/2,-fltSize/2,fltSize/2);
            // glTexCoord2f(0,1);
            glVertex3f(fltSize/2,-fltSize/2,-fltSize/2);
        glEnd();

        // glBindTexture(GL_TEXTURE_2D,skybox[SKY_TOP]);
        glBegin(GL_QUADS);                      //top face
            glColor4f(0,1,1,1);
            // glTexCoord2f(1,0);
            glVertex3f(fltSize/2,fltSize/2,fltSize/2);
            // glTexCoord2f(0,0);
            glVertex3f(-fltSize/2,fltSize/2,fltSize/2);
            // glTexCoord2f(0,1);
            glVertex3f(-fltSize/2,fltSize/2,-fltSize/2);
            // glTexCoord2f(1,1);
            glVertex3f(fltSize/2,fltSize/2,-fltSize/2);
        glEnd();

        // glBindTexture(GL_TEXTURE_2D,skybox[SKY_BOTTOM]);
        glBegin(GL_QUADS);
            //bottom face
            glColor4f(1,0,1,1);
            // glTexCoord2f(1,1);
            glVertex3f(fltSize/2,-fltSize/2,fltSize/2);
            // glTexCoord2f(0,1);
            glVertex3f(-fltSize/2,-fltSize/2,fltSize/2);
            // glTexCoord2f(0,0);
            glVertex3f(-fltSize/2,-fltSize/2,-fltSize/2);
            // glTexCoord2f(1,0);
            glVertex3f(fltSize/2,-fltSize/2,-fltSize/2);
        glEnd();
    glPopMatrix();

    glEnable(GL_LIGHTING);
    glEnable(GL_DEPTH_TEST);

    if(!blnTextureEnabled)
        glDisable(GL_TEXTURE_2D);
}
