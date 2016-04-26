#include <GL/glew.h>
#include <GL/freeglut.h>

#ifdef WIN32
    #include <SOIL.h>
#else
    #include <SOIL/SOIL.h>
#endif

#include <bits/stdc++.h>
#include "estruturas_basicas.h"

using namespace std;

int intImgLogo;

void desenhaCuboCustomizado(float fltSize,Cor corObjeto){
    glPushMatrix();
        glBegin(GL_QUADS);
            // front face
            glColor4f(corObjeto.fltR,corObjeto.fltG,corObjeto.fltB,corObjeto.fltAlfa);
            glVertex3f(fltSize/2,fltSize/2,fltSize/2);
            glVertex3f(-fltSize/2,fltSize/2,fltSize/2);
            glVertex3f(-fltSize/2,-fltSize/2,fltSize/2);
            glVertex3f(fltSize/2,-fltSize/2,fltSize/2);
            // left face
            glColor4f(corObjeto.fltR,corObjeto.fltG,corObjeto.fltB,corObjeto.fltAlfa);
            glVertex3f(-fltSize/2,fltSize/2,fltSize/2);
            glVertex3f(-fltSize/2,-fltSize/2,fltSize/2);
            glVertex3f(-fltSize/2,-fltSize/2,-fltSize/2);
            glVertex3f(-fltSize/2,fltSize/2,-fltSize/2);
            // back face
            glColor4f(corObjeto.fltR,corObjeto.fltG,corObjeto.fltB,corObjeto.fltAlfa);
            glVertex3f(fltSize/2,fltSize/2,-fltSize/2);
            glVertex3f(-fltSize/2,fltSize/2,-fltSize/2);
            glVertex3f(-fltSize/2,-fltSize/2,-fltSize/2);
            glVertex3f(fltSize/2,-fltSize/2,-fltSize/2);
            // right face
            glColor4f(corObjeto.fltR,corObjeto.fltG,corObjeto.fltB,corObjeto.fltAlfa);
            glVertex3f(fltSize/2,fltSize/2,fltSize/2);
            glVertex3f(fltSize/2,-fltSize/2,fltSize/2);
            glVertex3f(fltSize/2,-fltSize/2,-fltSize/2);
            glVertex3f(fltSize/2,fltSize/2,-fltSize/2);
            // top face
            glColor4f(corObjeto.fltR,corObjeto.fltG,corObjeto.fltB,corObjeto.fltAlfa);
            glVertex3f(fltSize/2,fltSize/2,fltSize/2);
            glVertex3f(-fltSize/2,fltSize/2,fltSize/2);
            glVertex3f(-fltSize/2,fltSize/2,-fltSize/2);
            glVertex3f(fltSize/2,fltSize/2,-fltSize/2);
            // bottom face
            glColor4f(corObjeto.fltR,corObjeto.fltG,corObjeto.fltB,corObjeto.fltAlfa);
            glVertex3f(fltSize/2,-fltSize/2,fltSize/2);
            glVertex3f(-fltSize/2,-fltSize/2,fltSize/2);
            glVertex3f(-fltSize/2,-fltSize/2,-fltSize/2);
            glVertex3f(fltSize/2,-fltSize/2,-fltSize/2);
        glEnd();
    glPopMatrix();
}

void setupLogoDesenhoMaquina(){
    intImgLogo= SOIL_load_OGL_texture(
        #ifdef WIN32
            "img/LOGO.png",
        #else
            "../img/LOGO.png",
        #endif
        SOIL_LOAD_AUTO,
        SOIL_CREATE_NEW_ID,
        SOIL_FLAG_INVERT_Y
    );
    if (intImgLogo == 0 ) {
        printf("Erro carregando textura: '%s'\n", SOIL_last_result());
    }
}

void desenhaMaquina(float fltSize,Cor corObjeto){
    //base da maquina
    glPushMatrix();
        glTranslated(0,-5,0);
        desenhaCuboCustomizado(5,corObjeto);
    glPopMatrix();

    //topo maquina
    glDisable(GL_LIGHTING);
    //logo na parte da frente...
    glPushMatrix();
        glTranslated(0,5,0);
        glEnable(GL_TEXTURE_2D);
        glBindTexture(GL_TEXTURE_2D,intImgLogo);
        glBegin(GL_QUADS);
            // front face
            glColor4f(1,1,1,1);
            glTexCoord2f(1,1);      
            glVertex3f(fltSize/2,fltSize/2,fltSize/2);       
            glTexCoord2f(0,1);    
            glVertex3f(-fltSize/2,fltSize/2,fltSize/2);
            glTexCoord2f(0,0);
            glVertex3f(-fltSize/2,-fltSize/2,fltSize/2);
            glTexCoord2f(1,0);
            glVertex3f(fltSize/2,-fltSize/2,fltSize/2);
        glEnd();

        glEnable(GL_TEXTURE_2D);
        glBindTexture(GL_TEXTURE_2D,intImgLogo);
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

        glEnable(GL_TEXTURE_2D);
        glBindTexture(GL_TEXTURE_2D,intImgLogo);
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
    glPopMatrix();
    glDisable(GL_TEXTURE_2D);
    glEnable(GL_LIGHTING);

    //laterais laranjas do topo da maquina
    glPushMatrix();
        glTranslated(0,5,0);
        glBegin(GL_QUADS);
                // back face
                glColor4f(corObjeto.fltR,corObjeto.fltG,corObjeto.fltB,corObjeto.fltAlfa);
                glVertex3f(fltSize/2,fltSize/2,-fltSize/2);
                glVertex3f(-fltSize/2,fltSize/2,-fltSize/2);
                glVertex3f(-fltSize/2,-fltSize/2,-fltSize/2);
                glVertex3f(fltSize/2,-fltSize/2,-fltSize/2);
                // top face
                glColor4f(corObjeto.fltR,corObjeto.fltG,corObjeto.fltB,corObjeto.fltAlfa);
                glVertex3f(fltSize/2,fltSize/2,fltSize/2);
                glVertex3f(-fltSize/2,fltSize/2,fltSize/2);
                glVertex3f(-fltSize/2,fltSize/2,-fltSize/2);
                glVertex3f(fltSize/2,fltSize/2,-fltSize/2);
                // bottom face
                glColor4f(corObjeto.fltR,corObjeto.fltG,corObjeto.fltB,corObjeto.fltAlfa);
                glVertex3f(fltSize/2,-fltSize/2,fltSize/2);
                glVertex3f(-fltSize/2,-fltSize/2,fltSize/2);
                glVertex3f(-fltSize/2,-fltSize/2,-fltSize/2);
                glVertex3f(fltSize/2,-fltSize/2,-fltSize/2);
        glEnd();
    glPopMatrix();
    glEnable(GL_LIGHTING);
}