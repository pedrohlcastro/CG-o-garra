#include <GL/glew.h>
#include <GL/freeglut.h>
#ifdef WIN32
    #include <SOIL.h>
#else
    #include <SOIL/SOIL.h>
#endif
#include <bits/stdc++.h>
#include "skybox.h"
#include "estruturas_basicas.h"

using namespace std;

enum intTextura{FUNDO=0,LADO1,LADO2,CHAO,TETO};
GLint intSkybox[5];

void setupTexturasSkybox(){
    intSkybox[FUNDO] = SOIL_load_OGL_texture(
        #ifdef WIN32
            "img/centro.png",
        #else
            "../img/centro.png",
        #endif
        SOIL_LOAD_AUTO,
        SOIL_CREATE_NEW_ID,
        SOIL_FLAG_INVERT_Y
    );
    if (intSkybox[FUNDO] == 0 ) {

        printf("Erro carregando textura: '%s'\n", SOIL_last_result());
    }

    intSkybox[LADO1] = SOIL_load_OGL_texture(
        #ifdef WIN32
            "img/lado1.png",
        #else
            "../img/lado1.png",
        #endif
        SOIL_LOAD_AUTO,
        SOIL_CREATE_NEW_ID,
        SOIL_FLAG_INVERT_Y
    );
    if (intSkybox[LADO1] == 0 ) {
        printf("Erro carregando textura: '%s'\n", SOIL_last_result());
    }

    intSkybox[LADO2] = SOIL_load_OGL_texture(
        #ifdef WIN32
            "img/lado2.png",
        #else
            "../img/lado2.png",
        #endif
        SOIL_LOAD_AUTO,
        SOIL_CREATE_NEW_ID,
        SOIL_FLAG_INVERT_Y
    );
    if (intSkybox[LADO2] == 0 ) {
        printf("Erro carregando textura: '%s'\n", SOIL_last_result());
    }

    intSkybox[CHAO] = SOIL_load_OGL_texture(
        #ifdef WIN32
            "img/chao.jpg",
        #else
            "../img/chao.jpg",
        #endif
        SOIL_LOAD_AUTO,
        SOIL_CREATE_NEW_ID,
        SOIL_FLAG_INVERT_Y
    );
    if (intSkybox[CHAO] == 0 ) {
        printf("Erro carregando textura: '%s'\n", SOIL_last_result());
    }
    intSkybox[TETO] = SOIL_load_OGL_texture(
        #ifdef WIN32
            "img/teto.jpg",
        #else
            "../img/teto.jpg",
        #endif
        SOIL_LOAD_AUTO,
        SOIL_CREATE_NEW_ID,
        SOIL_FLAG_INVERT_Y
    );
    if (intSkybox[TETO] == 0 ) {
        printf("Erro carregando textura: '%s'\n", SOIL_last_result());
    }
}

void desenhaSkybox(float fltSize){
    bool blnTextureEnabled = glIsEnabled(GL_TEXTURE_2D);
    glDisable(GL_LIGHTING);
    glDisable(GL_DEPTH_TEST);
    glEnable(GL_TEXTURE_2D);
    glTexParameteri(GL_TEXTURE_2D,GL_TEXTURE_WRAP_S,GL_CLAMP);
    glTexParameteri(GL_TEXTURE_2D,GL_TEXTURE_WRAP_T,GL_CLAMP);
    glPushMatrix();
        glBindTexture(GL_TEXTURE_2D,intSkybox[FUNDO]);
        glBegin(GL_QUADS);
            //back face
            glTexCoord2f(0,0);      
            glVertex3f(fltSize/2,fltSize/2,fltSize/2);       
            glTexCoord2f(1,0);    
            glVertex3f(-fltSize/2,fltSize/2,fltSize/2);
            glTexCoord2f(1,1);
            glVertex3f(-fltSize/2,-fltSize/2,fltSize/2);
            glTexCoord2f(0,1);
            glVertex3f(fltSize/2,-fltSize/2,fltSize/2);
        glEnd();
        glDisable(GL_TEXTURE_2D);

        glEnable(GL_TEXTURE_2D);
        glBindTexture(GL_TEXTURE_2D,intSkybox[LADO1]);
        glBegin(GL_QUADS);
            //left face
            glColor4f(1,1,1,1);
            glTexCoord2f(0,1);
            glVertex3f(-fltSize/2,fltSize/2,fltSize/2);
            glTexCoord2f(1,1);
            glVertex3f(-fltSize/2,fltSize/2,-fltSize/2);
            glTexCoord2f(1,0);
            glVertex3f(-fltSize/2,-fltSize/2,-fltSize/2);
            glTexCoord2f(0,0);
            glVertex3f(-fltSize/2,-fltSize/2,fltSize/2);
        glEnd();
        glDisable(GL_TEXTURE_2D);

        glEnable(GL_TEXTURE_2D);
        glBindTexture(GL_TEXTURE_2D,intSkybox[FUNDO]);
        glBegin(GL_QUADS);
            //front face
            glColor4f(1,1,1,1);
            glTexCoord2f(1,1);
            glVertex3f(fltSize/2,fltSize/2,-fltSize/2);
            glTexCoord2f(0,1);
            glVertex3f(-fltSize/2,fltSize/2,-fltSize/2);
            glTexCoord2f(0,0);
            glVertex3f(-fltSize/2,-fltSize/2,-fltSize/2);
            glTexCoord2f(1,0);
            glVertex3f(fltSize/2,-fltSize/2,-fltSize/2);
        glEnd();
        glDisable(GL_TEXTURE_2D);

        glEnable(GL_TEXTURE_2D);
        glBindTexture(GL_TEXTURE_2D,intSkybox[LADO2]);
        glBegin(GL_QUADS);
            //right face
            glColor4f(1,1,1,1);
            glTexCoord2f(0,1);
            glVertex3f(fltSize/2,fltSize/2,-fltSize/2);
            glTexCoord2f(1,1);
            glVertex3f(fltSize/2,fltSize/2,fltSize/2);
            glTexCoord2f(1,0);
            glVertex3f(fltSize/2,-fltSize/2,fltSize/2);
            glTexCoord2f(0,0);
            glVertex3f(fltSize/2,-fltSize/2,-fltSize/2);
        glEnd();
        glDisable(GL_TEXTURE_2D);

        glEnable(GL_TEXTURE_2D);
        glBindTexture(GL_TEXTURE_2D,intSkybox[TETO]);
        glBegin(GL_QUADS);
            glColor4f(1,1,1,1);
            glTexCoord2f(1,0);
            glVertex3f(fltSize/2,fltSize/2,fltSize/2);
            glTexCoord2f(1,1);
            glVertex3f(-fltSize/2,fltSize/2,fltSize/2);
            glTexCoord2f(0,1);
            glVertex3f(-fltSize/2,fltSize/2,-fltSize/2);
            glTexCoord2f(0,0);
            glVertex3f(fltSize/2,fltSize/2,-fltSize/2);
        glEnd();
        glDisable(GL_TEXTURE_2D);

        glEnable(GL_TEXTURE_2D);
        glBindTexture(GL_TEXTURE_2D,intSkybox[CHAO]);
        glBegin(GL_QUADS);
            //bottom face
            glColor4f(1,1,1,1);
            glTexCoord2f(1,0);
            glVertex3f(fltSize/2,-fltSize/2,fltSize/2);
            glTexCoord2f(1,1);
            glVertex3f(-fltSize/2,-fltSize/2,fltSize/2);
            glTexCoord2f(0,1);
            glVertex3f(-fltSize/2,-fltSize/2,-fltSize/2);
            glTexCoord2f(0,0);
            glVertex3f(fltSize/2,-fltSize/2,-fltSize/2);
        glEnd();
        glDisable(GL_TEXTURE_2D);
    glPopMatrix();

    glEnable(GL_LIGHTING);
    glEnable(GL_DEPTH_TEST);


}
